//
// Created by Rohini Sharma on 4/30/20.
//

#include "ocr/matrix_utils.h"

#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/objdetect.hpp>
#include <opencv2/photo.hpp>
#include <vector>

using cv::HOGDescriptor;
using cv::Point;
using cv::Size;
using std::vector;
using cv::HOGDescriptor;

namespace ocr {

void ProcessMatrix(Mat& matrix, bool is_character_matrix) {
  cv::cvtColor(matrix, matrix, cv::COLOR_BGR2GRAY);
  cv::fastNlMeansDenoising(matrix, matrix);
  cv::GaussianBlur(matrix, matrix,
                  cv::Size(kSmoothingSize, kSmoothingSize), kSigmaX);
  cv::adaptiveThreshold(matrix, matrix, kThresholdMax,
                        cv::ADAPTIVE_THRESH_GAUSSIAN_C,
                        cv::THRESH_BINARY, kBlockSize,
                        kThresholdConstant);
  //TODO fix magic nums
  if (is_character_matrix) {
    cv::resize(matrix, matrix,
               cv::Size(20,30));
    return;
  }
  Mat sobel_x, sobel_y, magnitude;
  cv::Sobel(matrix, sobel_x, CV_32F, 1,0);
  cv::Sobel(matrix, sobel_y, CV_32F, 0,1);
  cv::magnitude(sobel_x, sobel_y, matrix);
  cv::normalize(matrix, matrix, kNormAlpha, kNormBeta,
      cv::NORM_MINMAX, CV_8U);

  Mat kernel = Mat::ones(kDialationKernelSize,kDialationKernelSize, CV_8U);
  cv::dilate(matrix,matrix,kernel);



}

bool SortContours(const vector<cv::Point>& first, const vector<cv::Point>& second) {
  //TODO put in a better place
  cv::Rect firstr = cv::boundingRect(first);
  cv::Rect secondr = cv::boundingRect(second);
  return firstr.x < secondr.x;
}
}
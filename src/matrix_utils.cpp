//
// Created by Rohini Sharma on 4/30/20.
//

#include "ocr/matrix_utils.h"

#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <vector>

using cv::Mat;
using cv::Point;
using std::vector;

namespace ocr {

void ProcessMatrix(Mat& matrix, bool is_character_matrix) {
  cv::cvtColor(matrix, matrix, cv::COLOR_BGR2GRAY);

  cv::GaussianBlur(matrix, matrix,
                  cv::Size(kSmoothingSize, kSmoothingSize), kSigmaX);
  cv::adaptiveThreshold(matrix, matrix, kThresholdMax,
                        cv::ADAPTIVE_THRESH_GAUSSIAN_C,
                        cv::THRESH_BINARY, kBlockSize,
                        kThresholdConstant);
  Mat sobel_x, sobel_y, magnitude;
  cv::Sobel(matrix, sobel_x, CV_32F, 1,0);
  cv::Sobel(matrix, sobel_y, CV_32F, 0,1);
  cv::magnitude(sobel_x, sobel_y, matrix);
  cv::normalize(matrix, matrix, 0, 255, cv::NORM_MINMAX, CV_8U);

  if (is_character_matrix) {
    cv::resize(matrix, matrix,
               cv::Size(kResizeSideLength, kResizeSideLength));
  }
}
}
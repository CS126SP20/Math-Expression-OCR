//
// Created by Rohini Sharma on 4/30/20.
//

#include "ocr/matrix_utils.h"

#include <ocr/Character.h>

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

void ProcessMatrix(Mat& matrix) {
  cv::cvtColor(matrix, matrix, cv::COLOR_BGR2GRAY);
  cv::fastNlMeansDenoising(matrix, matrix);
  cv::GaussianBlur(matrix, matrix,
                  cv::Size(kSmoothingSize, kSmoothingSize), kSigmaX);
  cv::adaptiveThreshold(matrix, matrix, kThresholdMax,
                        cv::ADAPTIVE_THRESH_GAUSSIAN_C,
                        cv::THRESH_BINARY, kBlockSize,
                        kThresholdConstant);
}

//bool SortContours(const vector<cv::Point>& first, const vector<cv::Point>& second) {
//  //TODO put in a better place
//  cv::Rect firstr = cv::boundingRect(first);
//  cv::Rect secondr = cv::boundingRect(second);
//  return firstr.x < secondr.x;
//}
}
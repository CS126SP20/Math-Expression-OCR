//
// Created by Rohini Sharma on 4/30/20.
//

#include "ocr/matrix_utils.h"
#include <ocr/Character.h>
#include <opencv2/imgproc.hpp>
#include <opencv2/photo.hpp>

using cv::Point;
using cv::Size;
using std::vector;

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
}
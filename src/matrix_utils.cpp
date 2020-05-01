//
// Created by Rohini Sharma on 4/30/20.
//

#include <opencv2/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include "ocr/matrix_utils.h"
#include <vector>

using cv::Mat;
using cv::Point;
using std::vector;

namespace ocr {

void ProcessMatrix(Mat& matrix, bool is_character_matrix) {
  //TODO write tests
  cv::cvtColor(matrix, matrix, cv::COLOR_BGR2GRAY);
  cv::GaussianBlur(matrix, matrix,
                   cv::Size(kSmoothingSize, kSmoothingSize), kSigmaX);
  cv::adaptiveThreshold(matrix, matrix, kThresholdMax,
                        cv::ADAPTIVE_THRESH_GAUSSIAN_C,
                        cv::THRESH_BINARY, kBlockSize,
                        kThresholdConstant);

  if (is_character_matrix) {
    cv::resize(matrix, matrix,
               cv::Size(kResizeSideLength, kResizeSideLength));
  }
}
}
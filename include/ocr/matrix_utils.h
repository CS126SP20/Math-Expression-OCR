//
// Created by Rohini Sharma on 4/30/20.
//

#ifndef FINALPROJECT_MATRIX_UTILS_H
#define FINALPROJECT_MATRIX_UTILS_H

#include <opencv2/core.hpp>
#include <vector>

using cv::Mat;
using std::vector;

namespace ocr {

const size_t kSmoothingSize = 5;
const double kSigmaX = 30;
const double kThresholdMax = 255;
const size_t kBlockSize = 11;
const double kThresholdConstant = 2.0;
const size_t kResizeSideLength = 30;
const size_t kKernelSize = 3;
const double kNormAlpha = 0;
const double kNormBeta = 255;

void ProcessMatrix(Mat& matrix);

}

#endif  // FINALPROJECT_MATRIX_UTILS_H
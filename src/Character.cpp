//
// Created by Rohini Sharma on 4/23/20.
//

#include "ocr/Character.h"

#include <ocr/matrix_utils.h>

#include <filesystem>
#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/photo.hpp>
#include <string>
#include <vector>

using ocr::kDialationKernelSize;
using std::vector;
using std::__fs::filesystem::exists;
using std::invalid_argument;
using ocr::kResizeSideLength;
using ocr::kDialationKernelSize;

namespace ocr {


Character::Character(const string& filepath) {
  if (!exists(filepath)) {
    throw invalid_argument("Could not find character at path: " + filepath);
  }
  character_mat_ = cv::imread(filepath);
  ProcessMatrix(character_mat_, true);
}

Character::Character(const cv::Mat& mat) {
  character_mat_ = mat;
  //TODO fix magic nums
  cv::imshow("char", character_mat_);
  cv::waitKey(0);
  int top = 0;
  int bottom = 0;
  int left = 0;
  int right = 0;
  int border = cv::BORDER_CONSTANT;
  if (character_mat_.rows > character_mat_.cols) {
    left = (int) (0.5 * (character_mat_.rows - character_mat_.cols)); right = left;
  }
  if (character_mat_.cols > character_mat_.rows) {
    top = (int) (0.5 * (character_mat_.cols - character_mat_.rows)); bottom = top;
  }



  cv::Scalar value(255,255,255);
  cv::copyMakeBorder(character_mat_, character_mat_, top, bottom, left, right, border,value);
  Mat kernel = Mat::ones(kDialationKernelSize,kDialationKernelSize, CV_8U);
  cv::erode(character_mat_,character_mat_,kernel);

  cv::imshow("char", character_mat_);
  cv::waitKey(0);
  cv::resize(character_mat_, character_mat_, cv::Size(20, 30));
  cv::imshow("char", character_mat_);
  cv::waitKey(0);

}

cv::Mat Character::GetMatrix() const {
  return character_mat_;
}
}

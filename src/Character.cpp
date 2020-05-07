//
// Created by Rohini Sharma on 4/23/20.
//

#include "ocr/Character.h"
#include <ocr/matrix_utils.h>
#include <ocr/Image.h>
#include <filesystem>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <string>

using ocr::kKernelSize;
using std::vector;
using std::__fs::filesystem::exists;
using std::invalid_argument;
using ocr::kResizeSideLength;

namespace ocr {

Character::Character(const string& filepath) {
  if (!exists(filepath)) {
    throw invalid_argument("Could not find character at path: " + filepath);
  }
  character_mat_ = cv::imread(filepath);
  ProcessMatrix(character_mat_);
  cv::resize(character_mat_, character_mat_,
             cv::Size(kCharacterWidth,kCharacterHeight));
}

Character::Character(const cv::Mat& mat) {
  character_mat_ = mat;
  PadCharacter();
  Mat kernel = Mat::ones(kKernelSize, kKernelSize, CV_8U);
  cv::erode(character_mat_,character_mat_,kernel);
  cv::resize(character_mat_, character_mat_,
      cv::Size(kCharacterWidth, kCharacterHeight));

}

cv::Mat Character::GetFlattenedMatrix() const {
  Mat flattened = character_mat_.reshape(1,1);
  flattened.convertTo(flattened, CV_32F);
  return flattened;
}

void Character::PadCharacter(){
  int top = 0;
  int bottom = 0;
  int right = 0;
  int left = 0;
  int border = cv::BORDER_CONSTANT;
  if (character_mat_.rows > character_mat_.cols) {
    left = (int) (kPadRatio * (character_mat_.rows - character_mat_.cols));
    right = left;
  }
  if (character_mat_.cols > character_mat_.rows) {
    top = (int) (kPadRatio * (character_mat_.cols - character_mat_.rows));
    bottom = top;
  }
  cv::copyMakeBorder(character_mat_, character_mat_, top, bottom,
      left, right, border, kPadValue);
}
}

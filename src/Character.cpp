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
  ProcessMatrix(character_mat_, true);
}

Character::Character(const cv::Mat& mat) {
  character_mat_ = mat;

  Mat kernel = Mat::ones(kKernelSize, kKernelSize, CV_8U);
  cv::erode(character_mat_,character_mat_,kernel);
  cv::resize(character_mat_, character_mat_,
      cv::Size(kCharacterWidth, kCharacterHeight));

}

cv::Mat Character::GetMatrix() const {
  return character_mat_;
}

void Character::PadCharacter(){
  int top, bottom, right, left = 0;
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

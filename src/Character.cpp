//
// Created by Rohini Sharma on 4/23/20.
//

#include "ocr/Character.h"

#include <filesystem>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <ocr/matrix_utils.h>
#include <string>
#include <vector>

using std::string;
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
}

cv::Mat Character::GetMatrix() const {
  return character_mat_;
}
}

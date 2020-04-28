//
// Created by Rohini Sharma on 4/23/20.
//

#include "ocr/Character.h"

#include <filesystem>
#include <iostream>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/ml/ml.hpp>
#include <string>
#include <vector>

using std::string;
using std::vector;
using std::__fs::filesystem::exists;
using std::invalid_argument;
namespace ocr {



Character::Character(const string& filepath) {
  if (!exists(filepath)) {
    throw invalid_argument("Could not find image at path: " + filepath);
  }
  img_mat_ = cv::imread(filepath);
  ProcessMatrix();
  cv::findContours(img_mat_, img_contours_, v4iHierarchy,
      cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE );
}

Character::Character(const cv::Mat& mat) {
  img_mat_ = mat;
  ProcessMatrix();
  cv::findContours(img_mat_, img_contours_, v4iHierarchy,
                   cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE );
}

cv::Mat Character::GetMatrix() const {
  return img_mat_;
}

vector<vector<cv::Point>> Character::GetContours() const {
  return img_contours_;
}

void Character::ProcessMatrix() {
  cv::cvtColor(img_mat_, img_mat_, cv::COLOR_BGR2GRAY);
  cv::GaussianBlur(img_mat_, img_mat_,
      cv::Size(kSmoothingSize, kSmoothingSize), kSigmaX);
  cv::adaptiveThreshold(img_mat_, img_mat_, kThresholdMax,
      cv::ADAPTIVE_THRESH_GAUSSIAN_C,
      cv::THRESH_BINARY, kBlockSize, kThresholdConstant);
}


}

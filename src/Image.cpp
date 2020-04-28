//
// Created by Rohini Sharma on 4/23/20.
//

#include "ocr/Image.h"
#include <filesystem>
#include <iostream>
#include <opencv2/imgcodecs.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include <string>
#include <vector>

using std::string;
using std::vector;
using std::__fs::filesystem::exists;
using std::invalid_argument;
namespace ocr {



Image::Image(const string& filepath) {
  if (!exists(filepath)) {
    throw invalid_argument("Could not find image at path: " + filepath);
  }
  img_mat_ = cv::imread(filepath);
  ProcessMatrix();
}

cv::Mat Image::GetMatrix() const {
  return img_mat_;
}

void Image::ProcessMatrix() {
  cv::cvtColor(img_mat_, img_mat_, cv::COLOR_BGR2GRAY);
  cv::GaussianBlur(img_mat_, img_mat_,
      cv::Size(kSmoothingSize, kSmoothingSize), kSigmaX);
  cv::adaptiveThreshold(img_mat_, img_mat_, kThresholdMax,
      cv::ADAPTIVE_THRESH_GAUSSIAN_C,
      cv::THRESH_BINARY, kBlockSize, kThresholdConstant);

}

}

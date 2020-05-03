//
// Created by Rohini Sharma on 4/30/20.
//

#include "ocr/Image.h"
#include <ocr/matrix_utils.h>
#include <opencv2/core.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<opencv2/highgui/highgui.hpp>
#include <filesystem>

using std::__fs::filesystem::exists;
using std::invalid_argument;
using cv::Point;
using ocr::ProcessMatrix;
using ocr::SortContours;


namespace ocr {

Image::Image(const string& path) {
  if (!exists(path)) {
    throw invalid_argument("Could not find image at path: " + path);
  }
  image_mat_ = cv::imread(path);
  ProcessMatrix(image_mat_, false);
}

vector<Character> Image::GetCharacters() {
  vector<Character> characters_in_img;
  vector<vector<Point>> contours = GetValidContours();
  for (auto& contour : contours) {
    Mat character_mat = GetMatFromContour(contour);
    characters_in_img.push_back(Character(character_mat));
  }
  return characters_in_img;
}


vector<vector<Point>> Image::GetValidContours() const {
  vector<vector<Point>> valid_contours;
  Mat image_mat_copy = image_mat_.clone();
  vector<vector<Point>> all_contours;
  cv::findContours(image_mat_copy, all_contours, cv::RETR_EXTERNAL,
      cv::CHAIN_APPROX_SIMPLE);
  for (auto& contour : all_contours) {
    if (cv::contourArea(contour) > kMinContourArea) {
      valid_contours.push_back(contour);

    }
  }
  cv::drawContours(image_mat_,all_contours,-1, cv::Scalar(0,0,0));
  cv::imshow("drew contours", image_mat_);
  //TODO sort contours left to right if needed
  std::sort(valid_contours.begin(), valid_contours.end(), SortContours);
  return valid_contours;
}

Mat Image::GetMatFromContour(const vector<Point>& contour) const {
  cv::Rect bounds = cv::boundingRect(contour);
  cv::rectangle(image_mat_, bounds, cv::Scalar(100,0,0), 2);
  return image_mat_(bounds).clone();
}


}
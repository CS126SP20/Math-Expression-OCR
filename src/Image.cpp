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

namespace ocr {

Image::Image(const string& path) {
  if (!exists(path)) {
    throw invalid_argument("Could not find image at path: " + path);
  }
  original_mat_= cv::imread(path);
  processed_mat_ = original_mat_.clone();
  ProcessMatrix(processed_mat_);
  ProcessEdges();
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
  Mat image_mat_copy = processed_mat_.clone();
  vector<vector<Point>> all_contours;
  cv::findContours(image_mat_copy, all_contours, cv::RETR_EXTERNAL,
      cv::CHAIN_APPROX_SIMPLE);
  for (const auto& contour : all_contours) {
    if (cv::contourArea(contour) > kMinContourArea) {
      valid_contours.push_back(contour);

    }
  }
  std::sort(valid_contours.begin(), valid_contours.end(), SortContours);
  return valid_contours;
}

Mat Image::GetMatFromContour(const vector<Point>& contour) {
  cv::Rect bounds = cv::boundingRect(contour);
  Mat region_of_interest = original_mat_(bounds).clone();
  cv::cvtColor(region_of_interest, region_of_interest, cv::COLOR_BGR2GRAY);
  return region_of_interest;
}

void Image::ProcessEdges() {
  Mat sobel_x, sobel_y, magnitude;
  cv::Sobel(processed_mat_, sobel_x, CV_32F, 1,0);
  cv::Sobel(processed_mat_, sobel_y, CV_32F, 0,1);
  cv::magnitude(sobel_x, sobel_y, processed_mat_);
  cv::normalize(processed_mat_, processed_mat_, kNormAlpha, kNormBeta,
                cv::NORM_MINMAX, CV_8U);

  Mat kernel = Mat::ones(kKernelSize, kKernelSize, CV_8U);
  cv::dilate(processed_mat_,processed_mat_,kernel);
}

bool Image::SortContours(const vector<cv::Point>& first,
    const vector<cv::Point>& second) {
  cv::Rect firstr = cv::boundingRect(first);
  cv::Rect secondr = cv::boundingRect(second);
  return firstr.x < secondr.x;
}
}
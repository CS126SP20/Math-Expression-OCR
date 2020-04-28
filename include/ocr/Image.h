//
// Created by Rohini Sharma on 4/23/20.
//

#ifndef FINALPROJECT_IMAGE_H
#define FINALPROJECT_IMAGE_H

#include <opencv2/core/mat.hpp>
#include <vector>

using std::vector;
using std::string;
namespace ocr {

const size_t kSmoothingSize = 5;
const double kSigmaX = 0;
const double kThresholdMax = 255;
const size_t kBlockSize = 11;
const double kThresholdConstant = 2.0;

class Image {

 public:
  explicit Image(const string& filepath);
  cv::Mat GetMatrix() const;
  vector<vector<cv::Point>> GetContours() const;
 private:
  cv::Mat img_mat_;
  vector<vector<cv::Point>> img_contours_;
  //TODO what is this
  std::vector<cv::Vec4i> v4iHierarchy;

  void ProcessMatrix();
};

}

#endif  // FINALPROJECT_IMAGE_H

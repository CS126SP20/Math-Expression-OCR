//
// Created by Rohini Sharma on 4/23/20.
//

#ifndef FINALPROJECT_CHARACTER_H
#define FINALPROJECT_CHARACTER_H

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
const size_t kResizeSideLength = 30;

class Character {

 public:
  explicit Character(const string& filepath);
  Character(const cv::Mat& mat);
  cv::Mat GetMatrix() const;
  vector<vector<cv::Point>> GetContours() const;
 private:
  cv::Mat img_mat_;
  vector<vector<cv::Point>> img_contours_;
  //TODO what is this
  std::vector<cv::Vec4i> v4i_hierarchy;

  void ProcessMatrix();
};

struct LabeledCharacter {
  Character character;
  string label;
};
}

#endif  // FINALPROJECT_CHARACTER_H

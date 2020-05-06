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

const cv::Scalar kPadValue = cv::Scalar(255, 255, 255);
const double kPadRatio = 0.5;
const size_t kCharacterWidth = 20;
const size_t kCharacterHeight = 30;

class Character {

 public:
  explicit Character(const string& filepath);
  Character(const cv::Mat& mat);
  cv::Mat GetMatrix() const;
 private:
  cv::Mat character_mat_;

  void PadCharacter();
};

struct LabeledCharacter {
  Character character;
  string label;
};
}

#endif  // FINALPROJECT_CHARACTER_H

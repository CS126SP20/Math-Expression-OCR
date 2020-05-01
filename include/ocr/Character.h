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



class Character {

 public:
  explicit Character(const string& filepath);
  Character(const cv::Mat& mat);
  cv::Mat GetMatrix() const;
 private:
  cv::Mat character_mat_;
};

struct LabeledCharacter {
  Character character;
  string label;
};
}

#endif  // FINALPROJECT_CHARACTER_H

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

/** Scalar representing the RGB values of the padding pixels **/
const cv::Scalar kPadValue = cv::Scalar(255, 255, 255);
/** Ratio used in calculating the amount of padding to add to each dimension of the image **/
const double kPadRatio = 0.5;
/** Width of character, in pixels **/
const size_t kCharacterWidth = 20;
/** Height of character, in pixels **/
const size_t kCharacterHeight = 30;

class Character {

 public:

  explicit Character(const string& filepath);
  Character(const cv::Mat& mat);
  /**
   * @return The character matrix that has been flattened and converted to floats
   */
  cv::Mat GetFlattenedMatrix() const;
 private:
  /** Matrix representing  the pixels of a character image **/
  cv::Mat character_mat_;
  /**
   * Adds padding to a character to make sure it is square
   */
  void PadCharacter();
};

struct LabeledCharacter {
  Character character;
  string label;
};
}

#endif  // FINALPROJECT_CHARACTER_H

//
// Created by Rohini Sharma on 4/28/20.
//

#ifndef FINALPROJECT_LABELLEDIMAGE_H
#define FINALPROJECT_LABELLEDIMAGE_H
#include <ocr/Image.h>
namespace ocr {
enum class Labels {
  Zero,
  One,
  Two,
  Three,
  Four,
  Five,
  Six,
  Seven,
  Eight,
  Nine,
  OpenParentheses,
  CloseParentheses,
  OpenBracket,
  CloseBracket,
  Plus,
  Minus,
  Equals,
  Times,
  In,
  PlusOrMinus,
  Factorial,
  RightArrow,
  Sin,
  Cos,
  Tan,
  Lim,
  Log,
  Exists,
  ForAll,
  Sqrt,
  Over,
  GreaterOrEqual,
  Greater,
  LessOrEqual,
  Less,
  NotEqual,
  Divides,
  Integral,
  Infinity
};

class LabelledImage : public Image {
 public:


 private:
};
}

#endif  // FINALPROJECT_LABELLEDIMAGE_H

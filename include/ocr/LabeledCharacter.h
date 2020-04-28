//
// Created by Rohini Sharma on 4/28/20.
//

#ifndef FINALPROJECT_LABELEDIMAGE_H
#define FINALPROJECT_LABELEDIMAGE_H
#include <ocr/Character.h>

namespace ocr {
enum class Label {
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

class LabeledImage : public Image {
 public:
  LabeledImage(string& filepath, string& label);
  Label GetLabel() const;


 private:
};
}

#endif  // FINALPROJECT_LABELEDIMAGE_H

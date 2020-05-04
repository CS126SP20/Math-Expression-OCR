// Copyright (c) 2020 CS126SP20. All rights reserved.

#ifndef FINALPROJECT_APPS_MYAPP_H_
#define FINALPROJECT_APPS_MYAPP_H_

#include <cinder/app/App.h>
#include <cinder/gl/Texture.h>
#include <ocr/KNN_Model.h>
#include <ocr/Image.h>

using cinder::gl::Texture2dRef;
using ocr::KNN_Model;
namespace myapp {
const char kNormalFont[] = "Arial Unicode MS";
const string kModelPath = "../../../../../../assets/knn_all.xml";
const size_t kFontSize = 50;
const size_t kCenterX = 400;
const size_t kCenterY = 400;

class MyApp : public cinder::app::App {
 public:

  MyApp();
  void setup() override;

  void update() override;
  void draw() override;
  void keyDown(cinder::app::KeyEvent) override;

 private:
  KNN_Model model;
  Texture2dRef texture;

  void PrintDetectedCharacters(const string& result);
  void PrintEvaluatedExpression(const string& exp);
  void PrintText(const string& text, const cinder::Color& color, const cinder::ivec2& size,
            const cinder::vec2& loc);
};

}  // namespace myapp

#endif  // FINALPROJECT_APPS_MYAPP_H_

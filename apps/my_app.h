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
const string kModelPath = "../../../../../../assets/knn_resize.xml";
const size_t kFontSize = 50;
const size_t kCenterX = 400;
const size_t kCenterY = 400;
const cinder::vec2 kImagePosition = {200, 0};
const cinder::vec2 kTrainingStatusSize = {300, 70};
const cinder::vec2 kDetectedCharactersSize = {500, 60};
const size_t kDetectedCharacterOffset = 20;
const size_t kEvaluatedExpressionOffset = 70;
const cinder::vec2 kEvaluatedExpressionSize = {700, 60};

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
  bool should_start_training;
  bool model_is_training;
  bool model_is_saved;

  void PrintDetectedCharacters(const string& result);
  void PrintEvaluatedExpression(const string& exp);
  void PrintText(const string& text, const cinder::Color& color, const cinder::ivec2& size,
            const cinder::vec2& loc);
};

}  // namespace myapp

#endif  // FINALPROJECT_APPS_MYAPP_H_

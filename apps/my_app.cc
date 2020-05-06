// Copyright (c) 2020 [Your Name]. All rights reserved.

#include "my_app.h"
#include <gflags/gflags.h>
#include <cinder/app/App.h>
#include <cinder/gl/gl.h>
#include <opencv2/highgui/highgui.hpp>
#include <ocr/KNN_Model.h>
#include <ocr/Image.h>
#include <expression_evaluation/Expression.h>
#include <filesystem>

using ocr::KNN_Model;
using ocr::Image;
using expression_evaluator::Expression;
using cinder::Surface;
using cinder::Area;
using cinder::gl::Texture;
using cinder::TextBox;
using cinder::Color;
using cinder::ColorA;


namespace myapp {
using cinder::gl::Texture2d;
using cinder::app::KeyEvent;

DECLARE_string(equation);
DECLARE_string(model);
DECLARE_bool(train);
DECLARE_string(training_images);
DECLARE_string(training_labels);
DECLARE_string(model_save_path);


MyApp::MyApp() {


}

void MyApp::setup() {
  if (!FLAGS_train) {
    auto img = cinder::loadImage(FLAGS_equation);
    model.Load(FLAGS_model);
    texture = Texture2d::create(img);
  } else {
    should_start_training = false;
    model_is_saved = false;
  }


}

void MyApp::update() {
  if (FLAGS_train) {
    if (should_start_training) {
      model.Train(FLAGS_training_images, FLAGS_training_labels);
      should_start_training = false;
      model_is_training = true;
    }
    if (model.IsTrained() && !model_is_saved) {
      model.Save(FLAGS_model_save_path);
      model_is_training = false;
      model_is_saved = true;
    }
  }
}

void MyApp::draw(){
  if (!FLAGS_train) {
    cinder::gl::draw(texture, {200, 0});
    string result = model.ClassifyImage(FLAGS_equation);
    PrintDetectedCharacters("Detected: " + result);
    Expression exp(result);
    string evaluation = exp.Evaluate();
    PrintEvaluatedExpression("Evaluation: " + evaluation);
  } else {
    if (!should_start_training && !model.IsTrained()) {
      PrintText(
          "Training... ",
          Color::white(), {300, 70}, getWindowCenter());
      should_start_training = true;
    }
    if (model_is_saved){
      PrintText(
          "Training Complete! ",
          Color::white(), {500, 200}, getWindowCenter());
    }
  }
}

void MyApp::keyDown(KeyEvent event) { }

void MyApp::PrintDetectedCharacters(const string& result) {
  const cinder::vec2 position  = {kCenterX, texture->getSize().y + 20 };
  const cinder::ivec2 size = {500, 60};
  const Color color = Color::white();
  PrintText(result, color, size, position);
}

void MyApp::PrintEvaluatedExpression(const string& exp) {
  const cinder::vec2 position  = {kCenterX, texture->getSize().y + 70 };
  const cinder::ivec2 size = {700, 60};
  const Color color = Color::white();
  PrintText(exp, color, size, position);
}

void ShowTrainingStatus() {

}

void MyApp::PrintText(const string& text, const Color& color, const cinder::ivec2& size,
               const cinder::vec2& loc) {
  cinder::gl::color(color);

  auto box = TextBox()
      .alignment(TextBox::CENTER)
      .font(cinder::Font(myapp::kNormalFont, myapp::kFontSize))
      .size(size)
      .color(color)
      .backgroundColor(ColorA(0, 0, 0, 0))
      .text(text);

  const auto box_size = box.getSize();
  const cinder::vec2 locp = {loc.x - box_size.x / 2, loc.y - box_size.y / 2};
  const auto surface = box.render();
  const auto texture = cinder::gl::Texture::create(surface);
  cinder::gl::draw(texture, locp);
}
} // namespace myapp

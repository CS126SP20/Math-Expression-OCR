// Copyright (c) 2020 [Your Name]. All rights reserved.

#include "my_app.h"
#include <cinder/app/App.h>
#include <cinder/gl/gl.h>
#include <opencv2/highgui/highgui.hpp>
#include <ocr/KNN_Model.h>
#include <expression_evaluation/Expression.h>
#include <ocr/Image.h>
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

MyApp::MyApp() {
  model.Load(kModelPath);
}

void MyApp::setup() {
  auto img = cinder::loadImage("../../../../../../tests/assets/addition2.jpg");
  texture = Texture2d::create(img);


}

void MyApp::update() {
}

void MyApp::draw(){
  cinder::gl::draw(texture);
  string result = model.ClassifyImage("../../../../../../tests/assets/addition2.jpg");
  PrintDetectedCharacters("Detected: " + result);
  Expression exp(result);
  string evaluation = exp.Evaluate();
  PrintEvaluatedExpression("Evaluation: " + evaluation);




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

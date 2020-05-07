// Copyright (c) 2020 [Your Name]. All rights reserved.

#include "my_app.h"
#include <gflags/gflags.h>
#include <cinder/app/App.h>
#include <cinder/gl/gl.h>
#include <cinder/ip/Resize.h>
#include <expression_evaluation/Expression.h>

using ocr::KNN_Model;
using ocr::Image;
using expression_evaluator::Expression;
using cinder::Surface;
using cinder::Area;
using cinder::gl::Texture;
using cinder::TextBox;
using cinder::Color;
using cinder::ColorA;
using cinder::ip::resize;
using cinder::gl::Texture2d;
using cinder::app::KeyEvent;

namespace myapp {

DECLARE_string(equation);
DECLARE_string(model);
DECLARE_bool(train);
DECLARE_string(training_images);
DECLARE_string(training_labels);
DECLARE_string(model_save_path);

MyApp::MyApp() = default;

void MyApp::setup() {
  if (!FLAGS_train) {
      Surface img = cinder::loadImage(FLAGS_equation);
      img = cinder::ip::resizeCopy(img,
                                   Area(0,0,img.getWidth(),img.getHeight()),  kImageSize);
      model.Load(FLAGS_model);
      img_to_classify_texture_ = Texture2d::create(img);
  } else {
    training_state_ = TrainingState::NotStarted;
    training_status_visible = false;
  }
}

void MyApp::update() {
  if (FLAGS_train) {
    if (!training_status_visible) {
      return;
    }
    if (training_state_ == TrainingState::NotStarted) {
      training_state_ = TrainingState::Training;
      model.Train(FLAGS_training_images, FLAGS_training_labels);
    }
    if (model.IsTrained() && training_state_ == TrainingState::Training) {
      training_state_ = TrainingState::Trained;
      model.Save(FLAGS_model_save_path);
    }
  }
}

void MyApp::draw(){
  if (!FLAGS_train) {
    cinder::gl::draw(img_to_classify_texture_, {getWindowCenter().x - kImageOffset, 0});
    string result = model.ClassifyImage(FLAGS_equation);
    PrintDetectedCharacters("Detected: " + result);
    Expression exp(result);
    string evaluation = exp.Evaluate();
    PrintEvaluatedExpression("Evaluation: " + evaluation);
  } else {
    if (!training_status_visible || training_state_ == TrainingState::Training) {
      PrintText(
          "Training... ",
          Color::white(), kTrainingStatusSize, getWindowCenter());
      training_status_visible = true;
    }
    if (training_state_ == TrainingState::Trained){
      cinder::gl::clear(ColorA::black());
      PrintText(
          "Training Complete!"
          "\nRerun with your model to evaluate an expression",
          Color::white(), kTrainingCompleteSize, getWindowCenter());
    }
  }
}

void MyApp::keyDown(KeyEvent event) { }

void MyApp::PrintDetectedCharacters(const string& result) {
  const cinder::vec2 position  = {getWindowCenter().x, 
                                  img_to_classify_texture_->getSize().y +
                                  kDetectedCharacterOffset};
  PrintText(result, Color::white(), kDetectedCharactersSize, position);
}

void MyApp::PrintEvaluatedExpression(const string& exp) {
  const cinder::vec2 position  = {getWindowCenter().x, 
                                  img_to_classify_texture_->getSize().y +
                                  kEvaluatedExpressionOffset};
  PrintText(exp, Color::white(), kEvaluatedExpressionSize, position);
}

void MyApp::PrintText(const string& text, const Color& color, const cinder::ivec2& size,
               const cinder::vec2& loc) {
  cinder::gl::color(color);

  auto box = TextBox()
      .alignment(TextBox::CENTER)
      .font(cinder::Font(myapp::kNormalFont, myapp::kFontSize))
      .size(size)
      .color(color)
      .backgroundColor(ColorA::black())
      .text(text);

  const auto box_size = box.getSize();
  const cinder::vec2 locp = {loc.x - box_size.x / 2, loc.y - box_size.y / 2};
  const auto surface = box.render();
  const auto texture = cinder::gl::Texture::create(surface);
  cinder::gl::draw(texture, locp);
}
} // namespace myapp

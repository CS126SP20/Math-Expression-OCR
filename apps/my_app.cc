// Copyright (c) 2020 [Your Name]. All rights reserved.

#include "my_app.h"
#include <cinder/app/App.h>
#include <cinder/gl/gl.h>
#include <opencv2/highgui/highgui.hpp>
#include <ocr/KNN_Model.h>
#include <ocr/Image.h>
#include <filesystem>

using ocr::KNN_Model;
using ocr::Image;
using cinder::Surface;
using cinder::Area;
using cinder::gl::Texture;
using cinder::TextBox;


namespace myapp {
using cinder::gl::Texture2d;
using cinder::app::KeyEvent;

MyApp::MyApp() {
  model = KNN_Model m("")
}

void MyApp::setup() {
  auto img = cinder::loadImage("../../../../../../tests/assets/5chars.jpg");

  texture = Texture2d::create(img);


}

void MyApp::update() {
}

void MyApp::draw(){
  cinder::gl::draw(texture);
  string result = model.ClassifyImage("../../../../../../tests/assets/5chars.jpg");
  const cinder::vec2 center = getWindowCenter();
  const cinder::ivec2 size = {500, 50};
  PrintText(result, Color::red(), size, center);

}

void MyApp::keyDown(KeyEvent event) { }

}

template <typename C>
void PrintText(const string& text, const C& color, const cinder::ivec2& size,
               const cinder::vec2& loc) {
  cinder::gl::color(color);

  auto box = TextBox()
      .alignment(TextBox::CENTER)
      .font(cinder::Font(kNormalFont, 30))
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














// namespace myapp

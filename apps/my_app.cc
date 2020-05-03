// Copyright (c) 2020 [Your Name]. All rights reserved.

#include "my_app.h"
#include <cinder/app/App.h>
#include <cinder/gl/gl.h>
#include <opencv2/highgui/highgui.hpp>
#include <ocr/KNN_Model.h>
#include <filesystem>

using ocr::KNN_Model;
using cinder::Surface;
using cinder::Area;
using cinder::gl::Texture;


namespace myapp {
using cinder::gl::Texture2d;
using cinder::app::KeyEvent;

MyApp::MyApp() {

}

void MyApp::setup() {
  auto img = cinder::loadImage("../../../../../../tests/assets/5chars.jpg");
  texture = Texture2d::create(img);


}

void MyApp::update() {
}

void MyApp::draw(){
  cinder::gl::draw(texture);


}

void MyApp::keyDown(KeyEvent event) { }

}  // namespace myapp

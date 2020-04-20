// Copyright (c) 2020 [Your Name]. All rights reserved.

#include "my_app.h"
#include <cinder/app/App.h>
#include <opencv2/highgui/highgui.hpp>

namespace myapp {
using cinder::app::KeyEvent;

MyApp::MyApp() {

}

void MyApp::setup() {
  cv::VideoCapture cap(0);
}

void MyApp::update() {
}

void MyApp::draw(){


}

void MyApp::keyDown(KeyEvent event) { }

}  // namespace myapp

// Copyright (c) 2020 [Your Name]. All rights reserved.

#include "my_app.h"
#include <cinder/app/App.h>
#include <opencv2/highgui/highgui.hpp>
#include <filesystem>
#include <iostream>
using std::cout;

namespace myapp {
using cinder::app::KeyEvent;

MyApp::MyApp() {

}

void MyApp::setup() {
  cv::Mat test_img = cv::imread("../../../../../../assets/plane.jpg");
  cv::imshow("test_image", test_img);
}

void MyApp::update() {
}

void MyApp::draw(){


}

void MyApp::keyDown(KeyEvent event) { }

}  // namespace myapp

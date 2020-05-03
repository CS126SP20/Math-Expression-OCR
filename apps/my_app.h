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

class MyApp : public cinder::app::App {
 public:

  MyApp();
  void setup() override;

  void update() override;
  void draw() override;
  void keyDown(cinder::app::KeyEvent) override;

 private:
  KNN_Model model;
  Image img;
  Texture2dRef texture;


};

}  // namespace myapp

#endif  // FINALPROJECT_APPS_MYAPP_H_

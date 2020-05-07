// Copyright (c) 2020 [Your Name]. All rights reserved.

#include <cinder/app/App.h>
#include <cinder/app/RendererGl.h>
#include <gflags/gflags.h>
#include "my_app.h"

using cinder::app::App;
using cinder::app::RendererGl;

namespace myapp {

DEFINE_string(training_images, "../../../../../../assets/training/", "path to the training images");
DEFINE_string(training_labels, "../../../../../../assets/train_labels.txt", "path to the training labels");
DEFINE_string(model_save_path,"../../../../../../assets/my_model.xml", "Path to save model after training");
DEFINE_bool(train, false, "Include this flag if you want to train a new model");
DEFINE_string(equation, "../../../../../../tests/assets/addition.png", "Path to the image to evaluate");
DEFINE_string(model, "../../../../../../assets/my_model.xml", "Path to the model to use to evaluate the image");

const int kSamples = 8;
const int kWidth = 800;
const int kHeight = 500;

void ParseArgs(vector<string>* args) {
  gflags::SetUsageMessage(
      "Evaluate an image of a mathematical expression. "
      "Pass --helpshort for options.");
  int argc = static_cast<int>(args->size());
  vector<char*> argvs;
  for (string& str : *args) {
    argvs.push_back(&str[0]);
  }
  char** argv = argvs.data();
  gflags::ParseCommandLineFlags(&argc, &argv, true);
}

void SetUp(App::Settings* settings) {
  vector<string> args = settings->getCommandLineArgs();
  ParseArgs(&args);
  settings->setWindowSize(kWidth, kHeight);
  settings->setTitle("My CS 126 Application");
}
}  // namespace myapp

CINDER_APP(myapp::MyApp,
           RendererGl(RendererGl::Options().msaa(myapp::kSamples)),
           myapp::SetUp)

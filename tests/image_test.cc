// Copyright (c) 2020 CS126SP20. All rights reserved.

#define CATCH_CONFIG_MAIN

#include <catch2/catch.hpp>
#include <cinder/Rand.h>
#include <ocr/Image.h>
#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include "opencv2/imgproc/imgproc.hpp"



using ocr::Image;
using std::cout;
using std::endl;

TEST_CASE("File path for image doesn't exist") {
  REQUIRE_THROWS(Image("bad/path"));
}

TEST_CASE("make an img") {
  Image image("../../../../../../tests/assets/test_images/0.jpg");
  image.GetMatrix();
}



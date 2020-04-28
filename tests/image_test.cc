// Copyright (c) 2020 CS126SP20. All rights reserved.

#define CATCH_CONFIG_MAIN

#include <cinder/Rand.h>
#include <ocr/Character.h>

#include <catch2/catch.hpp>
#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>

#include "opencv2/imgproc/imgproc.hpp"

using ocr::Character;
using std::cout;
using std::endl;

TEST_CASE("File path for image doesn't exist") {
  REQUIRE_THROWS(Character("bad/path"));
}

TEST_CASE("make an img") {
  Character image("../../../../../../tests/assets/test_images/0.jpg");
  image.GetMatrix();
}

//TODO matrix constructor

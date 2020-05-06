// Copyright (c) 2020 CS126SP20. All rights reserved.

#define CATCH_CONFIG_MAIN

#include <cinder/Rand.h>
#include <ocr/Character.h>

#include <catch2/catch.hpp>
#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/core/types.hpp>
#include "opencv2/imgproc/imgproc.hpp"

using ocr::Character;
using std::cout;
using std::endl;
using cv::Mat;

TEST_CASE("File path for character doesn't exist") {
  REQUIRE_THROWS(Character("bad/path"));
}

TEST_CASE("GetFlattenedMatrix Test") {
  //TODO:
  // Check test cases, add more if needed
  //Comments, whitespace and naming,
  //Write ReadMe
  Mat simple_mat = Mat::eye(3,3,  CV_8UC1);
  Character character(simple_mat);
  Mat flattened = character.GetFlattenedMatrix();
  SECTION("Has only one row") {
    REQUIRE(flattened.rows == 1);
  }

  SECTION("Has correct number of columns ") {
    REQUIRE(flattened.cols == ocr::kCharacterWidth * ocr::kCharacterHeight);
  }

  SECTION("Matrix has only one channel") {
    REQUIRE(flattened.channels() == 1);
  }

}



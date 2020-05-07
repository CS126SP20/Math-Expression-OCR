// Copyright (c) 2020 CS126SP20. All rights reserved.

#define CATCH_CONFIG_MAIN

#include <ocr/Character.h>
#include <catch2/catch.hpp>
#include <opencv2/core/types.hpp>

using ocr::Character;
using std::cout;
using std::endl;
using cv::Mat;

TEST_CASE("File path for character doesn't exist") {
  REQUIRE_THROWS(Character("bad/path"));
}

TEST_CASE("GetFlattenedMatrix Test") {
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



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

TEST_CASE("GetMatrix Test") {
  Mat simple_mat = Mat::eye(3,3,  CV_8UC1);
  Character character(simple_mat);
  //Created matrix has a non zero value at index where values are not same
  Mat differences = character.GetMatrix()
      !=  Mat::eye(3,3, CV_8UC1);
  REQUIRE(cv::countNonZero(differences) == 0);
}

TEST_CASE("GetContours Test") {
  //TODO add test
  Mat simple_mat = Mat::eye(3,3,  CV_8UC1);
  Character character(simple_mat);
}


//
// Created by Rohini Sharma on 4/30/20.
//

#include <ocr/matrix_utils.h>

#include <catch2/catch.hpp>
#include <iostream>
#include <opencv2/imgcodecs.hpp>

TEST_CASE("Process matrix test with resize") {
  Mat simple_mat = cv::imread("../../../../../../tests/assets/test_images/0.jpg");
  ocr::ProcessMatrix(simple_mat, true);

  SECTION("Matrix row resize") {
    REQUIRE(simple_mat.rows == 30);
  }

  SECTION("Matrix column resize") {
    REQUIRE(simple_mat.cols == 20);
  }

  SECTION("Matrix is grayscale now") {
    REQUIRE(simple_mat.channels() == 1);
  }
}

TEST_CASE("Process matrix test without resize") {
  Mat simple_mat = cv::imread("../../../../../../tests/assets/test_images/0.jpg");
  ocr::ProcessMatrix(simple_mat, false);

  SECTION("Matrix row hasn't been resized") {
    REQUIRE(simple_mat.rows == 50);
  }

  SECTION("Matrix column hasn't been resized") {
    REQUIRE(simple_mat.cols == 50);
  }

  SECTION("Matrix is grayscale now") {
    REQUIRE(simple_mat.channels() == 1);
  }
}

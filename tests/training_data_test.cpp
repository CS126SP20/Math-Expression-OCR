//
// Created by Rohini Sharma on 4/28/20.
//

#include <ocr/Character.h>
#include <ocr/TrainingData.h>

#include <catch2/catch.hpp>
#include <iostream>

using ocr::TrainingData;


string correct_training_img_path = "../../../../../../tests/assets/test_images/";
string correct_label_path = "../../../../../../tests/assets/test_labels.txt";

TEST_CASE("Invalid file paths") {
  SECTION("Invalid image directory") {
    string training_imgs = "bad/path";
    REQUIRE_THROWS(TrainingData(training_imgs, correct_label_path));
  }

  SECTION("Invalid label file path") {
    string training_label = "bad/path";
    REQUIRE_THROWS(
        TrainingData(correct_training_img_path, training_label));
  }
}

TEST_CASE("Exception thrown for too few labels") {
  string img_dir = "../../../../../../tests/assets/too_few_images/";
  REQUIRE_THROWS(
      TrainingData(img_dir, correct_label_path));
}

TEST_CASE("Numerical Labels Mat Test") {
  //TODO fix
  TrainingData training_data(correct_training_img_path, correct_label_path);
  float data[5] = {9,15,15,1,2};
  Mat expected = Mat(1, 5, CV_32F, data);
  Mat differences = training_data.GetNumericalLabelsMat() != expected;
  REQUIRE(cv::countNonZero(differences) == 0);
}

TEST_CASE("Flattened images mat test") {
  TrainingData training_data(correct_training_img_path, correct_label_path);
  Mat flattened_imgs = training_data.GetFlattenedCharsMat();
  SECTION("Flattened image matrix has correct number of rows") {
    REQUIRE(flattened_imgs.rows == 5);
  }

  SECTION("Flattened image matrix has correct number of columns") {
    REQUIRE(flattened_imgs.cols == 600);
  }
}


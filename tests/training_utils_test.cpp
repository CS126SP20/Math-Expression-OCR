//
// Created by Rohini Sharma on 4/28/20.
//

#include <catch2/catch.hpp>
#include <ocr/training_utils.h>
#include <ocr/Character.h>
#include <iostream>

using ocr::GetCharacters;
using ocr::LabeledCharacter;
using ocr::GetNumericalLabelsMat;
using ocr::GetFlattenedImagesMat;

TEST_CASE("Invalid file paths") {
  SECTION("Invalid image directory") {
    string training_imgs = "bad/path";
    string training_label = "../../../../../../tests/assets/test_labels.txt";
    REQUIRE_THROWS(GetCharacters(training_imgs, training_label));
  }

  SECTION("Invalid label file path") {
    string training_imgs = "../../../../../../tests/assets/test_images/";
    string training_label = "bad/path";
    REQUIRE_THROWS(GetCharacters(training_imgs, training_label));
  }
}


TEST_CASE("Valid paths") {
  string training_imgs = "../../../../../../tests/assets/test_images/";
  string training_label = "../../../../../../tests/assets/test_labels.txt";
  REQUIRE(GetCharacters(training_imgs, training_label).size() == 5);
}

TEST_CASE("Exception thrown for too few labels") {
  string training_imgs = "../../../../../../tests/assets/test_images/";
  string training_label = "../../../../../../tests/assets/too_few_labels.txt";
  REQUIRE_THROWS(GetCharacters(training_imgs, training_label));
}

TEST_CASE("Numerical Labels Mat Test") {
  string training_imgs = "../../../../../../tests/assets/test_images/";
  string training_label = "../../../../../../tests/assets/test_labels.txt";
  vector<LabeledCharacter> train_char = GetCharacters(training_imgs, training_label);
  float data[5] = {9,15,15,1,2};
  Mat expected = Mat(1, 5, CV_32FC1, data);
  Mat differences = GetNumericalLabelsMat(train_char) != expected;
  REQUIRE(cv::countNonZero(differences) == 0);
}

TEST_CASE("Flattened images mat test") {
  string training_imgs = "../../../../../../tests/assets/test_images/";
  string training_label = "../../../../../../tests/assets/test_labels.txt";
  vector<LabeledCharacter> train_char = GetCharacters(training_imgs, training_label);
  Mat flattened_imgs = GetFlattenedImagesMat(train_char);
  SECTION("Flattened image matrix has correct number of rows") {
    REQUIRE(flattened_imgs.rows == 5);
  }

  SECTION("Flattened image matrix has correct number of columns") {
    REQUIRE(flattened_imgs.cols == 900);
  }
}
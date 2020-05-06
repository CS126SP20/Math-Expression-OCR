//
// Created by Rohini Sharma on 4/28/20.
//

#include <ocr/Character.h>
#include <ocr/TrainingData.h>

#include <catch2/catch.hpp>
#include <iostream>

using ocr::GetFlattenedImagesMat;
using ocr::LabeledCharacter;
using ocr::GetNumericalLabelsMat;
using ocr::GetFlattenedImagesMat;
using ocr::GetLabeledCharacters;

string correct_training_img_path = "../../../../../../tests/assets/test_images/";
string correct_label_path = "../../../../../../tests/assets/test_labels.txt";

TEST_CASE("Invalid file paths") {
  SECTION("Invalid image directory") {
    string training_imgs = "bad/path";
    REQUIRE_THROWS(GetLabeledCharacters(training_imgs, correct_label_path));
  }

  SECTION("Invalid label file path") {
    string training_label = "bad/path";
    REQUIRE_THROWS(
        GetLabeledCharacters(correct_training_img_path, training_label));
  }
}

TEST_CASE("Valid path") {
  REQUIRE(GetLabeledCharacters(correct_training_img_path, correct_label_path).size() == 5);
}

TEST_CASE("Exception thrown for too few labels") {
  string img_dir = "../../../../../../tests/assets/too_few_images/";
  REQUIRE_THROWS(
      GetLabeledCharacters(img_dir, correct_label_path));
}

TEST_CASE("Numerical Labels Mat Test") {
  vector<LabeledCharacter> train_char =
      GetLabeledCharacters(correct_training_img_path, correct_label_path);
  float data[5] = {9,15,15,1,2};
  Mat expected = Mat(1, 5, CV_32F, data);
  Mat differences = GetNumericalLabelsMat(train_char) != expected;
  REQUIRE(cv::countNonZero(differences) == 0);
}

TEST_CASE("Flattened images mat test") {
  vector<LabeledCharacter> train_char =
      GetLabeledCharacters(correct_training_img_path, correct_label_path);
  Mat flattened_imgs = GetFlattenedImagesMat(train_char);
  SECTION("Flattened image matrix has correct number of rows") {
    REQUIRE(flattened_imgs.rows == 5);
  }

  SECTION("Flattened image matrix has correct number of columns") {
    REQUIRE(flattened_imgs.cols == 600);
  }
}


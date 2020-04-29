//
// Created by Rohini Sharma on 4/28/20.
//

#include <catch2/catch.hpp>
#include <ocr/training_utils.h>

using ocr::GetCharacters;

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
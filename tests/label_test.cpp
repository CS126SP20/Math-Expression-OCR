//
// Created by Rohini Sharma on 4/28/20.
//

#include <catch2/catch.hpp>
#include <ocr/labels.h>

using ocr::label_and_num_map_;

TEST_CASE("Label bimap initializaton") {
  SECTION("Check for correct size") {
    REQUIRE(label_and_num_map_.size() == 17);
  }

  SECTION("Access number with string key") {
    REQUIRE(label_and_num_map_.left.at('0') == 0);
  }

  SECTION("Access string with number key") {
    REQUIRE(label_and_num_map_.right.at(0) == '0');
  }
}


//
// Created by Rohini Sharma on 4/30/20.
//
#include <catch2/catch.hpp>
#include <ocr/Image.h>

//TODO add tests here

using ocr::Image;

TEST_CASE("Single character image has one character") {
  Image nine_image("../../../../../../tests/assets/sample_img.jpg");
  vector<Character> characters = nine_image.GetCharacters();
  REQUIRE(characters.size() == 5);
}
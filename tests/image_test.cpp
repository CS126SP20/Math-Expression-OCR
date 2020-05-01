//
// Created by Rohini Sharma on 4/30/20.
//
#include <catch2/catch.hpp>
#include <ocr/Image.h>


using ocr::Image;

TEST_CASE("Image of 5  characters") {
  Image five_characters("../../../../../../tests/assets/sample_img.jpg");
  vector<Character> characters = five_characters.GetCharacters();
  REQUIRE(characters.size() == 5);
}

TEST_CASE("Blank image") {
  Image blank("../../../../../../tests/assets/blank.png");
  vector<Character> characters = blank.GetCharacters();
  REQUIRE(characters.size() == 0);
}
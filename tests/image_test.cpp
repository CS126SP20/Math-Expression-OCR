//
// Created by Rohini Sharma on 4/30/20.
//
#include <catch2/catch.hpp>
#include <ocr/Image.h>


using ocr::Image;

TEST_CASE("Image of 5  characters") {
  Image five_characters("../../../../../../tests/assets/5chars.jpg");
  vector<Character> characters = five_characters.GetCharacters();
  REQUIRE(characters.size() == 5);
}

TEST_CASE("Image of 30 characters") {
  Image thirty_characters("../../../../../../tests/assets/30chars.png");
  vector<Character> characters = thirty_characters.GetCharacters();
  REQUIRE(characters.size() == 30);
}

TEST_CASE("Blank image") {
  Image blank("../../../../../../tests/assets/blank.png");
  vector<Character> characters = blank.GetCharacters();
  REQUIRE(characters.size() == 0);
}

TEST_CASE("Single character image") {
  Image nine("../../../../../../tests/assets/test_images/0.jpg");
  vector<Character> characters = nine.GetCharacters();
  REQUIRE(characters.size() == 1);
}


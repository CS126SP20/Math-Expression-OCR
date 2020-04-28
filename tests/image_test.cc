// Copyright (c) 2020 CS126SP20. All rights reserved.

#define CATCH_CONFIG_MAIN

#include <catch2/catch.hpp>
#include <cinder/Rand.h>
#include <ocr/Image.h>

using ocr::Image;

TEST_CASE("File path for image doesn't exist") {
  REQUIRE_THROWS(Image("bad/path"));
}


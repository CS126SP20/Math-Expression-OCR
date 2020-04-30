//
// Created by Rohini Sharma on 4/29/20.
//
#include <catch2/catch.hpp>
#include <ocr/KNN_Model.h>

using ocr::KNN_Model;

string training_img_path = "../../../../../../tests/assets/test_images/";
string label_path = "../../../../../../tests/assets/test_labels.txt";

TEST_CASE("Untrained model throws error") {
  KNN_Model model;
  REQUIRE_THROWS(model.Save("../../../../../../tests/assets/model.xml"));
}

TEST_CASE("Save trained model") {
  KNN_Model model;
  model.Train(training_img_path, label_path);
  model.Save("../../../../../../tests/assets/model.xml");
}
//
// Created by Rohini Sharma on 4/29/20.
//
#include <catch2/catch.hpp>
#include <ocr/KNN_Model.h>
#include <ocr/Character.h>
#include <ocr/training_utils.h>
#include <filesystem>

using ocr::KNN_Model;
using ocr::LabeledCharacter;
using ocr::GetLabeledCharacters;
using std::__fs::filesystem::exists;

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
  REQUIRE(exists("../../../../../../tests/assets/model.xml"));
}

TEST_CASE("Trained model has desirable accuracy") {
  KNN_Model model("../../../../../../assets/knn_resize.xml");
  vector<LabeledCharacter> eval_chars = GetLabeledCharacters("../../../../../../assets/test/",
      "../../../../../../assets/test_labels.txt");
  REQUIRE(model.EvaluateModel(eval_chars) > 75.00);
}

TEST_CASE("Classify image") {
  KNN_Model model("../../../../../../assets/knn.xml");
  string result = model.ClassifyImage("../../../../../../tests/assets/5chars.jpg");
  REQUIRE(result == "13540");
}

TEST_CASE("Train and classify") {
  KNN_Model model;
  model.Train( "../../../../../../assets/training/",  "../../../../../../assets/train_labels.txt");
  model.Save( "../../../../../../assets/knn_resize.xml");
  string result = model.ClassifyImage("../../../../../../tests/assets/5chars.jpg");
  REQUIRE(result == "13540");
}
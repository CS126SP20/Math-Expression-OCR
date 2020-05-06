//
// Created by Rohini Sharma on 4/29/20.
//
#include <ocr/Character.h>
#include <ocr/KNN_Model.h>
#include <ocr/TrainingData.h>

#include <catch2/catch.hpp>
#include <filesystem>

using ocr::KNN_Model;
using ocr::LabeledCharacter;
using ocr::TrainingData;
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
  //TODO fix
  KNN_Model model("../../../../../../assets/knn_resize.xml");
  TrainingData data("../../../../../../assets/test/",
      "../../../../../../assets/test_labels.txt");
  vector<LabeledCharacter> eval_chars = data.GetLabeledCharacters();
  REQUIRE(model.EvaluateModel(eval_chars) > 75.00);
}



//
// Created by Rohini Sharma on 4/28/20.
//

#include "ocr/training_utils.h"
#include <filesystem>
#include <ocr/Character.h>
#include <fstream>
#include <istream>
#include <vector>
#include <iostream>
#include <ocr/labels.h>
#include<opencv2/core/core.hpp>

using std::vector;
using std::__fs::filesystem::exists;
using std::__fs::filesystem::directory_iterator;
using std::ifstream;
using std::invalid_argument;
using ocr::LabeledCharacter;
using cv::Mat;
using cv::Mat1f;

namespace ocr {

vector<LabeledCharacter> GetCharacters(const string &characters_dir, const string& label_path) {
  ifstream label_file(label_path);
  if (!exists(characters_dir) || !label_file.is_open()) {
    throw invalid_argument("Please check training image directory and label file paths and try again");
  }
  string label_line;
  vector<LabeledCharacter> created_characters;

  for (const auto& file : directory_iterator(characters_dir)) {
    Character training_char(file.path());
    if (label_file.eof()) {
      throw invalid_argument("Your label file does not have enough labels."
                             " Please try again.");
    }
    getline(label_file, label_line);
    LabeledCharacter training_character {training_char, label_line};
    created_characters.push_back(training_character);
  }
  return created_characters;
}

Mat GetNumericalLabelsMat(const vector<LabeledCharacter>& training_chars) {
  vector<float> labels;
  for (LabeledCharacter character : training_chars) {
    float numerical_label = ocr::label_and_num_map_.left.at(character.label);
    labels.push_back(numerical_label);
  }
  Mat numerical_labels_mat(1, labels.size(), CV_32FC1, labels.data());
  return numerical_labels_mat;
}

Mat GetFlattenedImagesMat(const vector<LabeledCharacter>& training_chars) {
  Mat flattened_imgs;
  for (LabeledCharacter character : training_chars) {
    Mat single_img = character.character.GetMatrix().reshape(1,1);
    flattened_imgs.push_back(single_img);
  }
  return flattened_imgs;

}


}
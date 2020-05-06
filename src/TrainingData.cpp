//
// Created by Rohini Sharma on 4/28/20.
//

#include "ocr/TrainingData.h"

#include <ocr/Character.h>
#include <ocr/labels.h>
#include <ocr/matrix_utils.h>

#include <filesystem>
#include <fstream>
#include <iostream>
#include <istream>
#include <opencv2/core/core.hpp>
#include <vector>

using cv::Mat;
using std::__fs::filesystem::exists;
using std::__fs::filesystem::directory_iterator;
using std::ifstream;
using std::invalid_argument;
using std::to_string;
using ocr::LabeledCharacter;
using cv::Mat;
using cv::Mat1f;

namespace ocr {

TrainingData::TrainingData(const string& chars_dir, const string& label_path) {
    CreateLabeledCharacters(chars_dir, label_path);
}


void TrainingData::CreateLabeledCharacters(const string &characters_dir,
    const string& label_path) {
  ifstream label_file(label_path);
  if (!exists(characters_dir) || !label_file.is_open()) {
    throw invalid_argument("Please check training image directory and "
                           "label file paths and try again");
  }
  string label_line;
  vector<LabeledCharacter> created_characters;
  size_t file_num = 0;
  while(getline(label_file, label_line)) {
    string character_path = characters_dir + to_string(file_num) + training_image_type;
    if (!exists(character_path)) {
      throw invalid_argument("Please make sure you have enough characters in your directory ");
    }
    Character training_char(character_path);
    LabeledCharacter training_character {training_char, label_line[0]};
    created_characters.push_back(training_character);
    file_num++;
  }
  labeled_chars_ =  created_characters;

}

 Mat TrainingData::GetNumericalLabelsMat() {
  vector<float> labels;
  for (LabeledCharacter character : labeled_chars_) {

      float numerical_label = ocr::label_and_num_map_.left.at(character.label);
      labels.push_back(numerical_label);

  }
  Mat numerical_labels_mat(labels);
  numerical_labels_mat.convertTo(numerical_labels_mat, CV_32F);
  return numerical_labels_mat;
}

Mat TrainingData::GetFlattenedCharsMat() {
  Mat flattened_chars;
  Mat flat2;
  Mat flat3;
  for (LabeledCharacter labeled_char : labeled_chars_) {
    Mat single_char = labeled_char.character.GetFlattenedMatrix();
    flattened_chars.push_back(single_char);
  }
  return flattened_chars;
}

vector<LabeledCharacter> TrainingData::GetLabeledCharacters() const {
    return labeled_chars_;
}


}
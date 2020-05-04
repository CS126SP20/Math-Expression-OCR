//
// Created by Rohini Sharma on 4/28/20.
//

#include "ocr/training_utils.h"

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

vector<LabeledCharacter> GetLabeledCharacters(const string &characters_dir,
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
    LabeledCharacter training_character {training_char, label_line};
    created_characters.push_back(training_character);
    file_num++;
  }
  return created_characters;

}

 Mat GetNumericalLabelsMat(const vector<LabeledCharacter>& training_chars) {
  vector<float> labels;
  for (LabeledCharacter character : training_chars) {

      float numerical_label = ocr::label_and_num_map_.left.at(character.label);
      labels.push_back(numerical_label);

  }
  //TODO fix ?
  Mat numerical_labels_mat(labels);
  numerical_labels_mat.convertTo(numerical_labels_mat, CV_32F);
  return numerical_labels_mat;
}

Mat GetFlattenedImagesMat(const vector<LabeledCharacter>& training_chars) {
  Mat flattened_imgs;
  Mat flat2;
  Mat flat3;
  for (LabeledCharacter character : training_chars) {
    Mat single_img;
    character.character.GetMatrix().convertTo(single_img, CV_32F);

  single_img = single_img.reshape(1,1);

    flattened_imgs.push_back(single_img);
  }
  return flattened_imgs;

}


}
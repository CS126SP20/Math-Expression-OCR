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
//    vector<float> desc = GetHOGDescriptors(single_img);
//    //TODO changed to HOG, rename and clean up
//    Mat to_add(desc);
//    to_add =  to_add.reshape(1,1);
  single_img = single_img.reshape(1,1);

    flattened_imgs.push_back(single_img);
  }
  return flattened_imgs;

}


}
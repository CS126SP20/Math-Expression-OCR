//
// Created by Rohini Sharma on 4/29/20.
//

#include "ocr/KNN_Model.h"

#include <ocr/Image.h>
#include <ocr/TrainingData.h>
#include <ocr/labels.h>
#include <ocr/matrix_utils.h>
#include <opencv2/ml/ml.hpp>
#include <filesystem>

using cv::Ptr;
using cv::Ptr;
using ocr::TrainingData;
using cv::ml::KNearest;
using ocr::Image;
using std::__fs::filesystem::exists;

namespace ocr {

KNN_Model::KNN_Model() {
  model_ = KNearest::create();
}

void KNN_Model::Train(const string& training_img_dir,
                      const string& label_path) {
  TrainingData train_data(training_img_dir, label_path);
  Mat flattened_imgs = train_data.GetFlattenedCharsMat();
  Mat labels = train_data.GetNumericalLabelsMat();
  model_->train(flattened_imgs, cv::ml::SampleTypes::ROW_SAMPLE, labels);
}

void KNN_Model::Save(const string& path) const {
  if (!model_->isTrained()) {
    throw "Model is not trained, could not save.";
  }
  model_->save(path);
}

void KNN_Model::Load(const string& path) {
  if (!exists(path)) {
    throw "No file exists at this path";
  }
  model_ = KNearest::load(path);
}

string KNN_Model::ClassifyImage(const string& image_path) const {
  if (!IsTrained()) {
    throw "Could not classify image, model has not been trained";
  }
  if (!exists(image_path)) {
    throw "This image does not exist, please check your path and try again";
  }
  string all_labels;
  Image image(image_path);
  vector<Character> all_characters = image.GetCharacters();
    for (Character character : all_characters) {
      all_labels += ClassifySingleCharacter(character);
    }
  return all_labels;
}

bool KNN_Model::IsTrained() const {
  return model_->isTrained();
}

double KNN_Model::EvaluateModel(vector<LabeledCharacter> labeled_chars) const {
  double num_correct = 0;
  for (LabeledCharacter labeled_character : labeled_chars) {
    char predicted_label = ClassifySingleCharacter(labeled_character.character);
    if (predicted_label == labeled_character.label) {
      num_correct++;
    }
  }
  std::cout << "Total Samples: " << labeled_chars.size() << std::endl;
  std::cout << "Number Correct: " << num_correct << std::endl;
  return (num_correct / labeled_chars.size()) * 100;
}

char KNN_Model::ClassifySingleCharacter(
    const Character& character_to_classify) const {
  Mat results(0, 0, CV_32F);
  Mat flattened_character_mat = character_to_classify.GetFlattenedMatrix();

  model_->findNearest(flattened_character_mat, kNumNearest, results);
  float numerical_label = results.at<float>(0, 0);
  char label = label_and_num_map_.right.at(numerical_label);
  return label;
}
}

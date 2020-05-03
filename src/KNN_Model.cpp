//
// Created by Rohini Sharma on 4/29/20.
//

#include "ocr/KNN_Model.h"

#include <ocr/Image.h>
#include <ocr/labels.h>
#include <ocr/training_utils.h>

#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/ml/ml.hpp>

using cv::Ptr;
using cv::Ptr;
using ocr::GetNumericalLabelsMat;
using ocr::GetFlattenedImagesMat;
using ocr::Image;

namespace ocr {

KNN_Model::KNN_Model() { kNearest_model_ = KNearest::create(); }

KNN_Model::KNN_Model(const string& saved_model) {
  kNearest_model_ = KNearest::load(saved_model);
}

void KNN_Model::Train(const string& training_img_dir,
                      const string& label_path) {
  vector<LabeledCharacter> training_characters =
      GetLabeledCharacters(training_img_dir, label_path);
  Mat flattened_imgs = GetFlattenedImagesMat(training_characters);
  Mat labels = GetNumericalLabelsMat(training_characters);
  std::cout << "Training model..." << std::endl;
  kNearest_model_->train(flattened_imgs, cv::ml::ROW_SAMPLE, labels);
  std::cout << "Training complete!" << std::endl;
}

void KNN_Model::Save(const string& path) const {
  if (!kNearest_model_->isTrained()) {
    throw "Model is not trained, could not save.";
  }
  kNearest_model_->save(path);
}

void KNN_Model::Load(const string& path) {
  kNearest_model_ = KNearest::load(path);
}

string KNN_Model::ClassifyImage(const string& image_path) const {
  string all_labels;
  Image image(image_path);
  vector<Character> all_characters = image.GetCharacters();
    for (Character character : all_characters) {
      all_labels.append(ClassifySingleCharacter(character));
    }
  return all_labels;
}

bool KNN_Model::IsTrained() const {
  return kNearest_model_->isTrained();
}

double KNN_Model::EvaluateModel(vector<LabeledCharacter> labeled_chars) const {
  double num_correct = 0;
  for (LabeledCharacter labeled_character : labeled_chars) {
    string predicted_label = ClassifySingleCharacter(labeled_character.character);
    if (predicted_label == labeled_character.label) {
      num_correct++;
    }
  }

  std::cout << "size " << labeled_chars.size() << std::endl;
  std::cout << "num correct" << num_correct << std::endl;
  return (num_correct / labeled_chars.size()) * 100;
}

string KNN_Model::ClassifySingleCharacter(
    const Character& character_to_classify) const {
  Mat results(0, 0, CV_32F);
  Mat flattened_character_mat = character_to_classify.GetMatrix();
  cv::resize(flattened_character_mat, flattened_character_mat, cv::Size(20,30));
  flattened_character_mat = flattened_character_mat.reshape(1, 1);
  flattened_character_mat.convertTo(flattened_character_mat, CV_32F);
  kNearest_model_->findNearest(flattened_character_mat, kNumNearest, results);
  float numerical_label = (float)results.at<float>(0, 0);
  numerical_label = round(numerical_label);
  string label = label_and_num_map_.right.at(numerical_label);
  return label;
}
}

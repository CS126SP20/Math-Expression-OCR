//
// Created by Rohini Sharma on 4/29/20.
//

#include "ocr/KNN_Model.h"
#include <ocr/training_utils.h>
#include <opencv2/ml/ml.hpp>
#include <ocr/labels.h>

using cv::ml::KNearest;
using cv::Ptr;
using ocr::GetNumericalLabelsMat;
using ocr::GetFlattenedImagesMat;

namespace ocr {

KNN_Model::KNN_Model() {
 kNearest_model_ = KNearest::create();
}

KNN_Model::KNN_Model(const string& saved_model) {
  kNearest_model_ = KNearest::load(saved_model);
}

void KNN_Model::Train(const string& training_img_dir, const string& label_path) {
  vector<LabeledCharacter> training_characters =
      GetTrainingCharacters(training_img_dir, label_path);
  Mat flattened_imgs = GetFlattenedImagesMat(training_characters);
  Mat labels = GetNumericalLabelsMat(training_characters);
  kNearest_model_->train(flattened_imgs, cv::ml::ROW_SAMPLE, labels);
}

void KNN_Model::Save(const string &path) const {
  if (!kNearest_model_->isTrained()) {
    throw "Model is not trained, could not save.";
  }
  kNearest_model_->save(path);
}




}

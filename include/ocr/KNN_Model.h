//
// Created by Rohini Sharma on 4/29/20.
//

#ifndef FINALPROJECT_KNN_MODEL_H
#define FINALPROJECT_KNN_MODEL_H
#include <opencv2/ml.hpp>
#include <string>
#include <ocr/Character.h>

using cv::ml::KNearest;
using std::string;
using ocr::Character;

namespace ocr {

const size_t kNumNearest = 5;

class KNN_Model {
 public:
  KNN_Model();
  KNN_Model(const string& saved_model_path);

  void Train(const string& training_img_dir, const string& label_path);
  void Save(const string& path) const;
  void Load(const string& path);
  string ClassifyImage(const string& image_path) const;
  double EvaluateModel(vector<LabeledCharacter> labeled_chars) const;

  bool IsTrained() const;

 private:
  cv::Ptr<KNearest> model_;
  string ClassifySingleCharacter(const Character& character_to_classify) const;


};

}


#endif  // FINALPROJECT_KNN_MODEL_H

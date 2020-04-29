//
// Created by Rohini Sharma on 4/29/20.
//

#ifndef FINALPROJECT_KNN_MODEL_H
#define FINALPROJECT_KNN_MODEL_H

namespace ocr {

class KNN_Model {
 public:
  KNN_Model();
  KNN_Model(const string& saved_model_path);
  Train(const string& training_img_dir, const string& label_path);

  string ClassifyImage(const string& image_path);

 private:
  string ClassifySingleCharacter(const Character& character_to_classify);


};


}


#endif  // FINALPROJECT_KNN_MODEL_H

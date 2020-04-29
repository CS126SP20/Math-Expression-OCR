//
// Created by Rohini Sharma on 4/29/20.
//

#include "KNN_Model.h"
#include<opencv2/ml/ml.hpp>

using cv::ml::KNearest;
using cv::Ptr;

namespace ocr {

KNN_Model::KNN_Model() {
  Ptr<KNearest> kNearest_model_(KNearest::create());
}

KNN_Model::KNN_Model(const string& saved_model) {
  Ptr<KNearest> kNearest_model_(KNearest::load(saved_model));
}


}

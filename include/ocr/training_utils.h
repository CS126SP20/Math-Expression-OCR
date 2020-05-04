//
// Created by Rohini Sharma on 4/28/20.
//

#ifndef FINALPROJECT_TRAINING_UTILS_H
#define FINALPROJECT_TRAINING_UTILS_H

#include <ocr/Character.h>
#include<opencv2/core/core.hpp>
#include <vector>

using std::vector;
using cv::Mat;

namespace ocr {

const string training_image_type = ".jpg";
vector<LabeledCharacter> GetLabeledCharacters(const string& characters_dir,
    const string& label_file);

Mat GetNumericalLabelsMat(const vector<LabeledCharacter>& training_chars);
Mat GetFlattenedImagesMat(const vector<LabeledCharacter>& training_chars);

}

#endif  // FINALPROJECT_TRAINING_UTILS_H

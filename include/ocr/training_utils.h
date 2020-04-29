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
vector<LabeledCharacter> GetCharacters(const string& characters_dir,
    const string& label_file);

Mat GetNumericalLabelsMat(vector<LabeledCharacter> training_chars);
Mat GetFlattenedImagesMat(vector<LabeledCharacter> training_chars);

}

#endif  // FINALPROJECT_TRAINING_UTILS_H

//
// Created by Rohini Sharma on 4/28/20.
//

#ifndef FINALPROJECT_TRAINING_UTILS_H
#define FINALPROJECT_TRAINING_UTILS_H

#include <ocr/Character.h>
#include <vector>

using std::vector;

namespace ocr {
vector<LabeledCharacter> GetCharacters(const string& characters_dir,
    const string& label_file);

}

#endif  // FINALPROJECT_TRAINING_UTILS_H

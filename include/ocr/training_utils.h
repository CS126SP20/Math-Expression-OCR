//
// Created by Rohini Sharma on 4/28/20.
//

#ifndef FINALPROJECT_TRAINING_UTILS_H
#define FINALPROJECT_TRAINING_UTILS_H

#include <ocr/Character.h>
#include <vector>


namespace ocr {

namespace helper_methods {
bool IsValidPath(const string& file_path);

}

vector<Character> GetCharacters(const string& characters_dir, const string&);


}

#endif  // FINALPROJECT_TRAINING_UTILS_H

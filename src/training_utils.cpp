//
// Created by Rohini Sharma on 4/28/20.
//

#include "ocr/training_utils.h"
#include <filesystem>
#include <ocr/Character.h>
#include <fstream>
#include <istream>
#include <vector>

using std::vector;
using std::__fs::filesystem::exists;
using std::ifstream;
using std::invalid_argument;

namespace ocr {

vector<Character> ocr::GetCharacters(const string &characters_dir, const string& label_path) {
  ifstream label_file(label_path);
  if (!exists(characters_dir) || !label_file.is_open()) {
    throw invalid_argument("Please check training image directory and label file paths and try again");
  }


}







}
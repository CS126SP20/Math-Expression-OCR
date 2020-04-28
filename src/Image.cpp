//
// Created by Rohini Sharma on 4/23/20.
//

#include "ocr/Image.h"
#include <filesystem>
#include <opencv2/imgcodecs.hpp>
#include <string>
#include <vector>

using std::string;
using std::vector;
using std::__fs::filesystem::exists;
using std::invalid_argument;
namespace ocr {



Image::Image(const string& filepath) {
  if (!exists(filepath)) {
    throw invalid_argument("Could not find image at path: " + filepath);
  }
 img_mat_ = cv::imread(filepath);
}


}

//
// Created by Rohini Sharma on 4/23/20.
//

#include "ocr/Image.h"
#include <opencv2/core/mat.hpp>
#include <string>
#include <vector>

using std::string;
using std::vector;
namespace ocr {

Image::Image() {}

Image::Image(string filepath) {}

cv::Mat Image::GetMatrix() const {  }
vector<vector<cv::Point>> Image::GetContours() const {   }

}

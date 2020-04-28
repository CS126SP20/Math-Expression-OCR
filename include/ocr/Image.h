//
// Created by Rohini Sharma on 4/23/20.
//

#ifndef FINALPROJECT_IMAGE_H
#define FINALPROJECT_IMAGE_H

#include <opencv2/core/mat.hpp>
#include <vector>

using std::vector;
using std::string;
namespace ocr {

class Image {
 public:
  explicit Image(const string& filepath);
 private:
  cv::Mat img_mat_;
};

}

#endif  // FINALPROJECT_IMAGE_H

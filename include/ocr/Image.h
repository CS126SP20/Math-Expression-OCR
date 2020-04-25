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
  Image();
  Image(string filepath);
  cv::Mat GetMatrix() const;
  vector<vector<cv::Point>> GetContours() const;
 private:
  cv::Mat img_mat_;
  vector<vector<cv::Point>> contours_;
};

}

#endif  // FINALPROJECT_IMAGE_H

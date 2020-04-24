//
// Created by Rohini Sharma on 4/23/20.
//

#ifndef FINALPROJECT_IMAGE_H
#define FINALPROJECT_IMAGE_H

#include <opencv2/core/mat.hpp>
namespace ocr {

class Image {
 public:
  Image()
  Image(std::string filepath);
  cv::Mat GetMatrix() const;
  vector<vector<cv::Point>> GetContours() const;
 private:
  cv::Mat GetMatrix() const;
};

}

#endif  // FINALPROJECT_IMAGE_H

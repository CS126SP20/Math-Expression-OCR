//
// Created by Rohini Sharma on 4/30/20.
//

#ifndef FINALPROJECT_IMAGE_H
#define FINALPROJECT_IMAGE_H

#include <vector>
#include <ocr/Character.h>
#include <opencv2/core.hpp>

using std::vector;
using ocr::Character;
using cv::Mat;


namespace ocr {
//TODO play with this number
const size_t kMinContourArea = 150;

struct Contour {
  vector<cv::Point> contour_points;
  cv::Rect bounding_rect;
};


class Image {
 public:
  Image(const string& path);
  vector<Character> GetCharacters();


 private:
  Mat image_mat_;
  vector<vector<cv::Point>> GetValidContours() const;
  Mat GetMatFromContour(const vector<cv::Point>& contour) const;


};
}


#endif  // FINALPROJECT_IMAGE_H

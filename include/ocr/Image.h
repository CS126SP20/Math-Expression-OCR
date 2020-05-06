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
const size_t kMinContourArea = 150;


class Image {
 public:
  /**
   * Creates an image object from an image file
   * @param path the path to the image to create an object from
   */
  Image(const string& path);
  /**
   * @return A vector of characters that the image contains, extracted based on
   * contours found in the image
   */
  vector<Character> GetCharacters();


 private:
  /** Matrix of pixels in the image **/
  Mat original_mat_;
  Mat processed_mat_;
  vector<vector<cv::Point>> GetValidContours() const;
  Mat GetMatFromContour(const vector<cv::Point>& contour) const;
  static bool SortContours(const vector<cv::Point>& first, const vector<cv::Point>& second);
  void ProcessEdges();


};
}


#endif  // FINALPROJECT_IMAGE_H

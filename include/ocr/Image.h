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
/** Minimum area for a contour to be considered valid **/
const size_t kMinContourArea = 150;
/** Size of kernel used in erosion or dilation operations **/
const size_t kKernelSize = 3;
/** Alpha value used to normalize image after Sobel operation**/
const double kNormAlpha = 0;
/** Beta value used to normalize image after Sobel operation**/
const double kNormBeta = 255;


class Image {
 public:
  /**
   * Creates an image object from an image file
   * @param path the path to the image to create an object from
   */
  explicit Image(const string& path);
  /**
   * @return A vector of characters that the image contains, extracted based on
   * contours found in the image
   */
  vector<Character> GetCharacters();


 private:
  /** Matrix of pixels in the image **/
  Mat original_mat_;
  /** Matrix of pixels after the image has been processed **/
  Mat processed_mat_;
  /**
   * Gets the contours that are bigger than the minimum contour area
   * @return A vector of vectors of points. Each vector of points represents a
   * contour.
   */
  vector<vector<cv::Point>> GetValidContours() const;
  /**
   * Returns the matrix for a region of interest bounded by a contour. i
   * First it gets the location and area of the bounding rectangle of the contour,
   * and then extracts this region from the original image matrix
   * @param contour The contour whose matrix we want
   * @return A matrix containing the region of the image with the contour
   */
  Mat GetMatFromContour(const vector<cv::Point>& contour);
  /**
   * Used to sort the contours in order from left to right in order to create a
   * string of what the image says from left to right
   * @param first The first contour to compare
   * @param second The second contour to compare
   * @return True if first is to the left of second on the image, false otherwise
   */
  static bool SortContours(const vector<cv::Point>& first, const vector<cv::Point>& second);
  /**
   * Used a Sobel filter and dilation to process the edges of the image.
   * This processing makes finding contours more accurate.
   */
  void ProcessEdges();


};
}


#endif  // FINALPROJECT_IMAGE_H

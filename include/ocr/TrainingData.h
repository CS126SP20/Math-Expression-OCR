//
// Created by Rohini Sharma on 4/28/20.
//

#ifndef FINALPROJECT_TRAININGDATA_H
#define FINALPROJECT_TRAININGDATA_H

#include <ocr/Character.h>
#include<opencv2/core/core.hpp>
#include <vector>

using std::vector;
using cv::Mat;

namespace ocr {
/** File extension of training images **/
const string training_image_type = ".jpg";

class TrainingData {
 public:
  /**
   * Creates a training data object from the images and labels provided.
   * Populates the labeled_chars_ variable with LabeledCharacter objects created
   * from the given paths
   * @param characters_dir Directory of training character images
   * @param label_file text file with labels for the images
   */
  TrainingData(const string& characters_dir, const string& label_file);
  /**
   * @return A column vector with the numerical class label of each training character
   * in the labeled_chars_ vector
   */
  Mat GetNumericalLabelsMat();
  /**
   * @return A matrix where each row is one training image that has been flattened
   * into a 1 x n row vector, where n is the total number of pixels
   */
  Mat GetFlattenedCharsMat();
  /**
   * @return A vector of LabeledCharacters from the directory and label file
   * passed in
   */
  vector<LabeledCharacter> GetLabeledCharacters() const;
 private:
  /** Vector of LabeledCharacters created from the training directory and labels **/
  vector<LabeledCharacter> labeled_chars_;
  /**
   * Populates the labeled_chars_ vector by iterating through the label file and
   * training directory and creating LabeledCharacter objects. Called in constructor
   * @param characters_dir path to directory of training images
   * @param label_file path to training image labels
   */
  void CreateLabeledCharacters(const string& characters_dir,
                                                const string& label_file);



};

}

#endif  // FINALPROJECT_TRAININGDATA_H

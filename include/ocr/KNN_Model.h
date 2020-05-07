//
// Created by Rohini Sharma on 4/29/20.
//

#ifndef FINALPROJECT_KNN_MODEL_H
#define FINALPROJECT_KNN_MODEL_H
#include <opencv2/ml.hpp>
#include <string>
#include <ocr/Character.h>

using cv::ml::KNearest;
using std::string;
using ocr::Character;

namespace ocr {
/** Number of nearest neighbor points to look at to classify a character **/
const size_t kNumNearest = 5;

class KNN_Model {
 public:
  /**
   * Creates an empty model object
   */
  KNN_Model();
  /**
   * Trains a KNN Model based on the image directory and labels passed in.
   * @param training_img_dir The path to the directory of training images
   * @param label_path A text file of labels for each training image
   */
  void Train(const string& training_img_dir, const string& label_path);
  /**
   * Saves the model to the specified file path. Throws an error if the model
   * is not trained.
   * @param path The path to save the model to
   */
  void Save(const string& path) const;
  /**
   * Loads a model from specified file path. Throws error if no file exists
   * at specified path.
   * @param path The path from which to load the model
   */
  void Load(const string& path);
  /**
   * Classifies the characters on a single image using the previously trained
   * model by getting its contours and classifying each one.
   * Throws error if model has not been trained or the path does not exist.
   * @param image_path the path to the image to classify
   * @return A string with the labels for each character found in the image,
   * from left to right.
   */
  string ClassifyImage(const string& image_path) const;
  /**
   * Tests the trained model by evaluating the number of correctly labeled
   * characters compared to the total number of characters
   * @param labeled_chars A vector of LabeledCharacters used as the test dataset
   * @return the percent of correctly labeled characters.
   */
  double EvaluateModel(const vector<LabeledCharacter>& labeled_chars) const;
  /**
   * @return True if the model has been trained, false if not.
   */
  bool IsTrained() const;
 private:
  /**  A smart pointer for the KNN Model **/
  cv::Ptr<KNearest> model_;
  /**
   * Classifies a single character using the trained model. Called in ClassifyImage
   * to classify the characters of the image.
   * @param character_to_classify The character we want to classify
   * @return The predicted character of the image
   */
  char ClassifySingleCharacter(const Character& character_to_classify) const;
};
}
#endif  // FINALPROJECT_KNN_MODEL_H

// Copyright (c) 2020 CS126SP20. All rights reserved.

#ifndef FINALPROJECT_APPS_MYAPP_H_
#define FINALPROJECT_APPS_MYAPP_H_

#include <cinder/app/App.h>
#include <cinder/gl/Texture.h>
#include <ocr/KNN_Model.h>
#include <ocr/Image.h>

using cinder::gl::Texture2dRef;
using ocr::KNN_Model;

namespace myapp {
/** Font to use on UI **/
const char kNormalFont[] = "Arial Unicode MS";
/** Font size for UI **/
const size_t kFontSize = 30;
/** Amount to offset image from center when displaying **/
const size_t kImageOffset = 125;
/** Size to display the image at **/
const cinder::vec2 kImageSize = {250, 250};
/** Size of training status text **/
const cinder::vec2 kTrainingStatusSize = {300, 70};
/** Size of training complete text **/
const cinder::vec2 kTrainingCompleteSize = {500, 120};
/** Size of detected characters text **/
const cinder::vec2 kDetectedCharactersSize = {500, 60};
/** Amount to offset detected characters text from image **/
const size_t kDetectedCharacterOffset = 40;
/** Amount to offset evaluated expression text from detected characters **/
const size_t kEvaluatedExpressionOffset = 90;
/** Size at which evaluated expression should be displayed **/
const cinder::vec2 kEvaluatedExpressionSize = {700, 60};

/**
 * Represents the state of the model when in training mode
 */
enum class TrainingState {
  NotStarted,
  Training,
  Trained,
};

class MyApp : public cinder::app::App {
 public:
  /**
   * Creates app object for cinder to run
   */
  MyApp();
  /**
   * Called once when app is starting up.
   * If in training mode, initializes training states
   * If not in training mode, intitializes image texture to display
   */
  void setup() override;
  /**
   * Called at each step of the app.
   * If in training mode, updates current training state as necessary
   */
  void update() override;
  /**
   * Displays information to UI
   * If in training mode, displays the training status
   * If not in training mode, displays image, detected characters and
   * evaluated expression.
   */
  void draw() override;
  /**
   * Called when a key is pressed
   */
  void keyDown(cinder::app::KeyEvent) override;

 private:
  /** KNN Model object that is trained in training mode or
   * otherwise used to classify an image **/
  KNN_Model model;
  /** Texture to hold the image to classify **/
  Texture2dRef img_to_classify_texture_;
  /** The training state of the model **/
  TrainingState training_state_;
  /** Whether or not the training status has been displayed **/
  bool training_status_visible;
  /**
   * Prints the detected characters to the UI if not in train mode
   * @param result The detected characters to print
   */
  void PrintDetectedCharacters(const string& result);
  /**
   * Prints the evaluated expression to the UI if not in train mode
   * @param exp the text to display
   */
  void PrintEvaluatedExpression(const string& exp);
  /**
   * Prints text to the UI
   * @param text text to print
   * @param color desired color of the text as Color object
   * @param size desired size of the text as vector
   * @param loc desired location of text as vector
   */
  static void PrintText(const string& text, const cinder::Color& color,
      const cinder::ivec2& size, const cinder::vec2& loc);
};
}  // namespace myapp

#endif  // FINALPROJECT_APPS_MYAPP_H_

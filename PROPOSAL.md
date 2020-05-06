#Project Proposal

Author: Rohini Sharma

  I am planning to use Cinder, along with the OpenCV library in order to create an application that reads a mathematical expression from an image, and evaluates it. The application will take a path to an image of text and display the calculated answer. I am planning to use Optical Character Recognition methods with OpenCV in order to do this.
  I will also use the ExprTk library for evaluating the string expression. 
  
I have used OpenCV in python previously, so I am familiar with the library. I am interested in computer vision, and I think this will be a good project to get more experience in computer vision and text recognition techniques. The main external libraries I will need are OpenCV and ExprTk. 

#### Week 1 Goals: 
Get CMake set up, make sure OpenCV block is being imported, load an image from disk and extract some information from it (pixel shade, etc)

#### Week 2 Goals: 
Use KNN to train a model that can detect the symbols in the image. 

#### Week 3 Goals: 
Evaluate the expression constructed from the detected symbols in the image. Add a UI to display information to the user.

Stretch goals: Add option to upload image or capture image from camera, train recognition for more complex equations. 

### Relevant Links:

https://en.wikipedia.org/wiki/Optical_character_recognition
https://towardsdatascience.com/a-gentle-introduction-to-ocr-ee1469a201aa 
http://www.partow.net/programming/exprtk/ 
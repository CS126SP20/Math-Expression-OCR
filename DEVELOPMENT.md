# Development 
Week 1

Got CMake set up, project compiles properly. I started out using the OpenCV cinder block, but then ran into a lot of issues with that. 
The cinder block was very old and there wasn't a lot of support for it, so I switched to using the regular OpenCV library instead. I was able to compile the 
OpenCV library and add it to my project.

Week 2

I decided to pivot my project a little bit to focus on evaluating written mathematical expressions. I decided to use the 
CROHME mathematical symbol dataset. I first had to process the training data, as the dataset comes in the inkml format. I 
converted these images to JPGs. I created an Character class to represent a single character extracted from an image. I created
a LabeledCharacter struct to represent a Charater that has a label. I also created some methods in the training
utils file to help with reading and processing training data. I created an Image class to represent an image that would
be provided by the user. I also created methods to extract Characters from each Image, based on the contours of the image. 
I created a KNN_Model class with methods for training a model and saving it the trained model to the file. I am also making methods
in the model class to classify an image by getting its characters and then classifying those individually.   



---

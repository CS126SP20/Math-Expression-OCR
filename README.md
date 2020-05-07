# Final Project: Expression Evaluator

[![license](https://img.shields.io/badge/license-MIT-green)](LICENSE)
[![docs](https://img.shields.io/badge/docs-yes-brightgreen)](docs/README.md)

Read [this document](https://cliutils.gitlab.io/modern-cmake/chapters/basics/structure.html) to understand the project
layout.

**Author**: Rohini Sharma - [`rohini2@illinois.edu`](mailto:rohini2@illinois.edu)

![Example](assets/readme_example.png?raw=true)

## About
Given an image of a mathematical expression, this program will identify the symbols in the image and 
evaluate the expression. The symbols are identified based on a default pretrained K-Nearest Neighbors model, or
other model specified by the user. The ExprTk library is then used to evaluate the expression and return its value. 
The default model was trained on the [CROHME] dataset. It can detect the following 
symbols with 85% accuracy: 

0, 1,  2, 3, 4, 5, 6, 7, 8, 9, +, =, -, (, ), [, ]


## Dependencies
- [Cinder]
- [cmake]
- [OpenCV]
- [ExprTk]

Install Cinder at ~/Cinder, using the above link. Create a directory called my-projects in ~/Cinder. Clone this repo into
my-projects. This project was developed in CLion on MacOS, and is not necessarily optimized for Windows. 

## Usage
To run this program, run the ```cinder-myapp``` executable located in the 
```cmake-build-debug/Debug/cinder-myapp/cinder-myapp.app/Contents/MacOS/``` directory. 

### Training a new model
In order to train a new KNN model, run the executable with the ```--train``` flag. Use ```--training_images``` to specify
the directory for training images. Use ```--training_labels``` to specify the training label text file. Each image in the 
training directory must be in the format X.JPG where X is the line number of the text file that has the 
corresponding label for the image. Use the ```--model_save_path``` flag to specify the path where you would like your new model
saved.

If ```--train``` is passed without training images or training labels, the default training data will be used. If 
```--model_save_path``` is not specified, the model will be saved at ```assets/my_model.xml```

### Evaluating an expression
To evaluate an equation, pass the path to the equation using the ```--equation``` flag. If no equation is passed, a default
image will be used. If you wish to use a model other than the default KNN Model, pass it to the program using the 
```--model``` flag. This model must be an .xml or .yml format. 
 
#### Examples 
Train a model using default training data:  

```cinder-myapp --train```

 Train a new model with images in ```~/my-training-images/``` and labels at ```~/labels.txt```:

```cinder-myapp --train --training_images ~/my-training-images/ --training_labels ~/labels```

Evaluate default expression image: 

```cinder-myapp```

Evaluate expression image at ```~/my_equation.jpg``` using model at ```~/my_new_model.xml```

```cinder-myapp --equation ~/my_equation.jpg --model ~/my_new_model.xml```









[Cinder]: https://libcinder.org/download
[cmake]: https://cmake.org/
[OpenCV]: https://blog.zhajor.com/2016/10/install-opencv-and-make-a-test-project-with-clion/
[ExprTk]: https://github.com/ArashPartow/exprtk
[CROHME]: http://www.iapr-tc11.org/mediawiki/index.php?title=CROHME:_Competition_on_Recognition_of_Online_Handwritten_Mathematical_Expressions

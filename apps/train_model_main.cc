#include <iostream>

#include <core/image.h>
#include <core/file_processors/image_processor.h>
#include <core/model.h>
#include <core/image.h>

// TODO: You may want to change main's signature to take in argc and argv
int main() {
  // TODO: Replace this with code that reads the training data, trains a model,
  // and saves the trained model to a file.

  std::vector<naivebayes::Image> training_images = naivebayes::Image::ImagesFromFile("C:\\Users\\zaids\\Cinder\\my-projects\\naive-bayes-ZaidBarkat\\trainingimagesandlabels.txt");
  naivebayes::Model model;
  model.Train(training_images);
  return 0;
}

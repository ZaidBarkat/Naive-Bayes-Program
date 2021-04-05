#include <iostream>

#include <core/image.h>
#include <core/image_processor.h>
#include <core/model.h>
#include <core/image.h>

// TODO: You may want to change main's signature to take in argc and argv
int main() {
  // TODO: Replace this with code that reads the training data, trains a model,
  // and saves the trained model to a file.

    naivebayes::ImageProcessor file = naivebayes::ImageProcessor("..\\trainingimagesandlabels.txt");
    naivebayes::model model(file.getImages(), file.GetLength());
    model.CalculatePriorProbabilities();
    model.CalculateFeatureProbabilities();
  return 0;
}

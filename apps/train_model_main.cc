#include <iostream>

#include <core/Image.h>
#include <core/File.h>
#include <core/Model.h>
#include <core/Image.h>

// TODO: You may want to change main's signature to take in argc and argv
int main() {
  // TODO: Replace this with code that reads the training data, trains a model,
  // and saves the trained model to a file.

    naivebayes::File file = naivebayes::File("..\\trainingimagesandlabels.txt");
    naivebayes::Model model(file.getImages(), file.GetLength());
    model.CalculatePriorProbabilities();
    model.CalculateFeatureProbabilities();
  return 0;
}

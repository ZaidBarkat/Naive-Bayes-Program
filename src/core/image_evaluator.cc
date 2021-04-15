#include <core/image.h>
#include <fstream>
#include <sstream>
#include <core/image_evaluator.h>
#include <core/model.h>

namespace naivebayes {

    void ImageEvaluator::Classify(Image image_to_classify, Model model) {
        int length = model.GetFeatureProbabilities().size();
        int class_length = model.GetFeatureProbabilities()[0][0].size();
        float probability;
        vector<float> classify_probability;

        for (int c = 0; c < class_length; c++) {
            probability = log(model.GetPriorProbabilities()[c]);
            for (int i = 0; i < length; i++) {
                for (int j = 0; j < length; j++) {
                    if (image_to_classify.GetPixels()[i][j] == ' ') {
                        probability += log(model.GetFeatureProbabilities()[i][j][c][0]);
                    } else {
                        probability += log(model.GetFeatureProbabilities()[i][j][c][1]);
                    }
                }
            }

            classify_probability.push_back(probability);
        }

        float max = classify_probability[0];
        for (size_t p = 0; p < classify_probability.size(); p++) {
            if (max < classify_probability[p]) {
                max = classify_probability[p];
                label_ = p;
            }
        }

    }

    int ImageEvaluator::GetLabel() const {
        return label_;
    }

}
// namespace naivebayes
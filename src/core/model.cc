#include <core/model.h>

#include <utility>

namespace naivebayes {

    Model::Model() {
        prior_probabilities_.resize(fNumberOfClasses);
    }

    void Model::Train(vector<Image> images) {
        images_ = images;
        vector<int> class_size;
        Initialize4DVector();

        class_size.resize(fNumberOfClasses, (int) fInitialValue);
        for (const Image &image: images) {
            ++class_size[image.GetClass()];
        }

        CalculatePriorProbabilities(class_size);
        CalculateFeatureProbabilities(class_size);
    }

    void Model::CalculatePriorProbabilities(vector<int> class_size) {
        for (size_t i = 0; i < prior_probabilities_.size(); i++) {
            prior_probabilities_[i] =
                    (float) (fK + class_size[i]) / (float) (fNumberOfClasses * fK + images_.size());
        }
    }

    void Model::CalculateFeatureProbabilities(vector<int> class_size) {
        int number_of_images_unshaded = 0;
        int number_of_images_shaded = 0;
        int length = images_[0].GetPixels().size();

        for (int i = 0; i < length; i++) {
            for (int j = 0; j < length; j++) {
                for (int c = 0; c < (int) class_size.size(); c++) {
                    for (const Image &image: images_) {

                        if (image.GetClass() == c) {
                            if (image.GetPixels()[i][j] == ' ') {
                                ++number_of_images_unshaded;
                            } else if (image.GetPixels()[i][j] == '+' || image.GetPixels()[i][j] == '#') {
                                ++number_of_images_shaded;
                            }
                        }
                    }
                    feature_probabilities_[i][j][c][0] =
                            (float) (fK + number_of_images_unshaded) / (float) (fShadeSize * fK + class_size[c]);
                    feature_probabilities_[i][j][c][1] =
                            (float) (fK + number_of_images_shaded) / (float) (fShadeSize * fK + class_size[c]);
                    number_of_images_shaded = 0;
                    number_of_images_unshaded = 0;
                }
            }
        }
    }

    std::istream &operator>>(std::istream &input, Model &model) {
        //std::string line;
        model.Initialize4DVector();
        int length = model.feature_probabilities_[0].size();

        for (int i = 0; i < length; i++) {
            for (int j = 0; j < length; j++) {
                for (int c = 0; c < model.fNumberOfClasses; c++) {
                    for (int s = 0; s < model.fShadeSize; s++) {
                       // getline(input, line);
                        input >> model.feature_probabilities_[i][j][c][s];
                        //model.feature_probabilities_[i][j][c][s] = std::stof(line);
                    }
                }
            }
        }

        for (float &probability: model.prior_probabilities_) {
            input >> probability;
//            getline(input, line);
//            probability = std::stof(line);
        }
        return input;
    }

    std::ostream &operator<<(std::ostream &output, Model &model) {
        int length = model.feature_probabilities_[0].size();

        for (int i = 0; i < length; i++) {
            for (int j = 0; j < length; j++) {
                for (int c = 0; c < model.fNumberOfClasses; c++) {
                    for (int s = 0; s < model.fShadeSize; s++) {
                        output << model.feature_probabilities_[i][j][c][s] << std::endl;
                    }
                }
            }
        }
        for (float probability: model.prior_probabilities_) {
            output << probability << std::endl;
        }

        return output;
    }

    void Model::Initialize4DVector() {
        int length = images_[0].GetPixels().size();
        feature_probabilities_ = std::vector<std::vector<std::vector<std::vector<float>>>>(length,
                                                                                           std::vector<std::vector<std::vector<float>>>(
                                                                                                   length,
                                                                                                   std::vector<std::vector<float>>(
                                                                                                           (int) fNumberOfClasses,
                                                                                                           std::vector<float>(
                                                                                                                   fShadeSize,
                                                                                                                   fInitialValue))));
    }

    const vector<float> &Model::GetPriorProbabilities() const {
        return prior_probabilities_;
    }

    const vector<vector<vector<vector<float>>>> &Model::GetFeatureProbabilities() const {
        return feature_probabilities_;
    }


}  // namespace naivebayes
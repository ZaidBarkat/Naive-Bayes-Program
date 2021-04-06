#include <core/model.h>

namespace naivebayes {

    Model::Model(vector<Image> images, int length) {
        images_ = images;
        length_ = length;

        class_size_.resize(fNumberOfClasses, (int) fInitialValue);
        for (Image image: images_) {
            if (image.GetClass() < 0) {
                continue;
            }
            ++class_size_[image.GetClass()];
        }
    }

    Model::Model() {}

    void Model::CalculatePriorProbabilities() {
        prior_probabilities_.resize(fNumberOfClasses);

        for (size_t i = 0; i < prior_probabilities_.size(); i++) {
            prior_probabilities_[i] =
                    (fK + (float) class_size_[i]) / (fNumberOfClasses * fK + (float) (images_.size() - 1));
        }
    }

    void Model::CalculateFeatureProbabilities() {
        int sum = -1;
        int number_of_images_unshaded = 0;
        int number_of_images_shaded = 0;

        Initialize4DVector();

        for (int i = 0; i < length_; i++) {
            for (int j = 0; j < length_; j++) {
                sum++;
                for (int c = 0; c < (int) class_size_.size(); c++) {
                    for (Image image: images_) {

                        if (image.GetClass() == c) {
                            if (image.GetPixels()[sum] == '0') {
                                ++number_of_images_unshaded;
                            } else if (image.GetPixels()[sum] == '1') {
                                ++number_of_images_shaded;
                            }
                        }
                    }
                    feature_probabilities_[i][j][c][0] =
                            (fK + (float) number_of_images_unshaded) / (fShadeSize * fK + (float) class_size_[c]);
                    feature_probabilities_[i][j][c][1] =
                            (fK + (float) number_of_images_shaded) / (fShadeSize * fK + (float) class_size_[c]);
                    number_of_images_shaded = 0;
                    number_of_images_unshaded = 0;
                }
            }
        }
    }

    std::istream &operator>>(std::istream &input, Model &model) {
        std::string line;
        getline(input, line);
        model.length_ = std::stoi(line);
        model.Initialize4DVector();
        model.prior_probabilities_.resize(model.fNumberOfClasses);

        for (int i = 0; i < model.length_; i++) {
            for (int j = 0; j < model.length_; j++) {
                for (int c = 0; c < model.fNumberOfClasses; c++) {
                    for (int s = 0; s < model.fShadeSize; s++) {
                        getline(input, line);
                        model.feature_probabilities_[i][j][c][s] = std::stof(line);
                    }
                }
            }
        }

        for (float &probability: model.prior_probabilities_) {
            getline(input, line);
            probability = std::stof(line);
        }
        return input;
    }

    std::ostream &operator<<(std::ostream &output, Model &model) {
        output << model.length_ << std::endl;
        for (int i = 0; i < model.length_; i++) {
            for (int j = 0; j < model.length_; j++) {
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
        feature_probabilities_ = std::vector<std::vector<std::vector<std::vector<float>>>>(length_,
                                                                                           std::vector<std::vector<std::vector<float>>>(
                                                                                                   length_,
                                                                                                   std::vector<std::vector<float>>(
                                                                                                           (int) fNumberOfClasses,
                                                                                                           std::vector<float>(
                                                                                                                   fShadeSize,
                                                                                                                   fInitialValue))));
    }

    const vector<float> &Model::GetPriorProbabilities() const {
        return prior_probabilities_;
    }


}  // namespace naivebayes
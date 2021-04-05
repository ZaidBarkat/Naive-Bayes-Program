#include <core/Model.h>

namespace naivebayes {

    Model::Model(vector<Image> images, int length) {
        images_ = images;
        length_ = length;

        class_size_.resize(10, 0);
        for(Image image: images_) {
            if (image.GetClass() < 0) {
                continue;
            }
            ++class_size_[image.GetClass()];
        }
    }

    void Model::CalculatePriorProbabilities() {
        prior_probabilities_.resize(10);

        for (size_t i = 0; i < prior_probabilities_.size(); i++) {
            prior_probabilities_[i] = fK * (float) class_size_[i] / (10 * fK * (float) (images_.size() - 1));
        }
    }

    void Model::CalculateFeatureProbabilities() {
        int sum = -1;
        int number_of_images_unshaded = 0;
        int number_of_images_shaded = 0;

        auto vector = std::vector<std::vector<std::vector<std::vector<float>>>>(length_, std::vector<std::vector<std::vector<float>>>(length_, std::vector<std::vector<float>>((int) class_size_.size(), std::vector<float>(fShadeSize, fInitialValue))));

        for (int i = 0; i < length_; i++) {

            for (int j = 0; j < length_; j++) {
                sum++;
                if (sum == images_[0].GetPixels().size()) {
                    break;
                }
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
                    vector[i][j][c][0] = fK * (float) number_of_images_unshaded / (2 * fK * (float) class_size_[c]);
                    vector[i][j][c][1] = fK * (float) number_of_images_shaded / (2 * fK * (float) class_size_[c]);
                    number_of_images_shaded = 0;
                    number_of_images_unshaded = 0;
                }
            }
        }
        feature_probabilities_ = vector;
    }

    const vector<float> &Model::GetPriorProbabilities() const {
        return prior_probabilities_;
    }


}  // namespace naivebayes
#include <core/Model.h>

namespace naivebayes {

    Model::Model(vector<Image> images) {
        images_ = images;

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
            prior_probabilities_[i] = (float) class_size_[i] / (float) (images_.size() - 1);
        }

    }

    const vector<float> &Model::GetPriorProbabilities() const {
        return prior_probabilities_;
    }


}  // namespace naivebayes
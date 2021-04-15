#pragma once

#include <string>
#include <vector>
#include "model.h"

namespace naivebayes {

    using std::string;
    using std::vector;

    class ImageEvaluator {
    public:
        /**
         * Classify an image between 0 to 9.
         *
         * @param image_to_classify gives the image
         * @param model that has the training data
         */
        void Classify(Image image_to_classify, Model model);

        int GetLabel() const;

    private:
        int label_;
    };

}  // namespace naivebayes

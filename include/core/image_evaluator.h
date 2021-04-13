#pragma once

#include <string>
#include <vector>
#include "model.h"

namespace naivebayes {

    using std::string;
    using std::vector;

    class ImageEvaluator {
    public:
        void Classify(Image image_to_classify, Model model);

    private:
        int label_;
    };

}  // namespace naivebayes

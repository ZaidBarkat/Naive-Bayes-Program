#pragma once

#include <string>
#include <vector>

namespace naivebayes {

    using std::string;
    using std::vector;

    class ImageEvaluator {
    public:
        void Classify(Image image_to_classify, vector<Image> training_images);

    private:
        int label_;
    };

}  // namespace naivebayes

#pragma once
#include <string>
#include <vector>
#include "Image.h"

namespace naivebayes {

    using std::string;
    using std::vector;

    class Model {
    public:
        Model(vector<Image> images);

        void CalculatePriorProbabilities();

        const vector<float> &GetPriorProbabilities() const;

    private:
        vector<Image> images_;
        vector<int> class_size_;
        vector<float> prior_probabilities_;

        vector<vector<vector<vector<int>>>> feature_probabilities_;


};

}  // namespace naivebayes

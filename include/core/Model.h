#pragma once
#include <string>
#include <vector>
#include "Image.h"

namespace naivebayes {

    using std::string;
    using std::vector;

    class Model {
    public:
        Model(vector<Image> images, int length);

        void CalculatePriorProbabilities();

        void CalculateFeatureProbabilities();

        const vector<float> &GetPriorProbabilities() const;

    private:
        static float constexpr fK = 1;
        static float constexpr fShadeSize = 2;
        static float constexpr fInitialValue = 0;

        int length_;
        vector<Image> images_;
        vector<int> class_size_;
        vector<float> prior_probabilities_;

        vector<vector<vector<vector<float>>>> feature_probabilities_;


};

}  // namespace naivebayes

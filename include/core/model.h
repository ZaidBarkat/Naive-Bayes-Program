#pragma once

#include <string>
#include <vector>
#include "image.h"

namespace naivebayes {

    using std::string;
    using std::vector;

    class model {
    public:
        model(vector<image> images, int length);

        void CalculatePriorProbabilities();

        void CalculateFeatureProbabilities();

        const vector<float> &GetPriorProbabilities() const;

    private:
        static int constexpr fK = 1;
        static int constexpr fShadeSize = 2;
        static float constexpr fInitialValue = 0;
        static int constexpr fNumberOfClasses = 10;

        int length_;
        vector<image> images_;
        vector<int> class_size_;
        vector<float> prior_probabilities_;

        vector<vector<vector<vector<float>>>> feature_probabilities_;


    };

}  // namespace naivebayes

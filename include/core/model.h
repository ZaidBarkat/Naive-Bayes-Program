#pragma once

#include <string>
#include <vector>
#include "image.h"

namespace naivebayes {

    using std::string;
    using std::vector;

    class Model {
    public:

        /**
         * Empty constructor that also resizes vectors.
         */
        Model();

        friend std::istream &operator>>(std::istream &input, Model &model);

        friend std::ostream &operator<<(std::ostream &output, Model &model);

        /**
         * Calculated Prior and Feature probabilities.
         * @param images that are going to be used to calculate probabilities
         */
        void Train(vector<Image> images);


        const vector<float> &GetPriorProbabilities() const;

        const vector<vector<vector<vector<float>>>> &GetFeatureProbabilities() const;

    private:
        static int constexpr fK = 1;
        static int constexpr fShadeSize = 2;
        static float constexpr fInitialValue = 0;
        static int constexpr fNumberOfClasses = 10;

        vector<Image> images_;

        vector<float> prior_probabilities_;
        vector<vector<vector<vector<float>>>> feature_probabilities_;

        /**
         * Calculates the probability of each class between 0 to 9.
         */
        void CalculatePriorProbabilities(vector<int> class_size);

        /**
         * Calculated the probability of each pixel in a given class for all classes.
         */
        void CalculateFeatureProbabilities(vector<int> class_size);

        /**
         * Initialize a 4D vector.
         */
        void Initialize4DVector();


    };

}  // namespace naivebayes

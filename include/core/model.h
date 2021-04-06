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
         * Initialize the vector based on the given images
         *
         * @param images from the ImagerProcessor
         * @param length from the ImageProcessor
         */
        Model(vector<Image> images, int length);

        /**
         * empty constructor if model is being written from a file.
         */
        Model();

        friend std::istream &operator>>(std::istream &input, Model &model);

        friend std::ostream &operator<<(std::ostream &output, Model &model);

        /**
         * Calculates the probability of each class between 0 to 9.
         */
        void CalculatePriorProbabilities();

        /**
         * Calculated the probability of each pixel in a given class for all classes.
         */
        void CalculateFeatureProbabilities();


        const vector<float> &GetPriorProbabilities() const;

        const vector<vector<vector<vector<float>>>> &GetFeatureProbabilities() const;

    private:
        static int constexpr fK = 1;
        static int constexpr fShadeSize = 2;
        static float constexpr fInitialValue = 0;
        static int constexpr fNumberOfClasses = 10;

        int length_{};
        vector<Image> images_;
        vector<int> class_size_;
        vector<float> prior_probabilities_;
        vector<vector<vector<vector<float>>>> feature_probabilities_;

        /**
         * Initialize a 4D vector.
         */
        void Initialize4DVector();


    };

}  // namespace naivebayes

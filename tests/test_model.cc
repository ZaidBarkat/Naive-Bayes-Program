#include <catch2/catch.hpp>

#include <core/file_processors/image_processor.h>
#include <core/model.h>
#include <core/file_processors/model_processor.h>
#include <fstream>


TEST_CASE("Check Model class") {
    naivebayes::ImageProcessor image_file(
            "C:\\Users\\zaids\\Cinder\\my-projects\\naive-bayes-ZaidBarkat\\testimagesandlabels.txt");
    naivebayes::Model model(image_file.getImages(), image_file.GetLength());
    model.CalculatePriorProbabilities();
    model.CalculateFeatureProbabilities();
    SECTION("Check Model prior probabilities") {
        SECTION("Test model prior data") {
            REQUIRE(0.0740740746f == Approx(model.GetPriorProbabilities()[2]));
        }SECTION("Test model prior data again") {
            REQUIRE(0.1481481493f == Approx(model.GetPriorProbabilities()[9]));
        }
    }SECTION("Check Model feature probabilities") {
        SECTION("Test model feature data") {
            REQUIRE(0.8f == Approx(model.GetFeatureProbabilities()[0][27][9][0]));
        }SECTION("Test model feature data again") {
            REQUIRE(0.6f == Approx(model.GetFeatureProbabilities()[14][14][1][1]));
        }
    }
}

TEST_CASE("Check Model class for 7 by 7") {
    naivebayes::ImageProcessor image_file(
            "C:\\Users\\zaids\\Cinder\\my-projects\\naive-bayes-ZaidBarkat\\testimagesandlabelssmaller.txt");
    naivebayes::Model model(image_file.getImages(), image_file.GetLength());
    model.CalculatePriorProbabilities();
    model.CalculateFeatureProbabilities();
    SECTION("Check Model prior probabilities") {
        SECTION("Test model prior data") {
            REQUIRE(0.1875f == Approx(model.GetPriorProbabilities()[5]));
        }SECTION("Test model prior data again") {
            REQUIRE(0.1875f == Approx(model.GetPriorProbabilities()[4]));
        }
    }SECTION("Check Model feature probabilities") {
        SECTION("Test model feature data") {
            REQUIRE(0.5f == Approx(model.GetFeatureProbabilities()[0][5][1][0]));
        }SECTION("Test model feature data again") {
            REQUIRE(0.25f == Approx(model.GetFeatureProbabilities()[5][0][4][1]));
        }
    }
}
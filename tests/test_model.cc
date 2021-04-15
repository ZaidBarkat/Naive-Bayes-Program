#include <catch2/catch.hpp>
#include <core/model.h>
#include <fstream>


TEST_CASE("Check Model class") {
    naivebayes::Model model;
    model.Train(naivebayes::Image::ImagesFromFile(
            "C:\\Users\\zaids\\Cinder\\my-projects\\naive-bayes-ZaidBarkat\\testimagesandlabels.txt"));
    SECTION("Check Model prior probabilities") {

        SECTION("Test model prior data") {
            REQUIRE(0.0740740746f == Approx(model.GetPriorProbabilities()[2]));
        }
        SECTION("Test model prior data again") {
            REQUIRE(0.1481481493f == Approx(model.GetPriorProbabilities()[9]));
        }
    }
    SECTION("Check Model feature probabilities") {

        SECTION("Test model feature data") {
            REQUIRE(0.8f == Approx(model.GetFeatureProbabilities()[0][27][9][0]));
        }
        SECTION("Test model feature data again") {
            REQUIRE(0.6f == Approx(model.GetFeatureProbabilities()[14][14][1][1]));
        }
    }
}

TEST_CASE("Check Model class for 2 by 2") {
    naivebayes::Model model;
    model.Train(naivebayes::Image::ImagesFromFile(
            "C:\\Users\\zaids\\Cinder\\my-projects\\naive-bayes-ZaidBarkat\\testimagesandlabelssmaller.txt"));
    SECTION("Check Model prior probabilities") {
        SECTION("Test model prior data") {
            REQUIRE(0.1538461596f == Approx(model.GetPriorProbabilities()[0]));
        }
        SECTION("Test model prior data again") {
            REQUIRE(0.0769230798f == Approx(model.GetPriorProbabilities()[1]));
        }
        SECTION("Test model prior data") {
            REQUIRE(0.0769230798f == Approx(model.GetPriorProbabilities()[2]));
        }
        SECTION("Test model prior data again") {
            REQUIRE(0.0769230798f == Approx(model.GetPriorProbabilities()[3]));
        }
        SECTION("Test model prior data") {
            REQUIRE(0.1538461596f == Approx(model.GetPriorProbabilities()[4]));
        }
        SECTION("Test model prior data again") {
            REQUIRE(0.1538461596f == Approx(model.GetPriorProbabilities()[5]));
        }
        SECTION("Test model prior data") {
            REQUIRE(0.0769230798f == Approx(model.GetPriorProbabilities()[6]));
        }
        SECTION("Test model prior data again") {
            REQUIRE(0.0769230798f == Approx(model.GetPriorProbabilities()[7]));
        }
        SECTION("Test model prior data again") {
            REQUIRE(0.0769230798f == Approx(model.GetPriorProbabilities()[8]));
        }
        SECTION("Test model prior data again") {
            REQUIRE(0.0769230798f == Approx(model.GetPriorProbabilities()[9]));
        }
    }
    SECTION("Check Model feature probabilities for class 0") {

        SECTION("Test model feature data") {
            REQUIRE(0.6666666865f == Approx(model.GetFeatureProbabilities()[0][0][0][0]));
        }
        SECTION("Test model feature data again") {
            REQUIRE(0.3333333433f == Approx(model.GetFeatureProbabilities()[0][0][0][1]));
        }
        SECTION("Test model feature data") {
            REQUIRE(0.6666666865f == Approx(model.GetFeatureProbabilities()[0][1][0][0]));
        }
        SECTION("Test model feature data again") {
            REQUIRE(0.3333333433f == Approx(model.GetFeatureProbabilities()[0][1][0][1]));
        }
        SECTION("Test model feature data") {
            REQUIRE(0.3333333433f == Approx(model.GetFeatureProbabilities()[1][0][0][0]));
        }
        SECTION("Test model feature data again") {
            REQUIRE(0.6666666865f == Approx(model.GetFeatureProbabilities()[1][0][0][1]));
        }
        SECTION("Test model feature data") {
            REQUIRE(0.3333333433f == Approx(model.GetFeatureProbabilities()[1][1][0][0]));
        }
        SECTION("Test model feature data again") {
            REQUIRE(0.6666666865f == Approx(model.GetFeatureProbabilities()[1][1][0][1]));
        }
    }

    SECTION("Check Model feature probabilities for class 1") {

        SECTION("Test model feature data") {
            REQUIRE(0.5f == Approx(model.GetFeatureProbabilities()[0][0][1][0]));
        }
        SECTION("Test model feature data again") {
            REQUIRE(0.5f == Approx(model.GetFeatureProbabilities()[0][0][1][1]));
        }
        SECTION("Test model feature data") {
            REQUIRE(0.5f == Approx(model.GetFeatureProbabilities()[0][1][1][0]));
        }
        SECTION("Test model feature data again") {
            REQUIRE(0.5f == Approx(model.GetFeatureProbabilities()[0][1][1][1]));
        }
        SECTION("Test model feature data") {
            REQUIRE(0.5f == Approx(model.GetFeatureProbabilities()[1][0][1][0]));
        }
        SECTION("Test model feature data again") {
            REQUIRE(0.5f == Approx(model.GetFeatureProbabilities()[1][0][1][1]));
        }
        SECTION("Test model feature data") {
            REQUIRE(0.5f == Approx(model.GetFeatureProbabilities()[1][1][1][0]));
        }
        SECTION("Test model feature data again") {
            REQUIRE(0.5f == Approx(model.GetFeatureProbabilities()[1][1][1][1]));
        }
    }
}
#include <catch2/catch.hpp>
#include <core/model.h>
#include <fstream>



TEST_CASE("Check Model load and write") {
    naivebayes::Model model;
    model.Train(naivebayes::Image::ImagesFromFile("C:\\Users\\zaids\\Cinder\\my-projects\\naive-bayes-ZaidBarkat\\testimagesandlabels.txt"));
    SECTION("Check Model write file") {

        std::ofstream file("C:\\Users\\zaids\\Cinder\\my-projects\\naive-bayes-ZaidBarkat\\modelprobabilities.txt");
        if (file.is_open()) {
            file << model;
        }

        std::string line;
        std::ifstream check_file("C:\\Users\\zaids\\Cinder\\my-projects\\naive-bayes-ZaidBarkat\\modelprobabilities.txt");
        getline(check_file, line);
        SECTION("Test model file Write line length") {
            REQUIRE("28" == line);
        }
        SECTION("Test model file Write data") {
            getline(check_file, line);
            REQUIRE("0.75" == line);
        }
    }
    SECTION("Check Model load file") {
        naivebayes::Model new_model;
        std::ifstream file("C:\\Users\\zaids\\Cinder\\my-projects\\naive-bayes-ZaidBarkat\\modelprobabilities.txt");
        if (file.is_open()) {
            file >> new_model;
        }

        SECTION("Test model file prior data") {
            REQUIRE(0.11111f == Approx(new_model.GetPriorProbabilities()[0]));
        }
        SECTION("Test model file feature data") {
            REQUIRE(0.6f == Approx(new_model.GetFeatureProbabilities()[14][14][1][1]));
        }
    }
}

TEST_CASE("Check Model load and write for 7 by 7") {
    naivebayes::Model model;
    model.Train(naivebayes::Image::ImagesFromFile("C:\\Users\\zaids\\Cinder\\my-projects\\naive-bayes-ZaidBarkat\\testimagesandlabelssmaller.txt"));
    SECTION("Check Model write file") {
        std::ofstream file("C:\\Users\\zaids\\Cinder\\my-projects\\naive-bayes-ZaidBarkat\\modelprobabilities.txt");
        if (file.is_open()) {
            file << model;
        }

        std::string line;
        std::ifstream check_file("C:\\Users\\zaids\\Cinder\\my-projects\\naive-bayes-ZaidBarkat\\modelprobabilities.txt");
        getline(check_file, line);
        SECTION("Test model file Write line length") {
            REQUIRE("7" == line);
        }
        SECTION("Test model file Write data") {
            getline(check_file, line);
            REQUIRE("0.75" == line);
        }
    }SECTION("Check Model load file") {
        naivebayes::Model new_model;
        std::ifstream file("C:\\Users\\zaids\\Cinder\\my-projects\\naive-bayes-ZaidBarkat\\modelprobabilities.txt");
        if (file.is_open()) {
            file >> model;
        }
        SECTION("Test model file prior data") {
            REQUIRE(0.1875f == Approx(new_model.GetPriorProbabilities()[0]));
        }
        SECTION("Test model file feature data") {
            REQUIRE(0.25f == Approx(new_model.GetFeatureProbabilities()[4][4][4][1]));
        }
        SECTION("Test new model data features") {
            REQUIRE(new_model.GetFeatureProbabilities() == model.GetFeatureProbabilities());
        }
        SECTION("Test new model data priors") {
            REQUIRE(new_model.GetPriorProbabilities() == model.GetPriorProbabilities());
        }
    }
}
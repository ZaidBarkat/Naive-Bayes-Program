#include <catch2/catch.hpp>

#include <core/file_processors/image_processor.h>
#include <core/model.h>
#include <core/file_processors/model_processor.h>
#include <fstream>


naivebayes::ModelProcessor model_file(
        "C:\\Users\\zaids\\Cinder\\my-projects\\naive-bayes-ZaidBarkat\\modelprobabilities.txt");

TEST_CASE("Check Model load and write") {
    naivebayes::ImageProcessor image_file(
            "C:\\Users\\zaids\\Cinder\\my-projects\\naive-bayes-ZaidBarkat\\testimagesandlabels.txt");
    naivebayes::Model model(image_file.getImages(), image_file.GetLength());
    model.CalculatePriorProbabilities();
    model.CalculateFeatureProbabilities();
    SECTION("Check Model write file") {
        model_file.Write(model);
        std::string line;
        std::ifstream file("C:\\Users\\zaids\\Cinder\\my-projects\\naive-bayes-ZaidBarkat\\modelprobabilities.txt");
        getline(file, line);
        SECTION("Test model file Write line length") {
            REQUIRE("28" == line);
        }SECTION("Test model file Write data") {
            getline(file, line);
            REQUIRE("0.75" == line);
        }
    }SECTION("Check Model load file") {
        naivebayes::Model new_model = model_file.Read();
        SECTION("Test model file prior data") {
            REQUIRE(0.11111f == Approx(new_model.GetPriorProbabilities()[0]));
        }SECTION("Test model file feature data") {
            REQUIRE(0.6f == Approx(new_model.GetFeatureProbabilities()[14][14][1][1]));
        }
    }
}

TEST_CASE("Check Model load and write for 7 by 7") {
    naivebayes::ImageProcessor image_file(
            "C:\\Users\\zaids\\Cinder\\my-projects\\naive-bayes-ZaidBarkat\\testimagesandlabelssmaller.txt");
    naivebayes::Model model(image_file.getImages(), image_file.GetLength());
    model.CalculatePriorProbabilities();
    model.CalculateFeatureProbabilities();
    SECTION("Check Model write file") {
        model_file.Write(model);
        std::string line;
        std::ifstream file("C:\\Users\\zaids\\Cinder\\my-projects\\naive-bayes-ZaidBarkat\\modelprobabilities.txt");
        getline(file, line);
        SECTION("Test model file Write line length") {
            REQUIRE("7" == line);
        }SECTION("Test model file Write data") {
            getline(file, line);
            REQUIRE("0.75" == line);
        }
    }SECTION("Check Model load file") {
        naivebayes::Model new_model = model_file.Read();
        SECTION("Test model file prior data") {
            REQUIRE(0.1875f == Approx(new_model.GetPriorProbabilities()[0]));
        }SECTION("Test model file feature data") {
            REQUIRE(0.25f == Approx(new_model.GetFeatureProbabilities()[4][4][4][1]));
        }
    }
}
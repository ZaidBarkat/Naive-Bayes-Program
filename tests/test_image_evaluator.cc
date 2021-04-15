#include <catch2/catch.hpp>
#include <core/model.h>
#include <core/image_evaluator.h>


TEST_CASE("Check classify labels") {
    naivebayes::Model model;
    model.Train(naivebayes::Image::ImagesFromFile(
            "C:\\Users\\zaids\\Cinder\\my-projects\\naive-bayes-ZaidBarkat\\trainingimagesandlabels.txt"));
    std::vector<naivebayes::Image> images = naivebayes::Image::ImagesFromFile(
            "C:\\Users\\zaids\\Cinder\\my-projects\\naive-bayes-ZaidBarkat\\testimagesandlabelsreal.txt");
    naivebayes::ImageEvaluator image_evaluator;
    image_evaluator.Classify(images[0], model);

    float increment = 0;
    for (int i = 0; i < 50; i++) {
        image_evaluator.Classify(images[i], model);

        if (image_evaluator.GetLabel() == images[i].GetClass()) {
            increment++;
        }
    }
    float accuracy = increment / 50;

    SECTION("Test accuracy of image evaluator") {
        REQUIRE(0.70 <= Approx(accuracy));
    }
    SECTION("Test first image label") {
        REQUIRE(9 == images[0].GetClass());
    }
    SECTION("Test second image label") {
        REQUIRE(0 == images[1].GetClass());
    }
    SECTION("Test third image label") {
        REQUIRE(2 == images[2].GetClass());
    }
    SECTION("Test fourth image label") {
        REQUIRE(5 == images[3].GetClass());
    }
//    SECTION("Test image file line length") {
//        REQUIRE(1 == images[4].GetClass());
//    }
//    SECTION("Test image file line length") {
//        REQUIRE(9 == images[5].GetClass());
//    }
//    SECTION("Test image file line length") {
//        REQUIRE(7 == images[6].GetClass());
//    }
//    SECTION("Test image file line length") {
//        REQUIRE(8 == images[7].GetClass());
//    }

}
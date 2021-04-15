#include <catch2/catch.hpp>
#include <core/model.h>


TEST_CASE("Check image data") {
    std::vector<naivebayes::Image> images = naivebayes::Image::ImagesFromFile(
            "C:\\Users\\zaids\\Cinder\\my-projects\\naive-bayes-ZaidBarkat\\testimagesandlabels.txt");

    SECTION("Test image class") {
        REQUIRE(5 == images[1].GetClass());
    }
    SECTION("Test image size") {
        REQUIRE(17 == images.size());
    }
}

TEST_CASE("Check image data with 7 by 7") {
    std::vector<naivebayes::Image> images = naivebayes::Image::ImagesFromFile(
            "C:\\Users\\zaids\\Cinder\\my-projects\\naive-bayes-ZaidBarkat\\testimagesandlabelssmaller.txt");
    SECTION("Test image class") {
        REQUIRE(5 == images[1].GetClass());
    }
    SECTION("Test image size") {
        REQUIRE(6 == images.size());
    }
}
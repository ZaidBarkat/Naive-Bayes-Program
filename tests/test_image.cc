#include <catch2/catch.hpp>

#include <core/file_processors/image_processor.h>
#include <core/model.h>
#include <core/file_processors/model_processor.h>


TEST_CASE("Check image data") {
    naivebayes::ImageProcessor file = naivebayes::ImageProcessor("C:\\Users\\zaids\\Cinder\\my-projects\\naive-bayes-ZaidBarkat\\testimagesandlabels.txt");
    SECTION("Test image class") {
        REQUIRE(5 == file.getImages()[1].GetClass());
    }
    SECTION("Test image pixels") {
        std::string test_string = file.getImages()[4].GetPixels().substr(158, 4);
        REQUIRE("+##+" == test_string);
    }
    SECTION("Test image size") {
        REQUIRE(17 == file.getImages().size() - 1);
    }
}
TEST_CASE("Check image data with 7 by 7") {
    naivebayes::ImageProcessor new_file = naivebayes::ImageProcessor("C:\\Users\\zaids\\Cinder\\my-projects\\naive-bayes-ZaidBarkat\\testimagesandlabelssmaller.txt");
    SECTION("Test image class") {
        REQUIRE(5 == new_file.getImages()[1].GetClass());
    }
    SECTION("Test image pixels") {
        std::string test_string = new_file.getImages()[4].GetPixels().substr(0, 3);
        REQUIRE("   " == test_string);
    }
    SECTION("Test image size") {
        REQUIRE(6 == new_file.getImages().size() - 1);
    }
}
#include <catch2/catch.hpp>

#include <core/file_processors/image_processor.h>
#include <core/model.h>
#include <core/file_processors/model_processor.h>


TEST_CASE("Check image file") {
    SECTION("Test image file line length") {
        naivebayes::ImageProcessor file = naivebayes::ImageProcessor("C:\\Users\\zaids\\Cinder\\my-projects\\naive-bayes-ZaidBarkat\\testimagesandlabels.txt");
        REQUIRE(28 == file.GetLength());
    }
    SECTION("Test image file line length for 7 by 7") {
        naivebayes::ImageProcessor smaller_file = naivebayes::ImageProcessor("C:\\Users\\zaids\\Cinder\\my-projects\\naive-bayes-ZaidBarkat\\testimagesandlabelssmaller.txt");
        REQUIRE(7 == smaller_file.GetLength());
    }
}
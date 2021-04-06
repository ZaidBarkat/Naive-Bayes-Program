#include <catch2/catch.hpp>

#include <core/file_processors/image_processor.h>
#include <core/model.h>
#include <core/file_processors/model_processor.h>

TEST_CASE("Check that 126 is the best class") {
    naivebayes::ImageProcessor file = naivebayes::ImageProcessor("C:\\Users\\zaids\\Cinder\\my-projects\\naive-bayes-ZaidBarkat\\trainingimagesandlabels.txt");
    naivebayes::Model model(file.getImages(), file.GetLength());
    model.CalculatePriorProbabilities();
    model.CalculateFeatureProbabilities();
    naivebayes::ModelProcessor processor("C:\\Users\\zaids\\Cinder\\my-projects\\naive-bayes-ZaidBarkat\\modelprobabilities.txt");
    processor.Write(model);
    naivebayes::Model new_model = processor.Read();
    REQUIRE(true);
}

/*
TODO: Rename this test file. You'll also need to modify CMakeLists.txt.
You can (and should) create more test files; this project is too big
for all tests to be in the same file. Remember that, for each file (foo.cc)
containing non-trivial code, you should have a corresponding test file
(foo_test.cc)
Make sure to add any files that you create to CMakeLists.txt.
TODO Delete this comment and the placeholder test before submitting your code.
*/
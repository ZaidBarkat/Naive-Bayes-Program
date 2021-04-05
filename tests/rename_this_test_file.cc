#include <catch2/catch.hpp>

#include <core/File.h>
#include <core/Model.h>

TEST_CASE("Check that 126 is the best class") {
    naivebayes::File file = naivebayes::File("..\\trainingimagesandlabels.txt");
    naivebayes::Model model(file.getImages());
    model.CalculatePriorProbabilities();
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
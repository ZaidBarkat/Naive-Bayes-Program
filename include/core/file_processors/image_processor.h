#include <string>
#include <vector>
#include "core/image.h"

namespace naivebayes {

    class ImageProcessor {
    public:
        /**
         * Takes a file, and gets the image of one number in that file, and then
         * pushes that value into a vector.
         *
         * @param file_location of the file path
         */
        ImageProcessor(const std::string& file_location);

        const vector<Image> &getImages() const;

        int GetLength() const;

    private:
        std::vector<Image> images_;
        int length_;
    };
}  // namespace naivebayes


#include <string>
#include <vector>
#include "image.h"

namespace naivebayes {

    class ImageProcessor {
    public:
        ImageProcessor(std::string file_location);

        const vector<image> &getImages() const;

        int GetLength() const;

    private:
        std::vector<image> images_;
        int length_;
    };
}  // namespace naivebayes


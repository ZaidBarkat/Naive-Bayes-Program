#include <string>
#include <vector>
#include "core/image.h"

namespace naivebayes {

    class ImageProcessor {
    public:
        ImageProcessor(std::string file_location);

        const vector<Image> &getImages() const;

        int GetLength() const;

    private:
        std::vector<Image> images_;
        int length_;
    };
}  // namespace naivebayes


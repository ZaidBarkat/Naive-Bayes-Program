#include <string>
#include <vector>
#include "Image.h"

namespace naivebayes {

    class File {
    public:
        File(std::string file_location);

        const vector<Image> &getImages() const;

        int GetLength() const;

    private:
        std::string file_name_;
        std::vector<Image> images_;
        int length_;
    };
}  // namespace naivebayes


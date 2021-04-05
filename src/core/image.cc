#include <core/image.h>

namespace naivebayes {

    std::istream &operator>>(std::istream &input, image &image) {
        std::string line;
        getline(input, line);
        image.pixels_ = line;

        image.class_ = (int) image.pixels_[0] - '0';
        image.pixels_.erase(0, 1);

        image.PixelToBits();
        return input;
    }

    void image::PixelToBits() {
        for (char &c: pixels_) {
            if (c == ' ') {
                c = '0';
            } else if (c == '+' || c == '#') {
                c = '1';
            }
        }
    }

    int image::GetClass() const {
        return class_;
    }

    const string &image::GetPixels() const {
        return pixels_;
    }


}  // namespace naivebayes
#include <core/image.h>

namespace naivebayes {

    std::istream &operator>>(std::istream &input, Image &image) {
        std::string line;
        getline(input, line);
        image.pixels_ = line;

        image.class_ = (int) image.pixels_[0] - '0';
        image.pixels_.erase(0, 1);

        return input;
    }

//    void Image::PixelToBits() {
//        for (char &c: pixels_) {
//            if (c == ' ') {
//                c = '0';
//            } else if (c == '+' || c == '#') {
//                c = '1';
//            }
//        }
//    }

    int Image::GetClass() const {
        return class_;
    }

    const string &Image::GetPixels() const {
        return pixels_;
    }


}  // namespace naivebayes
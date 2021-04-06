#pragma once

#include <string>
#include <vector>

namespace naivebayes {

    using std::string;
    using std::vector;

    class Image {
    public:
        int GetClass() const;

        friend std::istream &operator>>(std::istream &input, Image &image);

        const string &GetPixels() const;

    private:
        int class_;
        string pixels_;

        //void PixelToBits();
    };

}  // namespace naivebayes

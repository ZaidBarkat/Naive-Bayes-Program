#pragma once
#include <string>
#include <vector>

namespace naivebayes {

    using std::string;
    using std::vector;

    class Image {
    public:
        int GetClass() const;

        const string &GetPixels() const;

        friend std::istream &operator>>(std::istream &input, Image &image);

    private:
        int class_;
        string pixels_;

        void PixelToBits();



    };

}  // namespace naivebayes

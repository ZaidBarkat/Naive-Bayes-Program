#pragma once
#include <string>
#include <vector>

namespace naivebayes {

    using std::string;
    using std::vector;

    class image {
    public:
        int GetClass() const;

        friend std::istream &operator>>(std::istream &input, image &image);

        const string &GetPixels() const;

    private:
        int class_;
        string pixels_;
        void PixelToBits();
    };

}  // namespace naivebayes

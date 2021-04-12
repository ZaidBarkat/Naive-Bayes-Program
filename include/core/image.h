#pragma once

#include <string>
#include <vector>

namespace naivebayes {

    using std::string;
    using std::vector;

    class Image {
    public:
        /**
         * Gets the class between 0 - 9 from the text file.
         *
         * @return an int of the class being used
         */
        int GetClass() const;

        /**
         * overload >> to get an image object filled through a text file.
         *
         * @param input that is being read
         * @param image that is being written to
         * @return the input stream
         */
        friend std::istream &operator>>(std::istream &input, Image &image);

        const vector<vector<char>> &GetPixels() const;

        static vector<Image> ImagesFromFile(std::string path);


    private:
        int class_;
        //string pixels_;
        vector<vector<char>> pixels_;
    };

}  // namespace naivebayes

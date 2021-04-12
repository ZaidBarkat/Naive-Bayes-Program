#include <core/image.h>
#include <fstream>
#include <sstream>

namespace naivebayes {

    std::istream &operator>>(std::istream &input, Image &image) {
        std::string line;
        input >> image.class_;
        getline(input, line);
        getline(input, line);

        int length = line.size();
        image.pixels_ = vector<vector<char>>(length, vector<char>(length, ' '));

        for (int i = 0; i < length; i++) {
            for (int j = 0; j < length; j++) {
                image.pixels_[i][j] = line[j];
            }
            getline(input, line);
        }

        return input;
    }

    int Image::GetClass() const {
        return class_;
    }

    const vector<vector<char>> &Image::GetPixels() const {
        return pixels_;
    }

    vector<Image> Image::ImagesFromFile(std::string path) {
        std::string line;
        vector<Image> images;
        std::ifstream file(path);
        Image current;

        while(file >> current) {
            images.push_back(current);
        }
        file.close();

        return images;
    }

//        if (file.is_open()) {
//            while (getline(file, line)) {
//                if (line.size() == 1) {
//                    std::istringstream iss(image_string);
//                    iss >> image;
//                    images.push_back(image);
//                    image_string = "";
//                }
//                image_string += line;
//            }
//            std::istringstream iss(image_string);
//            iss >> image;
//            images.push_back(image);
//            file.close();
       }
       // namespace naivebayes
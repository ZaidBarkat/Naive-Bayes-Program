#include <core/image.h>
#include <fstream>
#include <sstream>

namespace naivebayes {

    Image::Image(vector<vector<char>> pixels) : pixels_(pixels) {}

    Image::Image() {}

    std::istream &operator>>(std::istream &input, Image &image) {
        std::string line;
        getline(input, line);
        image.class_ = (int) line[0] - '0';
        line.erase(0, 1);
        image.pixels_ = vector<vector<char>>(image.length_, vector<char>(image.length_, ' '));

        int sum = 0;
        for (int i = 0; i < image.length_; i++) {
            for (int j = 0; j < image.length_; j++) {
                image.pixels_[i][j] = line[sum];
                sum++;
            }
            getline(input, line);
        }
//        std::string line;
//        input >> image.class_;
//
//        int length = line.size();
//        image.pixels_ = vector<vector<char>>(length, vector<char>(length, ' '));
//
//        for (int i = 0; i < length; i++) {
//        getline(input, line);
//            for (int j = 0; j < length; j++) {
//                image.pixels_[i][j] = line[j];
//            }
//        }

        return input;
    }

    int Image::GetClass() const {
        return class_;
    }

    const vector<vector<char>> &Image::GetPixels() const {
        return pixels_;
    }

    vector<Image> Image::ImagesFromFile(std::string path) {
        std::ifstream file(path);
        Image image;
        string line;
        string image_string;
        vector<Image> images;
        int length;

        int count = 0;

        if (file.is_open()) {
            while (getline(file, line)) {
                if (line.size() == 1 && count != 0) {
                    std::istringstream iss(image_string);
                    image.length_ = length;
                    iss >> image;
                    images.push_back(image);
                    image_string = "";
                }
                length = line.size();
                count++;
                image_string += line;
            }
            std::istringstream iss(image_string);
            iss >> image;
            images.push_back(image);
            file.close();
        }
//        std::string line;
//        vector<Image> images;
//        std::ifstream file(path);
//        Image current;
//
//        while(file >> current) {
//            images.push_back(current);
//        }
//        file.close();

        return images;
    }
       }
       // namespace naivebayes
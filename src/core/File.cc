
#include <core/File.h>
#include <fstream>
#include <sstream>
#include <iostream>

namespace naivebayes {

    File::File(std::string file_location) {
        file_name_ = file_location;

        std::ifstream file(file_name_);
        std::vector<Image> images;
        Image image;
        string line;
        string image_string;

        //file.open("trainingimagesandlabels.txt");

        if (file.is_open()) {
            std::cout<<"here"<<std::endl;
            while (getline(file, line)) {
                if (line.size() == 1) {
                    std::istringstream iss(image_string);
                    iss >> image;
                    images_.push_back(image);
                    image_string = "";
                }
                length_ = line.size();
                image_string += line;
            }
            std::istringstream iss(image_string);
            iss >> image;
            images_.push_back(image);
            file.close();

            //images_ = images;
        }
    }

    const vector<Image> &File::getImages() const {
        return images_;
    }

    int File::GetLength() const {
        return length_;
    }

}  // namespace naivebayes
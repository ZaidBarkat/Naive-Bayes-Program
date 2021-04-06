
#include <core/file_processors/image_processor.h>
#include <fstream>
#include <sstream>

namespace naivebayes {

    ImageProcessor::ImageProcessor(const std::string& file_location) {

        std::ifstream file(file_location);
        Image image;
        string line;
        string image_string;

        if (file.is_open()) {
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
        }
    }

    const vector<Image> &ImageProcessor::getImages() const {
        return images_;
    }

    int ImageProcessor::GetLength() const {
        return length_;
    }

}  // namespace naivebayes

#include <fstream>
#include <sstream>
#include <iostream>
#include <core/file_processors/model_processor.h>
#include <core/model.h>

namespace naivebayes {

    ModelProcessor::ModelProcessor(std::string file_location) {
        file_location_ = file_location;
    }

    void ModelProcessor::Write(Model model) {
        std::ofstream file(file_location_);
        if (file.is_open()) {
            file << model;
        }
    }

    Model ModelProcessor::Read() {
        Model model;
        std::ifstream file(file_location_);
        if (file.is_open()) {
            file >> model;
        }
        return model;
    }


}  // namespace naivebayes
#include <string>
#include <vector>
#include <core/model.h>
#include "core/image.h"

namespace naivebayes {

    class ModelProcessor {
    public:
        ModelProcessor(std::string file_location);

        /**
         * Takes in a model and puts it into a file.
         *
         * @param model that is being read
         */
        void Write(Model model);

        /**
         * creates a model based on the given file path
         *
         * @return a new model that is being created
         */
        Model Read();

    private:
        std::string file_location_;
    };
}  // namespace naivebayes


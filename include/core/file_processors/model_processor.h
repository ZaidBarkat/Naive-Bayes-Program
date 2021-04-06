#include <string>
#include <vector>
#include <core/model.h>
#include "core/image.h"

namespace naivebayes {

    class ModelProcessor {
    public:
        ModelProcessor(std::string file_location);

        void Write(Model model);

        Model Read();

    private:
        std::string file_location_;
    };
}  // namespace naivebayes


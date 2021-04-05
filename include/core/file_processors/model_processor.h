#include <string>
#include <vector>
#include "core/image.h"

namespace naivebayes {

    class ModelProcessor {
    public:
        ModelProcessor(std::string file_location);

        Write();

        Read();

    private:
        std::string file_location_;
    };
}  // namespace naivebayes


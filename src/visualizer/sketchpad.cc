#include <visualizer/sketchpad.h>
#include <core/model.h>

namespace naivebayes {

    namespace visualizer {

        using glm::vec2;

        Sketchpad::Sketchpad(const vec2 &top_left_corner, size_t num_pixels_per_side,
                             double sketchpad_size, double brush_radius)
                : top_left_corner_(top_left_corner),
                  num_pixels_per_side_(num_pixels_per_side),
                  pixel_side_length_(sketchpad_size / num_pixels_per_side),
                  brush_radius_(brush_radius) {
            shaded_ = std::vector<std::vector<char>>(num_pixels_per_side_, std::vector<char>(num_pixels_per_side_, ' '));

            model_for_classify_.Train(Image::ImagesFromFile("C:\\Users\\zaids\\Cinder\\my-projects\\naive-bayes-ZaidBarkat\\trainingimagesandlabels.txt"));

        }

        void Sketchpad::Draw() const{
            for (size_t row = 0; row < num_pixels_per_side_; ++row) {
                for (size_t col = 0; col < num_pixels_per_side_; ++col) {

                    if (shaded_[row][col] == '+') {
                        ci::gl::color(ci::Color::gray(0.3f));
                    } else {
                        ci::gl::color(ci::Color("white"));
                    }

                    vec2 pixel_top_left = top_left_corner_ + vec2(col * pixel_side_length_,
                                                                  row * pixel_side_length_);

                    vec2 pixel_bottom_right =
                            pixel_top_left + vec2(pixel_side_length_, pixel_side_length_);
                    ci::Rectf pixel_bounding_box(pixel_top_left, pixel_bottom_right);

                    ci::gl::drawSolidRect(pixel_bounding_box);

                    ci::gl::color(ci::Color("black"));
                    ci::gl::drawStrokedRect(pixel_bounding_box);
                }
            }
        }

        void Sketchpad::HandleBrush(const vec2 &brush_screen_coords) {
            vec2 brush_sketchpad_coords =
                    (brush_screen_coords - top_left_corner_) / (float) pixel_side_length_;

            for (size_t row = 0; row < num_pixels_per_side_; ++row) {
                for (size_t col = 0; col < num_pixels_per_side_; ++col) {
                    vec2 pixel_center = {col + 0.5, row + 0.5};

                    if (glm::distance(brush_sketchpad_coords, pixel_center) <=
                        brush_radius_) {
                        shaded_[row][col] = '+';
                    }
                }
            }
        }

        void Sketchpad::Clear() {
            for (size_t row = 0; row < num_pixels_per_side_; ++row) {
                for (size_t col = 0; col < num_pixels_per_side_; ++col) {
                    shaded_[row][col] = ' ';
                }
                // namespace visualizer

            }
        }


        const Model &Sketchpad::getModel() const {
            return model_for_classify_;
        }

        const vector<std::vector<char>> &Sketchpad::GetShaded() const {
            return shaded_;
        }
    }
}// namespace naivebayes

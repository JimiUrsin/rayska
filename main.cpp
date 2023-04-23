#include <cmath>
#include <fstream>

#include "vec3d.hpp"
#include "writer.hpp"

int main() {
    const int img_width = 256;
    const int img_height = 256;

    const std::string FILENAME = "out.ppm";

    std::ofstream outfile(FILENAME);

    outfile << "P3\n";
    outfile << img_width << " " << img_height << "\n";
    outfile << "255\n";

    for (int y = 0; y < img_height; ++y) {
        for (int x = 0; x < img_width; ++x) {
            color pixel = color {
                (float) x / (img_width - 1),
                (float) y / (img_height - 1),
                0.25
            };

            write_color(outfile, pixel);
        }
    }
}

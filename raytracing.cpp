/* 
 * This tutorial was inspired by the following
 * article describing an introduction to raytracing:
 * https://github.com/ssloy/tinyraytracer/wiki
 *
 */
using namespace std;

#include <limits>
#include <cmath>
#include <iostream>
#include <fstream>
#include <vector>
#include "geometry.h"

void render () {
    const int width    = 1024;
    const int height   = 768;
    /* Vec3f is a 3 dimensional vector that give rgb values for each pixel */
    std::vector<Vec3f> framebuffer(width*height);

    for(size_t j = 0; j < height; j++) {
        for (size_t i = 0; i < width; i++){
           framebuffer[i + j * width] = Vec3f(j/float(height), i/float(width), 0);
        }
    }

    std::ofstream ofs; // save the framebuffer to a file
    ofs.open("./out.ppm");
    ofs << "P6\n" << width << " " << height << "\n255\n";
    for(size_t i = 0; i < height*width; i++) {
        for (size_t j = 0; j < 3; j++) {
            ofs << (char)(255 * std::max(0.f, std::min(1.f, framebuffer[i][j])));
        }
    }
    ofs.close();
}

int main() {
    render();
    return 0;
}
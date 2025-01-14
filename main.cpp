#include <iostream>
#include "C:\mingw64\include\CImg.h"
using namespace cimg_library;

int main() {
    CImg<unsigned char> img("image.jpg");
    int w = img.width();
    int h = img.height();

    // create a window
    CImg<unsigned char> image(w, h, 1, 3);
    CImgDisplay display(image, "Glitch the Image");
    image.fill(0);

    // rgb shift values
    int shiftX[3] = { 0,0,0 };
    int shiftY[3] = { 0,0,0 };

    while (!display.is_closed()) {
        image.fill(0);

        // apply rgb shift
        for (int i = 0; i < w; i++) {
            for (int j = 0; j < h; j++) {
                // rgb channels
                for (int k = 0; k < 3; k++) {
                    if (shiftX[k] > 0) {
                        if (shiftY[k] >= 0 && i > shiftX[k] && j > shiftY[k]) {
                            image(i, j, 0, k) = img(i - shiftX[k], j - shiftY[k], 0, k);
                        }
                        if (shiftY[k] < 0 && i > shiftX[k] && j < h + shiftY[k]) {
                            image(i, j, 0, k) = img(i - shiftX[k], j - shiftY[k], 0, k);
                        }
                    }
                    else {
                        if (shiftY[k] >= 0 && i < w + shiftX[k] && j > shiftY[k]) {
                            image(i, j, 0, k) = img(i - shiftX[k], j - shiftY[k], 0, k);
                        }
                        if (shiftY[k] < 0 && i < w + shiftX[k] && j < h + shiftY[k]) {
                            image(i, j, 0, k) = img(i - shiftX[k], j - shiftY[k], 0, k);
                        }
                    }
                }
            }
        }

        // <-------------key events------------->
        if (display.is_keyARROWUP()) shiftY[0]--;
        if (display.is_keyARROWDOWN()) shiftY[0]++;
        if (display.is_keyARROWLEFT()) shiftX[0]--;
        if (display.is_keyARROWRIGHT()) shiftX[0]++;

        if (display.is_keyI()) shiftY[1]--;
        if (display.is_keyK()) shiftY[1]++;
        if (display.is_keyJ()) shiftX[1]--;
        if (display.is_keyL()) shiftX[1]++;

        if (display.is_keyW()) shiftY[2]--;
        if (display.is_keyS()) shiftY[2]++;
        if (display.is_keyA()) shiftX[2]--;
        if (display.is_keyD()) shiftX[2]++;

        if (display.is_keyESC()) break;

        if (display.is_keyENTER()) {
            image.save("output.jpg");
            std::cout << "Image saved as output.jpg" << std::endl;
        }
        // <-------------key events------------->

        image.display(display);
    }
    return 0;
}
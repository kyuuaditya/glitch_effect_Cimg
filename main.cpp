#include <iostream>
#include "C:\mingw64\include\CImg.h"
using namespace std;
using namespace cimg_library;

int main() {
    CImg<unsigned char> img("image.jpg");
    int w = 735;
    int h = 976;

    CImg<unsigned char> image(w, h, 1, 3);
    CImgDisplay display(image, "Original Image");
    image.fill(0);

    int shiftRx = 0;
    int shiftRy = 0;
    int shiftGx = 0;
    int shiftGy = 0;
    int shiftBx = 0;
    int shiftBy = 0;

    while (!display.is_closed()) {
        image.fill(0);
        for (int i = 0; i < w; i++) {
            for (int j = 0; j < h; j++) {

                // red
                if (shiftRx > 0) {
                    if (shiftRy >= 0 && i > shiftRx && j > shiftRy) {
                        image(i, j, 0, 0) = img(i - shiftRx, j - shiftRy, 0, 0);
                    }
                    if (shiftRy < 0 && i > shiftRx && j < h + shiftRy) {
                        image(i, j, 0, 0) = img(i - shiftRx, j - shiftRy, 0, 0);
                    }
                }
                else {
                    if (shiftRy >= 0 && i < w + shiftRx && j > shiftRy) {
                        image(i, j, 0, 0) = img(i - shiftRx, j - shiftRy, 0, 0);
                    }
                    if (shiftRy < 0 && i < w + shiftRx && j < h + shiftRy) {
                        image(i, j, 0, 0) = img(i - shiftRx, j - shiftRy, 0, 0);
                    }
                }

                // green 
                if (shiftGx > 0) {
                    if (shiftGy >= 0 && i > shiftGx && j > shiftGy) {
                        image(i, j, 0, 1) = img(i - shiftGx, j - shiftGy, 0, 1);
                    }
                    if (shiftGy < 0 && i > shiftGx && j < h + shiftGy) {
                        image(i, j, 0, 1) = img(i - shiftGx, j - shiftGy, 0, 1);
                    }
                }
                else {
                    if (shiftGy >= 0 && i < w + shiftGx && j > shiftGy) {
                        image(i, j, 0, 1) = img(i - shiftGx, j - shiftGy, 0, 1);
                    }
                    if (shiftGy < 0 && i < w + shiftGx && j < h + shiftGy) {
                        image(i, j, 0, 1) = img(i - shiftGx, j - shiftGy, 0, 1);
                    }
                }

                // blue
                if (shiftBx > 0) {
                    if (shiftBy >= 0 && i > shiftBx && j > shiftBy) {
                        image(i, j, 0, 2) = img(i - shiftBx, j - shiftBy, 0, 2);
                    }
                    if (shiftBy < 0 && i > shiftBx && j < h + shiftBy) {
                        image(i, j, 0, 2) = img(i - shiftBx, j - shiftBy, 0, 2);
                    }
                }
                else {
                    if (shiftBy >= 0 && i < w + shiftBx && j > shiftBy) {
                        image(i, j, 0, 2) = img(i - shiftBx, j - shiftBy, 0, 2);
                    }
                    if (shiftBy < 0 && i < w + shiftBx && j < h + shiftBy) {
                        image(i, j, 0, 2) = img(i - shiftBx, j - shiftBy, 0, 2);
                    }
                }
            }
        }

        if (display.is_keyARROWUP()) shiftRy--;
        if (display.is_keyARROWDOWN()) shiftRy++;
        if (display.is_keyARROWLEFT()) shiftRx--;
        if (display.is_keyARROWRIGHT()) shiftRx++;

        if (display.is_keyI()) shiftGy--;
        if (display.is_keyK()) shiftGy++;
        if (display.is_keyJ()) shiftGx--;
        if (display.is_keyL()) shiftGx++;

        if (display.is_keyW()) shiftBy--;
        if (display.is_keyS()) shiftBy++;
        if (display.is_keyA()) shiftBx--;
        if (display.is_keyD()) shiftBx++;

        if (display.is_keyENTER()) {
            image.save("output.jpg");
            cout << "Image saved as output.jpg" << endl;
        }

        if (display.is_keyESC()) break;

        image.display(display);
        // display.wait();
    }
    return 0;
}
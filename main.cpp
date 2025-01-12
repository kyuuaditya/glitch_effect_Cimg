// #include <iostream>
// #include "C:\mingw64\include\CImg.h"
// using namespace std;
// using namespace cimg_library;

// int main() {
//     CImg<unsigned char> img("image.jpg");
//     int w = img.width();
//     int h = img.height();

//     CImg<unsigned int> image(w + 6, h + 6, 1, 3, 0);
//     CImgDisplay display(image, "Original Image");
//     // image.fill(255);



//     for (int i = 0; i < w; i++) {
//         for (int j = 0; j < h; j++) {
//             image(i, j, 0, 0) = img(i, j, 0, 0);
//             image(i + 3, j + 3, 0, 1) = img(i, j, 0, 1);
//             image(i + 6, j + 6, 0, 2) = img(i, j, 0, 2);
//         }
//     }


//     while (!display.is_closed()) {
//         display.wait();
//     }
//     return 0;
// }

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

    int shiftRx = 2;
    int shiftRy = 5;
    int shiftGx = 0;
    int shiftGy = 0;
    int shiftBx = 0;
    int shiftBy = 0;

    while (!display.is_closed()) {
        image.fill(0);
        for (int i = 0; i < w; i++) {
            for (int j = 0; j < h; j++) {
                // image(i, j + shift, 0, 0) = img(i, j, 0, 0);
                image(i, j, 0, 1) = img(i, j, 0, 1);
                image(i, j, 0, 2) = img(i, j, 0, 2);

                if (shiftRx > 0) {
                    if (shiftRy >= 0 && i > shiftRx && j > shiftRy) {
                        image(i, j, 0, 0) = img(i - shiftRx, j - shiftRy, 0, 0);
                    }
                    if (shiftRy < 0 && i > shiftRx && j < h + shiftRy) {
                        image(i, j, 0, 0) = img(i - shiftRx, j - shiftRy, 0, 0);
                    }
                }
            }
        }

        if (display.is_keyARROWUP()) shiftRy--;
        if (display.is_keyARROWDOWN()) shiftRy++;
        if (display.is_keyARROWLEFT()) shiftRx--;
        if (display.is_keyARROWRIGHT()) shiftRx++;
        image.display(display);
        // display.wait();
    }
    return 0;
}
#include "image.h"

#include <iostream>
using namespace std;

// Note: see image.h for documentation on functions.

int pixelToIndex(int width, int x, int y) {
    
    int pixelLoc = x + y*width;
    return pixelLoc*3;

}

void noRed(int width, int height, int* ppm) {
    
    for (int y = 0; y < height; y++) {

        for (int x = 0; x < width; x++) {

            int pixelLoc = pixelToIndex(width, x, y);
            ppm[pixelLoc] = 0;

        }

    }

}

void noGreen(int width, int height, int* ppm) {

    for (int y = 0; y < height; y++) {

        for (int x = 0; x < width; x++) {

            int pixelLoc = pixelToIndex(width, x, y);
            ppm[pixelLoc+1] = 0;

        }

    }

}

void noBlue(int width, int height, int* ppm) {

    for (int y = 0; y < height; y++) {

        for (int x = 0; x < width; x++) {

            int pixelLoc = pixelToIndex(width, x, y);
            ppm[pixelLoc+2] = 0;

        }

    }

}

void invert(int width, int height, int* ppm) {

    for (int y = 0; y < height; y++) {

        for (int x = 0; x < width; x++) {

            int pixelLoc = pixelToIndex(width, x, y);
            ppm[pixelLoc] = 255 - ppm[pixelLoc];
            ppm[pixelLoc+1] = 255 - ppm[pixelLoc+1];
            ppm[pixelLoc+2] = 255 - ppm[pixelLoc+2];

        }

    }

}

void grayscale(int width, int height, int* ppm) {

    for (int y = 0; y < height; y++) {

        for (int x = 0; x < width; x++) {

            int pixelLoc = pixelToIndex(width, x, y);
            int average = (ppm[pixelLoc] + ppm[pixelLoc+1] + ppm[pixelLoc+2])/3;
            ppm[pixelLoc] = average;
            ppm[pixelLoc+1] = average;
            ppm[pixelLoc+2] = average;

        }

    }

}

void flipHorizontally(int width, int height, int* ppm) {

    int ppm_length = width*height*3;
    int *modified_ppm = new int[width*height*3];

    for (int y = 0; y < height; y++) {

        for (int x = 0; x < width; x++) {

            int pixelLoc = pixelToIndex(width, x, y);
            modified_ppm[(y)*(width)*3 + (width-x-1)*3] = ppm[pixelLoc];
            modified_ppm[(y)*(width)*3 + (width-x-1)*3+1] = ppm[pixelLoc+1];
            modified_ppm[(y)*(width)*3 + (width-x-1)*3+2] = ppm[pixelLoc+2];

        }

    }

    for (int i = 0; i < ppm_length; i++) {
        ppm[i] = modified_ppm[i];
    }

    delete [] modified_ppm;

}

void flipVertically(int width, int height, int* ppm) {

    int ppm_length = width*height*3;
    int *modified_ppm = new int[width*height*3];

    for (int y = 0; y < height; y++) {

        for (int x = 0; x < width; x++) {

            int pixelLoc = pixelToIndex(width, x, y);
            modified_ppm[x*3 + (height-y-1)*3*width] = ppm[pixelLoc];
            modified_ppm[x*3 + (height-y-1)*3*width+1] = ppm[pixelLoc+1];
            modified_ppm[x*3 + (height-y-1)*3*width+2] = ppm[pixelLoc+2];

        }

    }

    for (int i = 0; i < ppm_length; i++) {
        ppm[i] = modified_ppm[i];
    }

    delete [] modified_ppm;

}

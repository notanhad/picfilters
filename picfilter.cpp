#include <iostream>
#include <string>

#include "image.h"
#include "ppmio.h"

using namespace std;

int main(int argc, char** argv) {

    if (argc != 4) {
        cout << "Error: Invalid commandline usage" << endl << "Usage: ./picfilter old.ppm transformation new.ppm" << endl;
        return 1;
    }

    string oldImage = argv[1];
    string transformation = argv[2];
    string newImage = argv[3];

    int imageWidth = ppm_width(oldImage);
    int imageHeight = ppm_height(oldImage);
    int *ppm = read_ppm(oldImage);

    cout << pixelToIndex(3,2,1) << endl;

    if (transformation == "noRed") {
        noRed(imageWidth, imageHeight, ppm);
    } else if (transformation == "noGreen") {
        noGreen(imageWidth, imageHeight, ppm);
    } else if (transformation == "noBlue") {
        noBlue(imageWidth, imageHeight, ppm);
    } else if (transformation == "invert") {
        invert(imageWidth, imageHeight, ppm);
    } else if (transformation == "grayscale") {
        grayscale(imageWidth, imageHeight, ppm);
    } else if (transformation == "flipHorizontally") {
        flipHorizontally(imageWidth, imageHeight, ppm);
    } else if (transformation == "flipVertically") {
        flipVertically(imageWidth, imageHeight, ppm);
    } else {
        cout << "Error: Invalid transformation. Valid arguments: noRed, noGreen, noBlue, invert, grayscale, flipHorizontally, flipVertically" << endl;
        return 1;
    }

    write_ppm(newImage, imageWidth, imageHeight, ppm);

    delete [] ppm;

    return 0;

}

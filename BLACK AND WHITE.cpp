#include <iostream>
using namespace std;
#include "Image_Class.h"

int main() {
    string filename;
    cout << "Pls enter colored image name to turn to black and white: ";
    cin >> filename;

    // Create an Image object using the provided filename
    Image image(filename);

    // Loop through each pixel in the image
    for (int i = 0; i < image.width; ++i) {
        for (int j = 0; j < image.height; ++j) {
            unsigned int avg = 0; // Initialize average value

            // Calculate the average pixel value by summing the RGB channels
            for (int k = 0; k < 3; ++k) {
                avg += image(i, j, k); // Accumulate pixel values
            }

            avg /= 3; // Calculate average

            // Convert the pixel to black or white based on the average intensity
            if (avg > 128) {
                avg = 255; // Set pixel to white
            } else {
                avg = 0; // Set pixel to black
            }  

            // Set all channels of the pixel to the average value
            image(i, j, 0) = avg;
            image(i, j, 1) = avg;
            image(i, j, 2) = avg;
        }
    }

    // Ask for a filename to store the modified image
    cout << "Pls enter image name to store new image\n";
    cout << "and specify extension .jpg, .bmp, .png, .tga: ";

    cin >> filename;

    // Save the modified image with the specified filename
    image.saveImage(filename);

    return 0;
}

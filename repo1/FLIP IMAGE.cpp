#include <iostream>
#include <string>
#include "Image_Class.h"

using namespace std;

int main() {
    string NameFile;
    cout << "Please Enter Image Name: ";
    cin >> NameFile;

    // Load the original image
    Image Photo(NameFile);

    // Get the width and height of the original image
    int Photo_Width = Photo.width;
    int Photo_Height = Photo.height;

    int choose;
    cout << "Do You Want Flip The Image Horizontally Or Vertical? : " << endl;
    cout << "1) Horizontally" << endl;
    cout << "2) Vertical" << endl;
    cout << "Enter your choice (1 or 2): ";
    cin >> choose; // Prompt the user to input their choice

    // Horizontal flip
    if (choose == 1) {
        for (int i = 0; i < Photo_Height; i++) {
            for (int j = 0; j < Photo_Width / 2; j++) {
                // Swap pixels horizontally
                for (int k = 0; k < 3; k++) { // Assuming RGB channels
                    int Flipped_Image = Photo(j, i, k);
                    Photo(j, i, k) = Photo(Photo_Width - 1 - j, i, k);
                    Photo(Photo_Width - 1 - j, i, k) = Flipped_Image;
                }
            }
        }
    }
    // Vertical flip
    else if (choose == 2) {
        for (int i = 0; i < Photo_Height / 2; i++) {
            for (int j = 0; j < Photo_Width; j++) {
                // Swap pixels vertically
                for (int k = 0; k < 3; k++) { // Assuming RGB channels
                    int Flipped_Image = Photo(j, i, k);
                    Photo(j, i, k) = Photo(j, Photo_Height - 1 - i, k);
                    Photo(j, Photo_Height - 1 - i, k) = Flipped_Image;
                }
            }
        }
    }

    // Prompt the user to enter the file name to save the flipped image
    cout << "Please Enter The New Flipped Image File Name: " << endl;
    cout << "And Specify Extension .jpg, .bmp, .png, .tga: ";
    cin >> NameFile;

    // Save the flipped image
    Photo.saveImage(NameFile);
    cout << "The New Flipped Image Saved Successfully." << endl;
    return 0;
}
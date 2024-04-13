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

  // Variables to store the cropping dimensions
  int old_Width, old_height;
  int new_Width, new_height;

  // Prompt the user to input the cropping dimensions
  cout << "Please Enter The Points You Want To Crop From it" << endl;
  cout << "Enter The Height: ";
  cin >> old_height;
  cout << "Enter The Width: ";
  cin >> old_Width;

  // Validate the cropping dimensions
  if (old_Width <= 0, old_height <= 0, old_Width > Photo_Width, old_height > Photo_Height) {
    cout << "Invalid Input, Please Try Again: " << endl;
  }

  // Prompt the user to input the dimensions of the cropped image
  cout << "Please Enter The Crop Image Dimensions" << endl;
  cout << "Enter The New Height: ";
  cin >> new_height;
  cout << "Enter The New Width: ";
  cin >> new_Width;

  // Validate the dimensions of the cropped image
  if (new_Width <= 0, new_height <= 0, new_Width > new_height, old_height > Photo_Height) {
    cout << "Invalid Input, Please Try Again: " << endl;
  }

  // Create a new image object for the cropped image
  Image croppedImage(new_Width, new_height);

  // Copy pixels from the original image to the cropped image
  for (int i = 0; i < new_Width; ++i) {
    for (int j = 0; j < new_height; ++j) {
      // Copy pixel values from the specified area of the original image to the cropped image
      croppedImage(i, j, 0) = Photo(old_Width + i, old_height + j, 0);
      croppedImage(i, j, 1) = Photo(old_Width + i, old_height + j, 1);
      croppedImage(i, j, 2) = Photo(old_Width + i, old_height + j, 2);
    }
  }

  // Prompt the user to enter the file name to save the cropped image
  cout << "Please Enter The New Flipped Image File Name: " << endl;
  cout << "And Specify Extension .jpg, .bmp, .png, .tga: ";
  cin >> NameFile;
  // Save the cropped image
  croppedImage.saveImage(NameFile);
  cout << "The Cropped Image Saved Successfully." << endl;

  return 0;
}

#include <iostream>     
#include "Image_Class.h" 
using namespace std;   




int main() {
  string FileName; // Declaring a string variable to store the file name

  // Asking the user to enter the name of the image file
  cout << "Please Enter The Image You Want To Add Natural Sunlight: ";
  cin >> FileName; // Reading the input image file name from the user

  // Creating an Image object called photo using the provided image file name
  Image photo(FileName);

  // Looping through each pixel in the image
  for (int i = 0; i < photo.width; ++i)
    {
      for (int j = 0; j < photo.height; ++j)
      {
          photo(i, j, 2) = photo(i, j, 2);
          photo(i, j, 2) = photo(i, j, 2) * 0.74;
          photo(i, j, 2) = photo(i, j, 2);
      }
    }
                              
  // Asking the user to enter the file name for the new image
  cout << "Please Enter The New Image File Name: " << endl;
  cout << "And Specify Extension .jpg, .bmp, .png, .tga: ";
  cin >> FileName; // Reading the new image file name from the user

  // Saving the modified image with the new file name
  photo.saveImage(FileName);
  
  // Informing the user that the image has been saved successfully
  cout << "The Image Saved Successfully." << endl;

  return 0; // Returning 0 to indicate successful execution
}

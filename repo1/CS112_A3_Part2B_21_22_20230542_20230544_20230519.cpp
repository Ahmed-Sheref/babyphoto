// Purpose: 
/*
  This program implements various image processing functions.
*/
//                                                                                    -------------------------------------------------------------
// Author1: Ahmed Sheref Sayed  ID:20230542  Email:ahmedsheref2288@yahoo.com S21,S22  | (valid_input),(print_message),                            |
//                                                                                    | (Grayscale_Conversion),(merge_image),                     |
//                                                                                    | (Darken_and_light), (Detect_Image_Edges) , (Purple_lffy)  |
//                                                                                    -------------------------------------------------------------

//                                                                                    -------------------------------------------------------------
// Author2: Youssef Yasser El-sayed ID:20230542 Email:yoyoyasso19@gmail.com S21,S22   | (Rotate_Image),(Invert_Image),                            |
//                                                                                    | (imageBlur),(infrared_filter),                            |
//                                                                                    | (createFrame)                                             |
//                                                                                    -------------------------------------------------------------

//                                                                                    -------------------------------------------------------------
// Author3: Hassan Walid Hassan ID:20230544 Email:hassan.moselhy22@gmail.com S21,S22  | (resize_photo),(Crop_image),                              |
//                                                                                    | (Flip_image),(Sun_Light_Image),                           |
//                                                                                    | (black_white)                                             |
//                                                                                    -------------------------------------------------------------
// Version: 1.0
// Date: 13.April 2024


#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include "Image_Class.h" // Include the header file for the Image class
#include "string" 

using namespace std;



// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> part of ahmed sheref <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
string IF_FILE_EXISTS (string namefile);
string valid_input(string input);
void pirnt_message();
void Grayscale_Conversion ();
void merge_image();
void Darken_and_light ();
void Detect_Image_Edges();
void Purple_lffy();
void save_image (string &filename , Image &image); // Ask the user if he wants to save the image or not 
// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> end part of ahmed sheref <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> part of Youssef Yasser <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
void Rotate_Image();
void Invert_Image();
void imageBlur(Image &image); void Main_Image_blur();
void infrared_filter();
void createFrame();
// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> end part of Youssef Yasser <<<<<<<<<<<<<<<<<<<<<<<<<<<<

// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> part of Hassan Walid <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<  
void resize_photo(); 
void Crop_image();
void Flip_image();
void Sun_Light_Image();
void black_white();
// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> end part of Hassan Walid <<<<<<<<<<<<<<<<<<<<<<<<<<<<<< 



string Main_name;
string original_photo;
string edited_photo;
Image Main_image;
int main ()
{
  cout << "\nPlease Enter Image_name: ";
  cin >> Main_name;
  cin.ignore();
  Main_name = IF_FILE_EXISTS(Main_name);
  original_photo = Main_name;
  Image Main_image(Main_name);
  while (true)
  {
    cout << "╔════════════════════════════════════════╗\n";
    cout << "║              \033[7;31m R \033[0m ";    // Red
    cout << "\033[7;32m G \033[0m ";                   // Green
    cout << "\033[7;34m B \033[0m               ║\n";  // Blue
    cout << "║  We have 6 methods of photoshop.       ║\n";
    cout << "║  Choose one of the following options:  ║\n";
    cout << "║  1. Grayscale_Conversion_Image         ║\n";
    cout << "║  2. merge_image                        ║\n";
    cout << "║  3. Darken_and_light_Image             ║\n";
    cout << "║  4. Detect_Edges_Image                 ║\n";
    cout << "║  5. Purple_lffy_image                  ║\n";
    cout << "║  6. Rotate_Image                       ║\n";
    cout << "║  7. Invert_Image                       ║\n";
    cout << "║  8. Blur_Image                         ║\n";
    cout << "║  9. infrared_filter                    ║\n";
    cout << "║  10. createFrame                       ║\n";
    cout << "║  11. resize_Image                      ║\n";
    cout << "║  12. Crop_Image                        ║\n";
    cout << "║  13. Flip_Image                        ║\n";
    cout << "║  14. Sun_Light_Image                   ║\n";
    cout << "║  15. black_white_Image                 ║\n";
    cout << "║  16. Exit                              ║\n";
    cout << "╚════════════════════════════════════════╝\n\n";

    string test_choose;
    cout << "--> ";
    getline(cin , test_choose); // Read user choice
    int number_choose = stoi(valid_input(test_choose)); // Convert user choice to integer

    // Validate user choice
    vector <int> menu = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};
    int found = count(menu.begin(),menu.end(),number_choose);
    while (!found)
    {
      cout << "Enter your choice (1-16): ";
      cin >> test_choose; // Read user choice again
      number_choose = stoi(valid_input(test_choose)); // Convert user choice to integer
      found = count(menu.begin(),menu.end(),number_choose);
    }

    switch (number_choose)
    {
      case 1:
        Grayscale_Conversion(); // Call grayscale conversion function
        break;
      case 2:
        merge_image(); // Call merge image function
        break;
      case 3:
        Darken_and_light(); // Call rotate image function
        break;
      case 4:
        Detect_Image_Edges(); // Call invert image function
        break;
      case 5:
        Purple_lffy(); // Call resize image function
        break;
      case 6:
        Rotate_Image();
        break;
      case 7:
        Invert_Image();
        break;
      case 8:
        Main_Image_blur();
        break;
      case 9:
        infrared_filter();
        break;
      case 10:
        createFrame();
        break;
      case 11:
        resize_photo();
        break;
      case 12:
        Crop_image();
        break;
      case 13:
        Flip_image();
        break;
      case 14:
        Sun_Light_Image();
        break;
      case 15:
        black_white();
        break;
      case 16:
        cout << "Exit...\n";
        return 0;
    }

    // Prompt the user if they want to continue editing pictures
    cout << "\n----------------------------------------------\n";
    cout << "\nDo you want to continue editing which pictures?\n";
    cout << "  1. original image\n";
    cout << "  2. edited image\n";
    cout << "  3. change image\n";
    cout << "  4. Exit Programming\n";
    cout << "\n----------------------------------------------\n";

    // Read user choice
    string test_Try_again;
    cin >> test_Try_again;
    cin.ignore();
    int number_Try_again = stoi(valid_input(test_Try_again)); // Convert user choice to integer

    // Validate user choice
    while (number_Try_again != 1 && number_Try_again != 2 && number_Try_again != 3 && number_Try_again != 4)
    {
      cout << "Enter your choice (1-4): ";
      cin >> test_Try_again; // Read user choice again
      number_Try_again = stoi(valid_input(test_Try_again)); // Convert user choice to integer
    }

    // Execute the selected action based on the user's choice
    switch (number_Try_again)
    {
    case 1:
      Main_name = original_photo;
      break; // Continue with the loop
    case 2:
      Main_name = edited_photo;
      break; // Continue with the loop
    case 3:
      cout << "Change Image __ Enter New name Image: ";
      cin >> Main_name;
      cin.ignore();
      Main_name = IF_FILE_EXISTS(Main_name);
      break; // Continue with the loop
    case 4:
      cout << "\033[3;31m  Exit... \033[0m" << endl; // Inform about program exit
      return 0; // Exit the program
    }
  }
  return 0;
}

// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> part of ahmed sheref <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
void save_image (string &filename , Image &image)
{
  string test_save;
  // cin.ignore(); // Ignore any remaining characters in the input buffer
  cout << "\n-----------------------\n\n";
  cout << "1) Save to the new image\n";
  cout << "2) Not save\n";
  cout << "\n-----------------------\n";
  getline(cin, test_save); // Read user choice
  int number_save = stoi(valid_input(test_save)); // Convert user choice to integer

  // Validate user choice
  while (number_save != 1 && number_save != 2)
  {
    cout << "Enter your choice (1-2): ";
    cin >> test_save; // Read user choice again
    cin.ignore(); // Ignore any remaining characters in the input buffer
    number_save = stoi(valid_input(test_save)); // Convert user choice to integer
  }

  switch (number_save)
  {
  case 1:
    cout << "Pls enter image name to store new image\n";
    cout << "and specify extension .jpg, .bmp, .png, .tga: ";
    cin >> filename; // Read filename from user
    image.saveImage(filename); // Save image with the specified filename
    edited_photo = filename;
    cout << "Saved successfully\n";
    break;
  case 2:
    break; // Do not save the image
  }
}

string IF_FILE_EXISTS (string namefile)
{
  while (true) // Loop until a valid file is found
  {
    ifstream file; // Declare input file stream
    file.open(namefile); // Attempt to open the file with the given name
    if (!file) // If the file does not exist or cannot be opened
    {
      cout << "Please check the file format or the file does not exist\n"; // Inform the user about the issue
      cin >> namefile; // Prompt the user to enter a new file name
      cin.ignore();
    }
    else // If the file exists and can be opened
    {
      break; // Exit the loop
    }
  }
  return namefile; // Return the valid file name
}


// Function to validate user input
string valid_input(string input)
{
  string Chek_input = input;
  // Loop through each character in the input
  for (auto ch : Chek_input)
  {
    // Check if the character is not a digit
    if (!isdigit(ch))
    {
      cout << "Please enter a valid number\n"; // Prompt the user to enter a valid number
      cin >> Chek_input; // Read the input again
      return valid_input(Chek_input); // Recursively call the function to validate the new input
    }
  }
  return Chek_input; // Return the validated input
}

void pirnt_message()
{
  cout << "\033[5;31m R \033[0m"; // Print 'R' in red
  cout << "\033[5;32m G \033[0m"; // Print 'G' in green
  cout << "\033[5;34m B \033[0m"; // Print 'B' in blue
  cout << " <<<<<<<<<<<<";
  cout << endl;
}

// Function for grayscale conversion
void Grayscale_Conversion()
{
  cout << "Welcome to Grayscale_Conversion programming :\n>>>>>>>>> ";
  pirnt_message();
  Image photo(Main_name); // Load the photo from the provided photoname

  for (int i = 0; i < photo.width; ++i)
    {
      for (int j = 0; j < photo.height; ++j)
      {
        int middle = 0; // Initialize average value

        // Calculate average pixel value
        for (int k = 0; k < 3; ++k)
        {
            middle += photo(i, j, k); // Accumulate pixel values
        }

        middle /= 3; // Calculate average

        // Set all channels to the average value
        photo(i, j, 0) = middle;
        photo(i, j, 1) = middle;
        photo(i, j, 2) = middle;
      }
    }
    string test_name;
    save_image(test_name, photo); // Save the modified image
}

// Function to print message


// Function to merge images
void merge_image()
{
  cout << "Welcome to merge_image programming :\n>>>>>>>>> ";
  pirnt_message(); // Print message
  string  photoname2;
  cout << "Pls enter colored image_1 name : ";
  cout << "Pls enter colored image_2 name : ";
  cin >> photoname2;
  photoname2 = IF_FILE_EXISTS(photoname2);

  Image image(Main_name);
  Image image2(photoname2);
  Image image3;

  // Determine the size of the resulting image
  if ((image.width * image.height) < image2.width * image2.height)
  {
    image3.loadNewImage(Main_name);
  }
  else
  {
    image3.loadNewImage(photoname2);
  }

  // Merge the images
  for (int i = 0; i < image3.width; ++i) 
  {
  // Loop through each column of the image
  for (int j = 0; j < image3.height; ++j)
  {
    // Loop through each row of the image
    for (int k = 0; k < image3.channels; ++k) 
    {
        // Loop through each channel (e.g., Red, Green, Blue)
        int pixel_value = 0;
        
        // Compute the pixel value for the current pixel in image3
        // by blending corresponding pixels from image and image2
        pixel_value += image(i, j, k) * 0.7; // Blend pixel from image
        pixel_value += image2(i, j, k) * 0.7; // Blend pixel from image2
        
        // Ensure the pixel value is within the range [0, 255]
        image3(i, j, k) = min(pixel_value, 255);
    }
  }
}

  string file_name3;
  cin.ignore();
  save_image(file_name3, image3); // Save the merged image
}

void Darken_and_light ()
{
  cout << "Welcome to Darken_and_light programming :\n>>>>>>>>> ";
  pirnt_message(); // Print message
  int choose_persnteg;
  cout << "\n1) 50 % -> dark\n2) 50 % -> light\n";
  cin >> choose_persnteg;
  Image image(Main_name);

  int new_pixel = 0;
  // Merge the images
  for (int i = 0; i < image.width; ++i) 
  {
  // Loop through each column of the image
    for (int j = 0; j < image.height; ++j)
    {
      new_pixel = 0;
      switch(choose_persnteg)
      {
        case 1:
          for (int k = 0; k < image.channels; ++k) 
          {
            new_pixel = image(i, j, k) * 0.5;
            image(i, j, k) = min(new_pixel,255);
          }
        break;
        case 2:
          for (int k = 0; k < image.channels; ++k) 
          {
            new_pixel = image(i, j, k) * 1.5;
            image(i, j, k) = min(new_pixel,255);
          }
        break;
      }
    }
  }
  string file_name;
  cin.ignore();
  save_image(file_name,image);
}

void Detect_Image_Edges() 
{
  cout << "Welcome to Detect Image Edges programming :\n>>>>>>>>> ";
  pirnt_message(); // Print message

  // Load the photo from the provided photoname
  Image photo(Main_name);

  // Define horizontal and vertical edge detection kernels
  int HR[3][3] = 
  {
    {-1, 0, 1},
    {-2, 0, 2},
    {-1, 0, 1}
  };
  int Vr[3][3] = 
  {
    {1, 2, 1},
    {0, 0, 0},
    {-1, -2, -1}
  };

  // Initialize variables to store image dimensions
  long long int height = photo.height;
  long long int width = photo.width;

  // Initialize arrays to store gradient magnitudes
  long long int IX[height - 2][width - 2];
  long long int IY[height - 2][width - 2];
  long long int IXY[height - 2][width - 2];
  long long int sum_IX = 0;
  long long int sum_IY = 0;
  long long int pixell = 0;
  long long int sum_IXY = 0;

  // Compute gradient magnitudes using Sobel operator
  for (long long int i = 0; i < photo.width - 2; i++) 
  {
    for (long long int j = 0; j < photo.height - 2; j++) 
    {
      sum_IX = 0;
      sum_IY = 0;
      pixell = 0;
      for (long long int k = 0; k < 3; k++) 
      {
        for (long long int n = 0; n < 3; n++) 
        {
          pixell = 0;
          // Compute grayscale intensity using weighted sum of RGB channels
          pixell += photo(i + k, j + n, 0) * 0.299;
          pixell += photo(i + k, j + n, 1) * 0.587;
          pixell += photo(i + k, j + n, 2) * 0.114;
          sum_IX += HR[k][n] * pixell; // Compute horizontal gradient
          sum_IY += Vr[k][n] * pixell; // Compute vertical gradient
        }
      }
      IX[i][j] = sum_IX;
      IY[i][j] = sum_IY;
    }
  }

  // Compute gradient magnitude magnitude and average
  for (long long int i = 0; i < photo.width - 2; i++) 
  {
    for (long long int j = 0; j < photo.height - 2; j++) 
    {
      IXY[i][j] = sqrt(pow(IX[i][j], 2) + pow(IY[i][j], 2)); // Compute gradient magnitude
      sum_IXY += IXY[i][j]; // Accumulate gradient magnitudes
    }
  }
  long long int avr_IXY = sum_IXY / ((height - 2) * (width - 2)); // Compute average gradient magnitude

  // Threshold gradient magnitudes to generate edge map
  for (long long int i = 0; i < photo.width - 2; i++) 
  {
    for (long long int j = 0; j < photo.height - 2; j++) 
    {
      IXY[i][j] = (IXY[i][j] > avr_IXY ? 0 : 255); // Apply thresholding
    }
  }

  // Update image with edge map
  for (long long int i = 0; i < photo.width - 2; i++) 
  {
    for (long long int j = 0; j < photo.height - 2; j++) 
    {
      photo(i, j, 0) = IXY[i][j];
      photo(i, j, 1) = IXY[i][j];
      photo(i, j, 2) = IXY[i][j];
    }
  }

  // Save the modified image
  string file_name;
  save_image(file_name, photo);
}


void Purple_lffy ()
{
  cout << "Welcome to Purple_lffy programming :\n>>>>>>>>> ";
  pirnt_message(); // Print message
  // string photoname;
  // cout << "Pls enter colored image name: ";
  // cin >> photoname; // Read user input for image name
  // photoname = IF_FILE_EXISTS(photoname);
  Image photo(Main_name); // Load the photo from the provided photoname

  for (int i = 0; i < photo.width; ++i)
    {
      for (int j = 0; j < photo.height; ++j)
      {
          photo(i, j, 0) = photo(i, j, 0);
          photo(i, j, 1) = photo(i, j, 1) * 0.65;
          photo(i, j, 2) = photo(i, j, 2);
      }
    }
    string photoname;
    save_image(photoname, photo); // Save the modified image
}
// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> end part of ahmed sheref <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> part of youssef yasser  <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
// Function to rotate an image
void Rotate_Image()
{
  cout << "Welcome to Rotate_Image programming :\n>>>>>>>>> ";
  pirnt_message(); // Print message

  Image image(Main_name);

  // Prompt user to enter the angle for rotation
  cout << "Please enter the angle you want to rotate the image from: ";
  string angle;
  cin >> angle;

  // Validate the angle input
  while (stoi(angle) != 90 && stoi(angle) != 180 && stoi(angle) != 270)
  {
      cout << "Invalid input. Please enter the angle (90, 180, 270): ";
      cin >> angle;
  }

  // Create a new image object to store the rotated image
  Image Rotate(image.height, image.width);

  // Perform rotation based on the input angle
  if (stoi(angle) == 90)
  {
    for (int i = 0; i < image.width; ++i)
    {
        for (int j = 0; j < image.height; ++j)
        {
            Rotate(j, image.width - i - 1, 0) = image(i, j, 0);
            Rotate(j, image.width - i - 1, 1) = image(i, j, 1);
            Rotate(j, image.width - i - 1, 2) = image(i, j, 2);
        }
    }
  }
  else if (stoi(angle) == 180)
  {
    for (int i = 0; i < image.width; ++i)
    {
        for (int j = 0; j < image.height; ++j)
        {
            Rotate(image.height - j - 1, image.width - i - 1, 0) = image(i, j, 0);
            Rotate(image.height - j - 1, image.width - i - 1, 1) = image(i, j, 1);
            Rotate(image.height - j - 1, image.width - i - 1, 2) = image(i, j, 2);
        }
    }
  }
  else if (stoi(angle) == 270)
  {
    for (int i = 0; i < image.width; ++i)
    {
        for (int j = 0; j < image.height; ++j)
        {
            Rotate(image.height - j - 1, i, 0) = image(i, j, 0);
            Rotate(image.height - j - 1, i, 1) = image(i, j, 1);
            Rotate(image.height - j - 1, i, 2) = image(i, j, 2);
        }
    }
  }
    cin.ignore();
    string filename;
    save_image(filename, Rotate); // Save the rotated image
}

// Function to invert an image
void Invert_Image()
{

  Image image(Main_name);

  // Invert each pixel in the image
  for (int i = 0; i < image.width; ++i)
  {
      for (int j = 0; j < image.height; ++j)
      {
          int avg = 0;
          for (int k = 0; k < 3; ++k)
          {
              image(i, j, k) = 255 - image(i, j, k);
          }
      }
  }
  string filename;
  // cin.ignore();
  save_image(filename, image); // Save the inverted image
}

void createFrame() {

    Image image(Main_name);
    char frameType;
    int frameColor, frameRed = 0, frameGreen = 0, frameBlue = 0;

    cout << "1) Simple frame\n";
    cout << "2) Fancy frame\n";
    cout << "Please select the type of frame: ";
    cin >> frameType;

    cout << "1) blue\n";
    cout << "2) Red\n";
    cout << "3) green\n";
    cout << "Please select the color for the frame: ";
    cin >> frameColor;


    frameBlue = (frameColor == 1) ? 225 : 0;
    frameRed = (frameColor == 2) ? 225 : 0;
    frameGreen = (frameColor == 3) ? 225 : 0;
    

    for (int i = 0; i < image.width; ++i) {
        for (int j = 0; j < image.height; ++j) {
            bool isFrame = (i <= image.width / 50) || (j <= image.height / 40) || (i >= image.width - image.width / 50) || (j >= image.height - image.height / 40);
            bool isInnerFrame = (i <= image.width / 80) || (j <= image.height / 80) || (i >= image.width - image.width / 80) || (j >= image.height - image.height / 80);
            bool isFancyFrame = (i <= image.width / 30 || i >= image.width - image.width / 30) && (j <= image.height / 20 || j >= image.height - image.height / 20);

            if (frameType == '1') {
                if (isFrame) {
                    image(i, j, 0) = frameRed;
                    image(i, j, 1) = frameGreen;
                    image(i, j, 2) = frameBlue;
                }
                if (isInnerFrame) {
                    image(i, j, 0) = 225;
                    image(i, j, 1) = 225;
                    image(i, j, 2) = 225;
                }
            } else if (frameType == '2') {
                if (isFrame) {
                    image(i, j, 0) = frameRed;
                    image(i, j, 1) = frameGreen;
                    image(i, j, 2) = frameBlue;
                }
                if (isInnerFrame) {
                    image(i, j, 0) = 30;
                    image(i, j, 1) = 30;
                    image(i, j, 2) = 30;
                }
                if (isFancyFrame) {
                    image(i, j, 0) = 50;
                    image(i, j, 1) = 0;
                    image(i, j, 2) = 225;
                }
            }
        }
    }

    string filename;
    cin.ignore();
    save_image(filename,image);
}

void infrared_filter()
{

    Image image(Main_name);

    for (int i = 0; i < image.width; ++i) {
        for (int j = 0; j < image.height; ++j) {
            // Calculate the brightness of the pixel
            unsigned int brightness = (image(i, j, 0) + image(i, j, 1) + image(i, j, 2)) / 3;

            // Determine whether the pixel is bright or dark
            if (brightness > 128) {
                // Bright pixels become a mix of shiny white and slightly decreased red
                unsigned int redIntensity = brightness + 99; // Adjust the boost factor as needed
                unsigned int whiteIntensity = 255 - brightness;
                // Ensure redIntensity doesn't exceed 255
                if (redIntensity > 255) redIntensity = 255;
                // Set the pixel color to shiny white-red
                image(i, j, 0) = redIntensity; // Red
                image(i, j, 1) = whiteIntensity; // Green (to mix with red)
                image(i, j, 2) = whiteIntensity; // Blue (to mix with red)
            } else {
                // Dark pixels become closer to white
                // Increase the intensity of all color channels
                unsigned int intensity = 255 - brightness;
                // Adjust the intensity to make dark parts closer to white
                intensity = 255 - intensity; // Make dark pixels closest to white
                image(i, j, 0) = 255 - intensity; // Red
                image(i, j, 1) = 255 - intensity; // Green
                image(i, j, 2) = 255 - intensity; // Blue
            }
        }
    }
    
    string filename;
    save_image(filename,image);
}

void imageBlur(Image &image) {
    int width = image.width;
    int height = image.height;

    // Create a temporary image to store the blurred result
    Image blurredImage(width, height);

    // Apply box blur
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            // Initialize sum for each channel
            int sumR = 0, sumG = 0, sumB = 0;

            // Loop through the surrounding pixels (11x11 matrix)
            for (int j = -10; j <= 10; ++j) {
                for (int i = -10; i <= 10; ++i) {
                    // Calculate the coordinates of the surrounding pixel
                    int neighborX = x + i;
                    int neighborY = y + j;

                    // Check if the surrounding pixel is within the image boundaries
                    if (neighborX >= 0 && neighborX < width && neighborY >= 0 && neighborY < height) {
                        // Accumulate the color values
                        sumR += image(neighborX, neighborY, 0);
                        sumG += image(neighborX, neighborY, 1);
                        sumB += image(neighborX, neighborY, 2);
                    }
                }
            }

            // Calculate the average color values
            int avgR = sumR / 441;
            int avgG = sumG / 441;
            int avgB = sumB / 441;

            // Set the new pixel value in the blurred image
            blurredImage(x, y, 0) = avgR;
            blurredImage(x, y, 1) = avgG;
            blurredImage(x, y, 2) = avgB;
        }
    }

    // Copy the blurred image back to the original image
    for (int i = 0; i < width * height * 3; ++i) {
        image.imageData[i] = blurredImage.imageData[i];
    }
}

void Main_Image_blur()
{
    // string filename;
    // cout << "Please enter the colored image name: ";
    // cin >> filename;

    Image image(Main_name);
    imageBlur(image);

    
    string filename;
    cin.ignore();
    save_image(filename,image);
}
// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> end part of youssef yasser <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>  part of hassan walid  <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
// Function to resize an image
void resize_photo()
{
  string photo;

  Image image(Main_name);

  int newWidth, newHeight;
  while(true)
  {
    cout << "Please enter the new width for the image: ";
    cin >> newWidth;
    cout << "Please enter the new height for the image: ";
    cin >> newHeight;
    if (newWidth >= 1 && newHeight >= 1){
    break;
    }
    else
    cout << "Invalid Input, Try Again: \n";
  }

  Image resizedImage(newWidth, newHeight);
  // Resize the image
  for (int i = 0; i < newWidth; ++i) 
  {
    for (int j = 0; j < newHeight; ++j) 
    {
      int original_i = (i * image.width) / newWidth;
      int original_j = (j * image.height) / newHeight;

      // Copy pixel values from the original image to the resized image
      for (int k = 0; k < image.channels; ++k) 
      {
        resizedImage(i, j, k) = image(original_i, original_j, k);
      }
    }
  }
  cin.ignore();
  save_image(photo,resizedImage);
}


void Crop_image()
{
  // Load the original image
  Image Photo(Main_name);

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
  string NameFile;
  // Save the cropped image
  cin.ignore();
  save_image(NameFile,croppedImage);
  cout << "The Cropped Image Saved Successfully." << endl;
}

void Flip_image()
{
    Image Photo(Main_name);

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
    string NameFile;
    // Save the flipped image
    cin.ignore();
    save_image(NameFile,Photo);
    cout << "The New Flipped Image Saved Successfully." << endl;
}


void Sun_Light_Image()
{
  Image photo(Main_name);

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
  string FileName;

  // Saving the modified image with the new file name
  save_image(FileName,photo);
  // Informing the user that the image has been saved successfully
  cout << "The Image Saved Successfully." << endl;
}

void black_white()
{
  // string filename;
  //   cout << "Pls enter colored image name to turn to black and white: ";
  //   cin >> filename;

    // Create an Image object using the provided filename
    Image image(Main_name);

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
    
    string filename;

    // Save the modified image with the specified filename
    cin.ignore();
    save_image(filename,image);
}

// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> end part of hassan walid  <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<


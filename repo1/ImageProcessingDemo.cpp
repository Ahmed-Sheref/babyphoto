// Purpose: 
/*
  This C++ program implements basic image manipulation functionalities including grayscale conversion,
  image merging, rotation, inversion, and resizing, with input validation and user-friendly interface.
*/
// Author1: Ahmed Sheref Sayed      ID:20230542    Email:ahmedsheref2288@yahoo.com    section 21,22  (valid_input),(print_message),(Grayscale_Conversion),(merge_image)
// Author2: Youssef Yasser El-sayed ID:20230519    Email:yoyoyasso19@gmail.com        section 21,22  (Rotate_Image),(Invert_Image)
// Author3: Hassan Walid Hassan     ID:20230544    Email:hassan.moselhy22@gmail.com   section 21,22 (resize_photo)
// Version: 1.0
// Date: 26.March 2024



#include <iostream>
#include "Image_Class.h" // Include the header file for the Image class
#include "string" 

using namespace std;


// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> part of ahmed sheref <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
string valid_input(string input); 
void pirnt_message(); 
void Grayscale_Conversion ();
void merge_image();
void const save_image (string &filename , Image &image); // Ask the user if he wants to save the image or not
// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> end part of ahmed sheref <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> part of Youssef Yasser <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
void Rotate_Image(); 
void Invert_Image(); 
// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> end part of Youssef Yasser <<<<<<<<<<<<<<<<<<<<<<<<<<<<

// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> part of Hassan Walid <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<  
void resize_photo(); 
// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> end part of Hassan Walid <<<<<<<<<<<<<<<<<<<<<<<<<<<<<< 



// Function to save image


// Main function
int main ()
{
  while (true)
  {
    cout << "╔════════════════════════════════════════╗\n";
    cout << "║              \033[7;31m R \033[0m ";    // Red
    cout << "\033[7;32m G \033[0m ";                   // Green
    cout << "\033[7;34m B \033[0m               ║\n";  // Blue
    cout << "║  We have 6 methods of photoshop.       ║\n";
    cout << "║  Choose one of the following options:  ║\n";
    cout << "║  1. Grayscale_Conversion               ║\n";
    cout << "║  2. merge_image                        ║\n";
    cout << "║  3. Rotate_Image                       ║\n";
    cout << "║  4. Invert_Image                       ║\n";
    cout << "║  5. resize_photo                       ║\n";
    cout << "║  6. Exit                               ║\n";
    cout << "╚════════════════════════════════════════╝\n\n";

    string test_choose;
    getline(cin , test_choose); // Read user choice
    int number_choose = stoi(valid_input(test_choose)); // Convert user choice to integer

    // Validate user choice
    while (number_choose != 1 && number_choose != 2 && number_choose != 3 && number_choose != 4 && number_choose != 5  && number_choose != 6)
    {
      cout << "Enter your choice (1-5): ";
      cin >> test_choose; // Read user choice again
      cin.ignore(); // Ignore any remaining characters in the input buffer
      number_choose = stoi(valid_input(test_choose)); // Convert user choice to integer
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
        Rotate_Image(); // Call rotate image function
        break;
      case 4:
        Invert_Image(); // Call invert image function
        break;
      case 5:
        resize_photo(); // Call resize image function
        break;
      case 6:
        cout << "\033[3;31m EX\033[0m"; // Red
        cout << "\033[3;32mIT\033[0m";// Green
        cout << "\033[3;34m...!\033[0m\n";  // Blue
        return 0; // Exit the program
    }

    // Prompt the user if they want to continue editing pictures
    cout << "\nDo you want to continue editing pictures?\n";
    cout << "  1. Yes\n";
    cout << "  2. No\n";

    // Read user choice
    string test_Try_again;
    cin >> test_Try_again;
    cin.ignore();
    int number_Try_again = stoi(valid_input(test_Try_again)); // Convert user choice to integer

    // Validate user choice
    while (number_Try_again != 1 && number_Try_again != 2)
    {
      cout << "Enter your choice (1-2): ";
      cin >> test_Try_again; // Read user choice again
      number_Try_again = stoi(valid_input(test_Try_again)); // Convert user choice to integer
    }

    // Execute the selected action based on the user's choice
    switch (number_Try_again)
    {
    case 1:
      break; // Continue with the loop
    case 2:
      cout << "\033[3;31m  Exit... \033[0m" << endl; // Inform about program exit
      return 0; // Exit the program
    }
  }
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

// Function for grayscale conversion
void Grayscale_Conversion()
{
  cout << "Welcome to Grayscale_Conversion programming :\n>>>>>>>>> ";
  pirnt_message(); // Print message
  string photoname;
  cout << "Pls enter colored image name to turn to gray scale: ";
  cin >> photoname; // Read user input for image name

  Image photo(photoname); // Load the photo from the provided photoname

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
    save_image(photoname, photo); // Save the modified image
}

// Function to print message
void pirnt_message()
{
  cout << "\033[5;31m R \033[0m"; // Print 'R' in red
  cout << "\033[5;32m G \033[0m"; // Print 'G' in green
  cout << "\033[5;34m B \033[0m"; // Print 'B' in blue
  cout << " <<<<<<<<<<<<";
  cout << endl;
}

// Function to merge images
void merge_image()
{
  cout << "Welcome to merge_image programming :\n>>>>>>>>> ";
  pirnt_message(); // Print message
  string phototname1, photoname2;
  cout << "Pls enter colored image_1 name to turn to gray scale: ";
  cin >> phototname1;
  cout << "Pls enter colored image_1 name to turn to gray scale: ";
  cin >> photoname2;

  Image image(phototname1);
  Image image2(photoname2);
  Image image3;

  // Determine the size of the resulting image
  if ((image.width * image.height) < image2.width * image2.height)
  {
    image3.loadNewImage(phototname1);
  }
  else
  {
    image3.loadNewImage(photoname2);
  }

  // Merge the images
  for (int i = 0; i < image3.width; ++i)
  {
    for (int j = 0; j < image3.height; ++j)
    {
      for (int k = 0; k < image3.channels; ++k)
      {
          int pixel_value = 0;
          pixel_value += image(i, j, k) * 0.7;
          pixel_value += image2(i, j, k) * 0.7;
          image3(i, j, k) = min(pixel_value, 255);
      }
    }
  }
  string file_name3;
  save_image(file_name3, image3); // Save the merged image
}

// Function to rotate an image
void Rotate_Image()
{
  cout << "Welcome to Rotate_Image programming :\n>>>>>>>>> ";
  pirnt_message(); // Print message

  // Prompt user to enter the name of the colored image
  string filename;
  cout << "Please enter the name of the colored image: ";
  cin >> filename;

  // Load the image from the provided filename
  Image image(filename);

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

    save_image(filename, image); // Save the rotated image
}

// Function to invert an image
void Invert_Image()
{
  cout << "Welcome to Invert_Image programming :\n>>>>>>>>> ";
  pirnt_message(); // Print message
  string filename;
  cout << "Pls enter colored image name : ";
  cin >> filename;

  Image image(filename);

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
  save_image(filename, image); // Save the inverted image
}

// Function to resize an image
void resize_photo()
{
  string photo;
  cout << "Please enter the image name you want to resize: ";
  cin >> photo;

  Image image(photo);

  int newWidth, newHeight;
  cout << "Please enter the new width for the image: ";
  cin >> newWidth;
  cout << "Please enter the new height for the image: ";
  cin >> newHeight;

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

  save_image(photo,image);
}


void const save_image (string &filename , Image &image)
{
  string test_save;
  cin.ignore(); // Ignore any remaining characters in the input buffer
  cout << "1) Save to the new image\n";
  cout << "2) Not save\n";
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
    cout << "Saved successfully\n";
    break;
  case 2:
    break; // Do not save the image
  }
}
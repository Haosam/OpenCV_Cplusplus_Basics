# Explanation of the codes

## OpenCV_Basics.cpp - Opening an image in OpenCV

### This code is about how to open an image in OpenCV

So let's go through the code individually

#### Headers
```
//#include "stdafx.h
```
This is a header file that normally is included in Visual Studio. Sometimes, it can work, sometimes it cannot work. I recommend that this be uncommented when using Visual Studio

```
#include <opencv2/opencv.hpp>
#include <iostream>
```
opencv2/opencv.hpp - This is to call the opencv header that is needed for OpenCV operations
iostream - This is for cout/cin

```
using namespace cv;
using namespace std;
```
All OpenCV functions, classes and data structures are declared inside cv namespace. So, we have to add the 'using namespace cv' line in the top of our program. Otherwise we have to append 'cv::' specifier before each OpenCV functions, classes and data structures. (e.g - cv::Mat, cv::imread() , etc). For more information, please refer OpenCV C++ API.

We have to use the std namespace also because cout, endl and cin functions are inside the std namespace.

#### Reading the image
```
Mat image = imread("C:/Users/Samuel/Desktop/OpenCV_3_Windows_10_Installation_Tutorial-master/OpenCVbasic1/ntu.jpg");
```
The function loads an image from the file "C:/Users/Samuel/Desktop/OpenCV_3_Windows_10_Installation_Tutorial-master/OpenCVbasic1/ntu.jpg" and returns it as a Mat object.  
In your code, you have to replace the "C:/Users/Samuel/Desktop/OpenCV_3_Windows_10_Installation_Tutorial-master/OpenCVbasic1/ntu.jpg" with a valid location to an image file in your computer.  

More information on this code:
>Mat imread(const String& filename, int flags = IMREAD_COLOR)

- This function loads an image from the specified file and return is as a Mat object. If the function cannot read the file, it will return an empty Mat object.  
- filename - You have to give the relative or absolute path of an image file. If you are giving the relative path, it should be relative to your cpp file. jpeg, jpg, bmp, png, tiff and tif image file types are always supported. Other image file types are supported depending on your platform and installed codecs.  
- flags - There are several possible values for the flag argument. In the above program, I did not pass any value to this argument such that default IMREAD_COLOR argument will be used.  
>IMREAD_UNCHANGED - The image will be loaded as it is. If you want to get the alpha channel in your input image (if it is available), you have to use this flag.  
>IMREAD_GRAYSCALE - The image will be load as a gray-scale image (i.e. - Single channel image, Black and white image)  
>IMREAD_COLOR - The image will be loaded as a BGR image (i.e. - 3 channel image, color image) <br/>

#### Error Catching
```
 // Check for failure
 if (image.empty()) 
 {
   cout << "Could not open or find the image" << endl;
   cin.get(); //wait for any key press
   return -1;
 }
 ```
If imread() function fails to load the image, the returned Mat object will be empty. If the Mat object is empty, image.empty() function will return true. In such scenarios, our program will print an error message to the console and wait for any key press. When the user press any key in the keyboard, the program will exit returning -1. It's a good practice to check whether the image is empty and exit the program. Otherwise your program will crash while trying to execute the imshow() function.

#### Creating a Window
```
namedWindow(windowName); // Create a window
```
This will create a window to display the image

>void namedWindow(const String& winname, int flags = WINDOW_AUTOSIZE)

This function creates a window which can be used to place images and track bars. If a window already exists with the given name, this function does nothing.  
winname - Name of the window. That name will display in the title bar of the newly created window. This name is also the identifier for this window and it will be used in the later OpenCV function calls to identify the window.  
flags - Determine the size of the window. In the above program, I did not pass any value to this argument such that default WINDOW_AUTOSIZE argument will be used.
- WINDOW_AUTOSIZE - User cannot resize the window. Image will be displayed in its original size. 
- WINDOW_NORMAL- User can resize the window.

```
imshow(windowName, image); // Show our image inside the created window.
```
this function displays the image in the window created

```
waitKey(0); // Wait for any keystroke in the window
```
waitKey(0) indicates the it will wait forever until a key is pressed. if an integer value is passed, instead of 0, then it will wait for that time duration in milliseconds

```
destroyWindow(windowName); //destroy the created window
```
This function will destroy the window created to de-allocate anything in the memory usage

### Create a Blank Image in OpenCV
In the other code, OpenCV_Basics1_FullColor, it will just create a window with a singular color  
The only difference in this code is this line
```
Mat image(600, 800, CV_8UC3, Scalar(100, 250, 30));
```
600,800 - 600x800 pixels window  
type - CV_8UC3  
Scalar(100, 250, 30) - Scalar values of Blue, Green, Red  

## Credit to Shermal Fernando for creating the codes from which this github is based on - https://www.opencv-srf.com/2017/11/load-and-display-image.html

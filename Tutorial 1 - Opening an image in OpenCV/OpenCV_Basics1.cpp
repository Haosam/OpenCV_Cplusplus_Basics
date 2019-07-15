// This is a comment line
// OpenCV - Why I choose OpenCV. OpenCV is a open source, free library that I personally find is very effective at configuring and managing
// images/videos. OpenCV comes in Python and C++, and maybe Java which I have not done. So if you are working on camera modules that need to
// work on images/videos, you can consider OpenCV which I will be using in this tutorial code

// In any programing language, you need to call out your libraries at the top. It is the standard recognized configuration on how to code
// So in C++ we will call them this way, other languages may call them differently

//#include "stdafx.h"
#include <opencv2/opencv.hpp>
#include <iostream>  // All C++ code needs this. This is to call out the fundamental building blocks of C++, without this iostream, you can run few functions

using namespace cv;
using namespace std; // Also another fundamental call

// This is your main function
int main(int argc, char** argv) 
{
	//Read the image file
	Mat image = imread("C:/Users/Samuel/Desktop/OpenCV_3_Windows_10_Installation_Tutorial-master/OpenCVbasic1/ntu.jpg"); // Please remember to change the path of the image

		// Check if loading the image file fails
	if (image.empty())
	{
		// cout is to display a message (Like print a message on the screen/logs file)
		cout << "Could not open the image" << endl;
		// endl means end line, it is something like a breakspace. So if you have multiple cout, the outputwillnotbecomelikethis
		cin.get(); // wait for a key press
		return -1;
	}
	
	String windowName = "Mingyeong"; // The name of the popup window that will appear

	namedWindow(windowName); // create a window

	imshow(windowName, image); // Show our image inside the created window

	waitKey(0); // Wait for any keystroke inside the window (Basically press any key with the mouse cursor inside the window)

	destroyWindow(windowName); // destroy the created window

	return 0; // This is basically to exit this function without returning anything
}

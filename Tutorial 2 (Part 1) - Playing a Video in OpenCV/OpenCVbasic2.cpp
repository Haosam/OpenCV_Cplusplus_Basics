#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main(int argc, char* argv[])
{
	char* fileName = "C:/Users/Samuel/Desktop/OpenCV_3_Windows_10_Installation_Tutorial-master/OpenCVbasic2/zzbm.mp4"; //please remember to change this link
	//opening the video to read
	// There will be no sound on this video
	VideoCapture cap(fileName);

	//if not successful, throw error message
	if (cap.isOpened() == false)
	{
		cout << "Cannot open the file" << endl;
		cin.get(); //wait for key press
		return -1;
	}

	//set video in the middle of screen
	cap.set(CAP_PROP_POS_MSEC, 300);

	//get frame rate of video
	double fps = cap.get(CAP_PROP_FPS);
	cout << "The frame rate of the video is: " << fps << endl;

	String window_name = "First OpenCV Video";

	namedWindow(window_name, WINDOW_NORMAL); // create a window

	while (true)
	{
		Mat frame;
		bool bSuccess = cap.read(frame); //read new frame from video

		//break while loop at the end of the video
		if (bSuccess == false)
		{
			cout << "Found the end of the video " << endl;
			break;
		}

		//show frame in the created window
		imshow(window_name, frame);

		//wait for for 10 ms until any key is pressed.  
		//If the 'Esc' key is pressed, break the while loop. - It will stop playing the video
		//If the any other key is pressed, continue the loop 
		//If any key is not pressed withing 10 ms, continue the loop
		if (waitKey(10) == 27)
		{
			cout << "Esc key is pressed by user. Stoppig the video" << endl;
			break;
		}

	}
	return 0;
}
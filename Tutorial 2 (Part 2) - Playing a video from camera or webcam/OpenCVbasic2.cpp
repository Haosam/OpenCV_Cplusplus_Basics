#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main(int argc, char* argv[])
{
	
	//opening the video to read
	// There will be no sound on this video
	VideoCapture cap(0);

	//if not successful, throw error message
	if (cap.isOpened() == false)
	{
		cout << "Cannot open the video camera" << endl;
		cin.get(); //wait for key press
		return -1;
	}

	// This is related to pxels
	double dWidth = cap.get(CAP_PROP_FRAME_WIDTH); // get the width of the frames of the video
	double dHeight = cap.get(CAP_PROP_FRAME_HEIGHT); // getthe height of the frames

	cout << "Resolution of the video : " << dWidth << " x " << dHeight << endl;

	//get frame rate of video
	double fps = cap.get(CAP_PROP_FPS);
	cout << "The frame rate of the video is: " << fps << endl;

	String window_name = "My Camera Feed";

	namedWindow(window_name); // create a window

	while (true)
	{
		Mat frame;
		bool bSuccess = cap.read(frame); //read new frame from video

		//break while loop at the end of the video
		if (bSuccess == false)
		{
			cout << "The camera is disconnected " << endl;
			cin.get();
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
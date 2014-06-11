#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

#define ENABLE_CAMERA	0

#if ENABLE_CAMERA
#define VIDEO_SOURCE	1
#else 
#define VIDEO_SOURCE	"./video/Spaceship_480x360-fps30.flv"
#endif

int main(int argc, char **argv)
{
	// Open laptop camera or video file
	VideoCapture video(VIDEO_SOURCE);

	if (!video.isOpened())
	{
		cout << "Cannot open video file/device: " << VIDEO_SOURCE << endl;
		return -1;
	}

	namedWindow("OpenCV", CV_WINDOW_AUTOSIZE);
	moveWindow("OpenCV", 0, 0);

	Mat frame;

	while (true)
	{
		video >> frame;
		if (frame.empty())
		{
			cout << "Invalid frame." << endl;
			break;
		}
		imshow("OpenCV", frame);

		if (waitKey(33) >= 0)
			break;
	}

	frame.release();
	video.release();	
	return 0;
}


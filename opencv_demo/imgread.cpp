#include <iostream>
#include <ctime>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

#define IMG_FILE_PATH "img/lena.jpg"
#define GRAY_FILE_PATH "img/gray.jpg"

int main()
{
	cout << "Hello opencv!" << endl;

	// Load image
	Mat img = imread(IMG_FILE_PATH, CV_LOAD_IMAGE_COLOR);

	if (img.empty())
	{
		cout << "Fail to read file" << endl;
		return -1;
	}

	Mat gray;

	// Print image info
	cout << "Image width: " << img.cols << endl;
	cout << "Image height: " << img.rows << endl;

	cout << "Convert color(BGR to gray)" << endl;

	// Convet BGR to Gray
	cout << "Start time: " << (double)clock() / CLOCKS_PER_SEC << endl;
	cvtColor(img, gray, CV_BGR2GRAY);

	cout << "End time: " << (double)clock() / CLOCKS_PER_SEC << endl;

	// Create window
	namedWindow("OpenCV", CV_WINDOW_AUTOSIZE);
	moveWindow("OpenCV", 0, 0);

	imshow("OpenCV", gray);
	waitKey(0);

	// Save image
	imwrite(GRAY_FILE_PATH, gray);

	return 0;
}


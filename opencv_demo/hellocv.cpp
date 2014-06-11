#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main()
{
	cout << "Hello opencv!" << endl;

	Mat M(2,2, CV_8UC3, Scalar(0,0,255));
	cout << "M = " << endl << " " << M << endl << endl;

	return 0;
}



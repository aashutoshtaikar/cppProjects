#include <opencv2\opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main() {
	Mat colourFile = imread("4.jpg", IMREAD_COLOR);
	Mat grayFile = imread("4.jpg", IMREAD_GRAYSCALE);

	imshow("color", colourFile);
	imshow("gray", grayFile);

	imwrite("outputGray.jpg", grayFile);
	
	waitKey();
	return 0;
}
#include <opencv2\opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main() {
	Mat testObj = imread("4.jpg", IMREAD_COLOR);
	namedWindow("color", WINDOW_FREERATIO);
	imshow("color", testObj);
	waitKey();
}
#include <opencv2\opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main() {
	Mat file1 = imread("4.jpg", IMREAD_COLOR);
	Mat file2 = imread("4.jpg", IMREAD_GRAYSCALE);
	namedWindow("color", WINDOW_FREERATIO);
	namedWindow("fixed", WINDOW_AUTOSIZE);


	imshow("color", file1); //should be same of the namedWindow("Color")
	imshow("fixed", file2);	//should be same of the namedWindow("fixed")

	
	//resizeWindow("color", file1.cols/2, file1.rows/2);
	//resizeWindow("fixed", file2.cols/2, file2.rows/2);

	moveWindow("color", 400, 600);
	moveWindow("fixed", 400 + file1.cols+5, 600);

	waitKey();

}
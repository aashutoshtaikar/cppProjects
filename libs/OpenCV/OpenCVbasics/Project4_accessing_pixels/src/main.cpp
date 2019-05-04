#include <opencv2\opencv.hpp>
#include <iostream>
#include <stdint.h>

using namespace cv;
using namespace std;

int main() {
	//grayscale
	//Mat original = imread("Lenna.png", IMREAD_GRAYSCALE);
	//Mat modified = imread("Lenna.png", IMREAD_GRAYSCALE);
	//
	//for (int r = 0; r < modified.rows; r++)
	//{
	//	for (int c = 0; c < modified.cols; c++) 
	//	{
	//		modified.at<uint8_t>(r, c) = modified.at<uint8_t>(r, c) * 0.5f; //get the value from each pixel and modify
	//	}
	//}

	//color
	Mat original = imread("Lenna.png", IMREAD_ANYCOLOR);
	Mat modified = imread("Lenna.png", IMREAD_ANYCOLOR);

	for (int r = 0; r < modified.rows; r++)
	{
		for (int c = 0; c < modified.cols; c++)
		{
			/*vec3b - vector 3 channel byte color image value(0-255)*/
			//modified.at<Vec3b>(r, c)[0] = modified.at<Vec3b>(r, c)[0] * 0;	//blue 
			//modified.at<Vec3b>(r, c)[1] = modified.at<Vec3b>(r, c)[1] * 0;	//green
			modified.at<Vec3b>(r, c)[2] = modified.at<Vec3b>(r, c)[2] * 0;		//red
		}
	}

	imshow("original", original);
	imshow("modified", modified);
	

	waitKey();

}
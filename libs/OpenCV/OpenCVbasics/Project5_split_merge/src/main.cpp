#include <opencv2\opencv.hpp>
#include <iostream>
#include <stdint.h>

using namespace cv;
using namespace std;

int main() 
{
	Mat original = imread("../Lenna.png", IMREAD_COLOR);

	Mat splitChannels[3];
	split(original, splitChannels);

	imshow("B", splitChannels[0]);	//will only extract the intensities of Blue (Grayscale)
	imshow("G", splitChannels[1]);
	imshow("R", splitChannels[2]);
	
	//kill red channel
	splitChannels[2] = Mat::zeros(splitChannels[2].size(), CV_8UC1); //unsigned channel U/UC/UC1
	
	Mat output;
	merge(splitChannels, 3, output);

	imshow("merged", output);

	waitKey();
}
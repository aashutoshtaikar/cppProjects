#include<opencv2\opencv.hpp>
#include<iostream>

using namespace std;
using namespace cv;

void takeDft(Mat& source, Mat& destination);
void showDft(Mat& source);
void recenterDft(Mat& source);
void invertDft(Mat& source, Mat& dest);

void takeDft(Mat& source, Mat& destination)
{
	//create mat with 2 channels; 1 -> real , 2 -> imaginary(filled with zeros)
	Mat originalComplex[2] = { source, Mat::zeros(source.size(), CV_32F) };	// {real, imaginary}
	Mat dftReady;

	merge(originalComplex, 2, dftReady); //merging the arrays into destination(dftReady) vector having 2 channels

	//take a dft(requires a floating point datatype)
	dft(dftReady, destination, DFT_COMPLEX_OUTPUT);
}

//display dft
void showDft(Mat& source)
{
	//2 channel Mat object coming in -- need to split into 2 channels
	Mat splitArray[2] = { Mat::zeros(source.size(),CV_32F), Mat::zeros(source.size(),CV_32F) }; //array to hold split values of source 
	split(source, splitArray);	//split source into 2 channels

	//taking the magnitude
	Mat dftMagnitude;
	magnitude(splitArray[0], splitArray[1], dftMagnitude);

	//values(mags) are over enormous range need to take log -- before that need to add 1 to all elements
	dftMagnitude += Scalar::all(1);
	log(dftMagnitude, dftMagnitude);

	//values are still beyond 0 and 1 thus again normalizing mags to be between 0 and 1 
	normalize(dftMagnitude, dftMagnitude, 0, 1, NORM_MINMAX);

	recenterDft(dftMagnitude);	//recenters dft to have the high freq's in center
	imshow("dft", dftMagnitude);
}

void recenterDft(Mat& source)
{
	//getting the center point from source
	int centerX = source.cols / 2;
	int centerY = source.rows / 2;

	Mat q1(source, Rect(0, 0, centerX, centerY));	//only 1st quadrant info
	Mat q2(source, Rect(centerX, 0, centerX, centerY));
	Mat q3(source, Rect(0, centerY, centerX, centerY));
	Mat q4(source, Rect(centerX, centerY, centerX, centerY));

	Mat swapMap;
	q1.copyTo(swapMap);
	q4.copyTo(q1);
	swapMap.copyTo(q4);

	q2.copyTo(swapMap);
	q3.copyTo(q2);
	swapMap.copyTo(q3);
}

void invertDft(Mat& source, Mat& dest)
{
	dft(source, dest, DFT_INVERSE | DFT_REAL_OUTPUT | DFT_SCALE);
}

void createGaussian(Size size, Mat& output, int uX, int uY, float sigmaX, float sigmaY, float amplitude=1.0) 
{
	Mat temp = Mat(size, CV_32F);

	for (int r = 0 ; r<size.height; r++) 
	{
		for (int c = 0; c < size.width; c++)
		{
			float x = ((c-uX)*((float)c-uX)) / (2.0f * sigmaX * sigmaX);
			float y = ((r - uY)*((float)r - uY)) / (2.0f * sigmaY * sigmaY);
			float value = amplitude * exp(-(x + y));
			temp.at<float>(r, c) = value;
		}
	}

	normalize(temp, temp, 0.0f, 1.0f, NORM_MINMAX);
	output = temp;
}

int main()
{
	Mat output;
	createGaussian(Size(256, 256), output, 256 / 2, 256 / 2, 10, 10);

	imshow("gaussian", output);

	waitKey();
}
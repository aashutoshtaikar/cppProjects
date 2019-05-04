#include<opencv2\opencv.hpp>
#include<iostream>

using namespace std;
using namespace cv;

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

	imshow("dft", dftMagnitude);
}


int main()
{
	Mat original = imread("../Lenna.png", IMREAD_GRAYSCALE);

	Mat originalFloat;	//output

	//convert to float to  
	original.convertTo(originalFloat, CV_32FC1, 1.0 / 255.0);

	Mat dftOforiginal;
	takeDft(originalFloat, dftOforiginal);

	showDft(dftOforiginal);
	waitKey();
}
#include<opencv2\opencv.hpp>
#include<iostream>

using namespace std;
using namespace cv;

int main() 
{
	Mat original = imread("../Lenna.png", IMREAD_GRAYSCALE);

	Mat originalFloat;	//output

	//convert to float to  
	original.convertTo(originalFloat, CV_32FC1, 1.0 / 255.0);

	//create mat with 2 channels; 1 -> real , 2 -> imaginary(filled with zeros)
	Mat originalComplex[2] = {originalFloat, Mat::zeros(originalFloat.size(), CV_32F)};	// {real, imaginary}
	Mat dftReady;

	merge(originalComplex, 2, dftReady); //merging the arrays into destination(dftReady) vector having 2 channels

	//take a dft(requires a floating point datatype)
	Mat dftOforiginal;
	dft(dftReady, dftOforiginal, DFT_COMPLEX_OUTPUT);

}
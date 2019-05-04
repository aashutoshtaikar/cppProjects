#include <opencv2\opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

const int fps = 20;

int main(){
	Mat frame;
	//VideoCapture vid(0); // get webcam data 
	VideoCapture vid("rtsp://wowzaec2demo.streamlock.net/vod/mp4:BigBuckBunny_115k.mov"); // get network stream
	namedWindow("Webcam", WINDOW_AUTOSIZE);

	if (!vid.isOpened()) {
		return -1;
	}

	while (vid.read(frame)) {
		imshow("Webcam", frame);
		if (waitKey(1000 / fps) >= 0) break;	//wait for at least 1000s/fps seconds
	}

	return 1;
}
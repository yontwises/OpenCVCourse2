#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/objdetect.hpp>
#include <iostream>

using namespace cv;
using namespace std;

//// Project 3
int main() {

	VideoCapture cap(1);
	Mat img;

	CascadeClassifier plateCascade;
	plateCascade.load("Resources/haarcascade_russian_plate_number.xml");

	if (plateCascade.empty()) {
		cout << "XML file not loaded" << endl;
	}

	vector<Rect> plates;

	while (true) {
		cap.read(img);
		plateCascade.detectMultiScale(img, plates, 1.1, 10);

		for (unsigned i = 0; i < plates.size(); i++) {
			Mat imgCrop = img(plates[i]);
			imwrite("Resources/Plates/" + to_string(i) + ".png",imgCrop);
			rectangle(img, plates.at(i).tl(), plates.at(i).br(), Scalar(255, 0, 255), 3);
		}

		imshow("Image", img);
		waitKey(1);

	}
	
	return -1; 
} 
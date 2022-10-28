#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;

// Resize and Crop /// 
int main() {
	string path = "Resources/test.png";

	Mat img = imread(path);
	Mat imgResize, imgCrop;

	cout << img.size() << endl;
	resize(img, imgResize,Size(),0.5,0.5);
	Rect roi(200, 100, 300, 200);
	imgCrop = img(roi);
	imshow("Image", img);
	imshow("Resized Image", imgResize);
	imshow("Image Crop", imgCrop);



	waitKey(0);

	return -1;

}
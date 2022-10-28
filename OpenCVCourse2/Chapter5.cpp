#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;

//// Importing Images
float w = 250, h = 350;
Mat matrix, imgWarp,imgWarpQueen, imgWarpJack,imgWarpNine;
int main() {

	string path = "Resources/cards.jpg";
	Mat img = imread(path);

	//King
	Point2f src[4] = { {529,142},{771,190},{405,395},{674,457} };
	Point2f dst[4] = { {0.0f,0.0f},{w,0.0f},{0.0f,h},{w,h} };

	
	
	matrix = getPerspectiveTransform(src, dst);
	warpPerspective(img, imgWarp, matrix, Point(w, h));

	//Queen 
	Point2f srcQueen[4] = { {65,324},{338,279},{89,633},{401,574} };
	Mat matrixQueen = getPerspectiveTransform(srcQueen, dst);
	warpPerspective(img, imgWarpQueen, matrixQueen, Point(w, h));

	//Jack 
	Point2f srcJack[4] = { {777,106},{1016,84},{844,359},{1115,331} };
	Mat matrixJack = getPerspectiveTransform(srcJack, dst);
	warpPerspective(img, imgWarpJack, matrixJack, Point(w, h));

	for (int i = 0; i < 4; i++) {
		circle(img, src[i], 10, Scalar(0, 0, 255), FILLED);
		circle(img, srcQueen[i], 10, Scalar(0, 0, 255), FILLED);
		circle(img, srcJack[i], 10, Scalar(0, 0, 255), FILLED);

	}

	imshow("Image", img);
	imshow("Image Warp", imgWarp);
	imshow("Image Queen Warp", imgWarpQueen);
	imshow("Image Jack Warp", imgWarpJack);


	waitKey(0);
	return -1;
}


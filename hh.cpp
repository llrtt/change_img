#include <opencv2/opencv.hpp>
#include <iostream>
#include <sstream>
using namespace cv;
using namespace std;

int main()
{
    Mat struct_element1 = getStructuringElement(MORPH_RECT, Size(3, 3), Point(-1, -1));
    string path = "/home/joker/Desktop/identify-mnist/";
    string suffix = ".jpg";
    for (int i = 0; i <= 9; i++)
    {
        stringstream s;
        string str0;
        s << i;
        s >> str0;
        string m1 = path + str0 + "-a" + suffix;
        string m2 = str0 + "-h" + suffix;
        Mat a = imread(m1);
        Mat b(a.size(), CV_8UC1);
        cvtColor(a, b, COLOR_BGR2GRAY);
        resize(b, b, Size(28, 28));
        cout << b;
        inRange(b, Scalar(0), Scalar(130), b);
        dilate(b, b, struct_element1);
        imwrite(m2, b);
        imshow("a", b);
        waitKey(0);
    }
    return 0;
}
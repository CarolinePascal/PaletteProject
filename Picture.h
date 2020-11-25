#ifndef PICTURE_H
#define PICTURE_H

#include <opencv2/opencv.hpp>   //TODO Install OpenCV
#include <iostream>

using namespace cv;
using namespace std;

class Picture
{
private:
    Mat matrix;
public:
    Picture(const String &fileName);
    ~Picture();
    void Display();
};

#endif
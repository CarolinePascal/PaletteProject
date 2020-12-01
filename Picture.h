#ifndef PICTURE_H
#define PICTURE_H

#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
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
    void Display() const;
    Vec3i GetRGB(int i, int j) const;
    Vec3i GetRGB(int k) const;
    int GetPictureResolution() const;
};

#endif
#ifndef PICTURE_H
#define PICTURE_H

#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>

class Picture
{
private:
    cv::Mat matrix;
public:
    Picture(const std::string &fileName);
    ~Picture();
    void Display() const;
    cv::Vec3i GetRGB(int i, int j) const;
    cv::Vec3i GetRGB(int k) const;
    int GetPictureResolution() const;
};

#endif
#include <opencv2/imgproc.hpp>

#include "Picture.h"

Picture::Picture(const String &fileName)
{
    // Read the image file
    matrix = imread(fileName,IMREAD_COLOR);

    // Check for failure
    if (!matrix.data)
    {
        throw("Could not read Picture !");
    }

    //TODO Resize the picture if too large
}

Picture::~Picture()
{
}

void Picture::Display() const
{
    namedWindow("Picture",WINDOW_AUTOSIZE);
    imshow("Picture",matrix);
    waitKey(0);
}

Vec3i Picture::GetRGB(int i, int j) const
{
    //TODO Replace Vec3i by Scalar 
    Vec3b BGR = matrix.at<Vec3b>(i,j);
    int B = BGR.val[0];
    int G = BGR.val[1];
    int R = BGR.val[2];
    Vec3i RGB(R,G,B);

    return(RGB);
}

Vec3i Picture::GetRGB(int k) const
{
    int i = k / (int)matrix.cols;
    int j = k % (int)matrix.cols;
    return(GetRGB(i,j));
}

int Picture::GetPictureResolution() const
{
    return(matrix.rows*matrix.cols);
}


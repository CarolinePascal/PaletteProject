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
}

Picture::~Picture()
{
}

void Picture::Display()
{
    namedWindow("Picture",WINDOW_AUTOSIZE);
    imshow("Picture",matrix);
    waitKey(0);
}

Vec3i Picture::GetRGB(int i, int j)
{
    Vec3b BGR = matrix.at<Vec3b>(i,j);
    int B = BGR.val[0];
    int G = BGR.val[1];
    int R = BGR.val[2];
    Vec3i RGB(R,G,B);

    return(RGB);
}
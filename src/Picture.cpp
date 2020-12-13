#define MAX_PICTURE_RESOLUTION 1000000

#include <opencv2/imgproc.hpp>

#include "../include/Picture.h"

using namespace cv;
using namespace std;

Picture::Picture(const string &fileName)
{
    // Read the image file
    matrix = imread(fileName,IMREAD_COLOR);

    // Check for failure
    if (!matrix.data)
    {
        throw("Could not read Picture !");
    }

    if(GetPictureResolution() > MAX_PICTURE_RESOLUTION)
    {
        resize(matrix,matrix,Size(matrix.cols*0.5,matrix.rows*0.5),0,0,INTER_LINEAR);
    }
}

Picture::~Picture()
{
}

void Picture::Display() const
{
    namedWindow("Picture",WINDOW_AUTOSIZE);
    imshow("Picture",matrix);
}

Vec3i Picture::GetRGB(int i, int j) const
{
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


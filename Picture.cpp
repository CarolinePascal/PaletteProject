#include "Picture.h"

Picture::Picture(const String &fileName)
{
    // Read the image file
    matrix = imread(fileName,flags=IMREAD_COLOR);

    // Check for failure
    if (matrix.empty())
    {
        throw("Could not read Picture !")
    }
}

Picture::~Picture()
{
}

void Picture::Display()
{
    String windowName = "Picture";  //TODO Parsing on filename ?
    namedWindow=(windowName);
    imshow(windowName,matrix);
    waitKey(0);
    destroyWindow(windowName);
}
#include <iostream>
#include <thread>

#include "../include/Picture.h"
#include "../include/KMeans.h"

using namespace cv;
using namespace std;
 
int main( int argc, char** argv ) {

    //Parameters parsing - Name of the picture file, number of colors within the palette
    string fileName = "";
    int colorNumber = 5;

    switch (argc)
    {
    case 1:
        throw("No file name given !");

    case 2:
        fileName = argv[1];
        break;

    case 3:
        fileName = argv[1];
        colorNumber = stoi(argv[2]);
        break;
    
    default:
        throw("Too many parameters given !");

    }

    //Initialize random seed: 
    srand(time(NULL));

    //Display picture
    Picture picture = Picture(fileName);
    picture.Display();

    //Compute and display palette
    vector<Vec3i> test = KMeans(picture, colorNumber, 10);
    DisplayPalette(test);

    waitKey(0);
    return(0);
}
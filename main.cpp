#include <iostream>
#include <thread>

#include "Picture.h"
#include "KMeans.h"
 
int main( int argc, char** argv ) {

    //Parameters parsing - Name of the picture file, number of colors within the palette

    String fileName = "";
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
    srand (time(NULL));

    //Display picture TODO Internalize thread
    Picture picture = Picture(fileName);
    thread thread_picture(&Picture::Display,&picture);

    //Compute and display palette TODO Internalize thread
    vector<Vec3i> test = KMeans(picture, colorNumber, 10);
    thread thread_palette(DisplayPalette,test);
    
    thread_picture.join();
    thread_palette.join();
    
    return(1);
}
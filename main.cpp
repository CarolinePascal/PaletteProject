#include <iostream>
#include "Picture.h"
 
int main( int argc, char** argv ) {
    
    Picture picture = Picture("Square.jpg");
    picture.Display();

    cout<<picture.GetRGB(20,20)<<endl;

    return(1);
}
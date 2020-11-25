#include <vector>
#include "Picture.h"

struct Pixel{}
    int R,G,B;
}

double distanceRGB(const Pixel &p1, const Pixel &p2){
    return((p1.R-p2.R)*(p1.R-p2.R) + (p1.G-p2.G)*(p1.G-p2.G) + (p1.B-p2.B)*(p1.B-p2.B));
}

std::vector<int> kMeansInit(const Picture &picture){
//Implement kmeans ++
}

Picture kMeans(const Picture &picture, int colorNumber, int iterationNumber){
//Implement kmeans
}
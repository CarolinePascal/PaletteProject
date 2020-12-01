#ifndef KMEANS_H
#define KMEANS_H

#include <vector>

#include "Picture.h"

float distanceRGB(const Vec3i &pixel1, const Vec3i &pixel2);
vector<Vec3i> KMeansInit(const Picture &picture, int centroidNumber);
vector<Vec3i> KMeans(const Picture &picture, int centroidNumber, int iterationNumber);
void DisplayPalette(const vector<Vec3i> &centroids);

#endif
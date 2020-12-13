#ifndef KMEANS_H
#define KMEANS_H

#include <vector>

#include "Picture.h"

float distanceRGB(const cv::Vec3i &pixel1, const cv::Vec3i &pixel2);
std::vector<cv::Vec3i> KMeansInit(const Picture &picture, int centroidNumber);
std::vector<cv::Vec3i> KMeans(const Picture &picture, int centroidNumber, int iterationNumber);
void DisplayPalette(const std::vector<cv::Vec3i> &centroids);

#endif
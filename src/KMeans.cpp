#include <stdlib.h>
#include <opencv2/imgproc.hpp>

#include "../include/KMeans.h"

using namespace cv;
using namespace std;

float DistanceRGB(const Vec3i &pixel1, const Vec3i &pixel2)
{
    //Compute the sRGB distance
    
    int deltaR = pixel1.val[0]-pixel2.val[0];
    int deltaG = pixel1.val[1]-pixel2.val[1];
    int deltaB = pixel1.val[2]-pixel2.val[2];
    float meanR = (pixel1.val[0]+pixel2.val[0])/2;

    return(2*deltaR*deltaR + 4*deltaG*deltaG + 3*deltaB*deltaB + meanR*(deltaR*deltaR - deltaB*deltaB)/256);
}

vector<Vec3i> KMeansInit(const Picture &picture, int centroidNumber)
{
    int resolution = picture.GetPictureResolution();
    vector<Vec3i> centroids;
    Vec3i furthestPixel, currentPixel;
    int minimumDistance, currentDistance, maximumDistance;

    //Randomly select the first centroid
    centroids.push_back(picture.GetRGB(rand()%resolution));

    //Choose the next centroids such that the distance between them is maximized
    while(centroids.size() < centroidNumber)
    {
        maximumDistance = 0;

        for (int i = 0; i<resolution; i++)
        {
            minimumDistance = INT_MAX;
            currentPixel = picture.GetRGB(i);

            for (int j = 0; j<centroids.size(); j++)
            {
                currentDistance = DistanceRGB(currentPixel,centroids[j]);
                if(currentDistance <= minimumDistance)
                {
                    minimumDistance = currentDistance;
                }
            }

            if(minimumDistance >= maximumDistance)
            {
                maximumDistance = minimumDistance;
                furthestPixel = currentPixel;
            }
        }
        centroids.push_back(furthestPixel);
    }
    return(centroids);
}

vector<Vec3i> KMeans(const Picture &picture, int centroidNumber, int iterationNumber)
{
    int resolution = picture.GetPictureResolution();
    int minimumDistance, currentDistance, closestCentroid;
    
    vector<Vec3i> currentCentroids = KMeansInit(picture,centroidNumber);
    vector<Vec3i> newCentroids(currentCentroids.size(),(Vec3i)(0,0,0));
    Vec3i currentPixel;

    vector<int> centroidsCounter(currentCentroids.size());

    for (int t = 0; t < iterationNumber; t++)
    {
        for(int i = 0; i < resolution; i++)
        {
            minimumDistance = INT_MAX;
            currentPixel = picture.GetRGB(i);

            //Seek the closest centroid
            for(int j = 0; j < currentCentroids.size(); j++)
            {
                currentDistance = DistanceRGB(currentPixel,currentCentroids[j]);
                if(currentDistance < minimumDistance)
                    {
                        minimumDistance = currentDistance;
                        closestCentroid = j;
                    }
            }

            //Add the current pixel to the cluster associated to its closest centroid
            centroidsCounter[closestCentroid] += 1;
            newCentroids[closestCentroid] += currentPixel;
        }

        //Update centroids by computing the centroid of each cluster
        for(int j = 0; j < currentCentroids.size(); j++)
        {
            currentCentroids[j] = newCentroids[j]/centroidsCounter[j];
            newCentroids[j] = (Vec3i)(0,0,0);
            centroidsCounter[j] = 0;
        }
    }
    return(currentCentroids);
}

void DisplayPalette(const vector<Vec3i> &centroids)
{
    Mat palette(50,centroids.size()*50,CV_8UC3);
    Point p1(0,0),p2(50,50);
    Scalar drawnRectangle;

    for(int i = 0; i < centroids.size(); i++)
    {
        p1.x = i*50;
        p2.x = (i+1)*50;
        drawnRectangle[0] = centroids[i][2];
        drawnRectangle[1] = centroids[i][1];
        drawnRectangle[2] = centroids[i][0];

        rectangle(palette,p1,p2,drawnRectangle,FILLED);
    }

    namedWindow("Palette",WINDOW_AUTOSIZE);
    imshow("Palette",palette);
}
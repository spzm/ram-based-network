#ifndef RAMBASEDNETWORK_H
#define RAMBASEDNETWORK_H

#include <math.h>
#include <iostream>

#include <opencv/cv.h>
#include <opencv/highgui.h>

#include "rambaseddiscriminator.h"


class RamBasedNetwork
{
private:
    void process();
    CvSize size;
    int depth, channels;
    int tupleSize;

public:
    RamBasedNetwork();
    ~RamBasedNetwork();
    void makeTuples(RamBasedDiscriminator **tuple, IplImage *image, bool add = false);
    int* makeScore(RamBasedDiscriminator *ramClass, RamBasedDiscriminator *imageDiscriminator);
    void show(IplImage *image);
};

#endif // RAMBASEDNETWORK_H

#ifndef RAMBASEDPROCESS_H
#define RAMBASEDPROCESS_H

#include "rambasednetwork.h"
#include "rambaseddiscriminator.h"

#include "opencv/cv.h"
#include "QString"

#include <string>

#define PATH "/media/sp/data/Dropbox/code/qtcreator_workspace/ram2/"

using namespace std;

struct threshold {

    string name;
    int Ts;
    int black;
    int white;
};

class RamBasedProcess {

private:

    static const int class_count = 6;
    string classes[class_count];
    int *results[class_count];

    int statNum;
    IplImage *img;
    RamBasedNetwork *network;
    int tupleSize, tupleCount;

    threshold thresholds[class_count];

public:
    RamBasedProcess(int tupleSize = 8);
    bool loadImage(string path);
    bool loadImage(IplImage *src_img);
    int* process(string className);
    bool processAll();
    string estimate();
    bool saveResult(string dir = "experiments");
};

#endif // RAMBASEDPROCESS_H

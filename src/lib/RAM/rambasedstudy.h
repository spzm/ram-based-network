#ifndef RAMBASEDSTUDY_H
#define RAMBASEDSTUDY_H

#include <vector>

#include "rambasednetwork.h"
#include "rambaseddiscriminator.h"


class RamBasedStudy {

private:

    IplImage *img;
    RamBasedNetwork *network;
    int Ts, Tc;

    struct TuplesVector {
        string name;
        RamBasedDiscriminator *tuple;
    };
    vector<TuplesVector> studyTuples;

public:

    RamBasedStudy();
    bool loadImage(string path);
    bool studyClass(string className, int tupleSize = 8);
};


#endif // RAMBASEDSTUDY_H

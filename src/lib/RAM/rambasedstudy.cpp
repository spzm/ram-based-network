#include "rambasedstudy.h"

RamBasedStudy::RamBasedStudy() {

}

bool RamBasedStudy::loadImage(string path) {

    img = cvLoadImage(path.c_str(), 0);
    cvThreshold(img, img, 30, 255, CV_THRESH_BINARY);
    network = new RamBasedNetwork();

    network->show(img);

    if(img == 0)
    {
        return false;
    }

    return true;
}

bool RamBasedStudy::studyClass(string className, int tupleSize) {

    if (tupleSize > 0 && tupleSize < 100) {
        Ts = tupleSize;
    } else {
        return false;
    }

    if (img == 0) {

        return false;
    }

    Tc = ( img->width * img->height ) / Ts;
    RamBasedDiscriminator *tuple = new RamBasedDiscriminator(Ts, Tc, className);

    network->makeTuples(&tuple, img);
    tuple->save();

    return true;
}

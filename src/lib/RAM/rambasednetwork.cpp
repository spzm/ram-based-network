#include "rambasednetwork.h"


RamBasedNetwork::RamBasedNetwork() {

    this->size = size;
    this->depth = depth;
    this->channels = channels;
}

void RamBasedNetwork::show(IplImage *image) {

    if (!image) {
        printf("Image don't exist. Oh... (");
        exit(-1);
    }

    cvNamedWindow("RamBasedNetwork_show", CV_WINDOW_AUTOSIZE);
    cvShowImage("RamBasedNetwork_show", image);
}

void RamBasedNetwork::makeTuples(RamBasedDiscriminator **tuple, IplImage *image, bool add) {

    unsigned int tupleValue;
    int tupleCount = (*tuple)->getTuplesCount();
    int tupleSize = (*tuple)->getTupleSize();
    int pixelCount = tupleSize * tupleCount;

    for (int i = 0; i < pixelCount; i += tupleSize) {

        tupleValue = 0;
        for (int j = 0; j < tupleSize; j++) {
            tupleValue |= (1 & (image->imageData[i + j])) << j;
        }

        // Проверям флаг добавлени еще одиного в образ в дискриминатор
        if (add) {
            tupleValue |= (*tuple)->getValue(i / tupleSize);
        }

        (*tuple)->setTupleValue(i / tupleSize, tupleValue);
        if (i == 0) {
            std::cout << tupleValue << std::endl;
        }
    }
}

int* RamBasedNetwork::makeScore(RamBasedDiscriminator *ramClass, RamBasedDiscriminator *imageDiscriminator) {

    enum {WHITE, BLACK, OTHER};

    int *score = new int[3];
    score[WHITE] = 0;
    score[BLACK] = 0;
    score[OTHER] = 0;

    if (ramClass->getTuplesCount() != imageDiscriminator->getTuplesCount()) {

        std::cout << "Tuple size not same! Check discriminators!";
        exit(-1);
    }

    int count = ramClass->getTuplesCount();

    for (int i = 0; i < count; i++) {

        if (ramClass->getValue(i) == imageDiscriminator->getValue(i)) {

            if (imageDiscriminator->getValue(i) == (pow(2,ramClass->getTupleSize()) - 1) ) {
                score[WHITE]++;
            } else if (imageDiscriminator->getValue(i) == 0) {
                score[BLACK]++;
            } else {
                score[OTHER]++;
            }
        }
    }

    return score;
}

RamBasedNetwork::~RamBasedNetwork() {

}

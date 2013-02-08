#include "rambasedprocess.h"

RamBasedProcess::RamBasedProcess(int tupleSize) {

    network = new RamBasedNetwork();
    statNum = 0;
    this->tupleSize = tupleSize;

    string classes_temp[class_count] = {"far_center", "far_left", "far_right", "near_center", "near_left", "near_right"};

    //TODO: Need to be setted from config files
    int black[class_count] = {2, 2, 3, 8, 6, 8};
    int white[class_count] = {300, 300, 300, 300, 300, 300};


    for (int i = 0; i < class_count; i++) {

        classes[i].append(classes_temp[i].c_str());
        thresholds[i].name = classes_temp[i];
        thresholds[i].Ts = tupleSize;
        thresholds[i].black = black[i];
        thresholds[i].white = white[i];
    }

}

bool RamBasedProcess::loadImage(string path) {

    img = cvLoadImage(path.c_str(), 0);
    cvThreshold(img, img, 30, 255, CV_THRESH_BINARY);
    network->show(img);

    if(img == 0) {

        return false;
    }

    return true;
}

bool RamBasedProcess::loadImage(IplImage *src_img) {
//    cout<<"Img was load"<<endl;

    img = cvCreateImage(cvSize(src_img->width, src_img->height), 8, 1);
    cvCopy(src_img, img);

    network->show(img);

    if(img == 0) {

        return false;
    }

    return true;

}

int* RamBasedProcess::process(string className) {

    if(img == 0) {

        return 0;
    }

    tupleCount = ( img->width * img->height ) / tupleSize;
    RamBasedDiscriminator *tuple = new RamBasedDiscriminator(tupleSize, tupleCount, className);
    tuple->load();

    RamBasedDiscriminator *imgTuple = new RamBasedDiscriminator(tupleSize, tupleCount);
    network->makeTuples(&imgTuple, img);

    return network->makeScore(tuple, imgTuple);
}

bool RamBasedProcess::processAll()
{

    for(int i = 0; i < class_count; i++) {

        if( (results[i] = process(classes[i])) == 0 ) {

            return false;
        }
    }

    // Оценка победителя
    // TODO Вынести в отдельный метод или класс

    for(int i = 0; i < class_count; i++) {

        cout << "\t" << classes[i] << " " << results[i][0]
                                   << " " << results[i][1]
                                   << " " << results[i][2] << endl;
    }

    return true;
}

string RamBasedProcess::estimate() {

    string str = "";
    int max_i = -1;
    int max = -1;
    for (int i = 0; i < class_count; i++) {

        if (results[i][0] >= thresholds[i].white && results[i][1] >= thresholds[i].black) {

            if ( results[i][1] > max ) {
                max = results[i][1];
                max_i = i;
            }

        }
    }

    if (max_i > 0) {

        cout << classes[max_i] << " " << results[max_i][0]
                                   << " " << results[max_i][1];
        return classes[max_i];
    } else {
        return str;
    }
}

bool RamBasedProcess::saveResult(string dir) {

    // TODO: added save path into parameters

    QString path = "%1%2stat%3.txt";
    path = path.arg(PATH).arg(dir.c_str()).arg(statNum);
    std::cout << "I save to: " << path.toStdString();
    std::ofstream file(path.toStdString().c_str());

    for (int i = 0; i < class_count; i++) {

        file << classes[i] << " " << results[i][0]
                           << " " << results[i][1]
                           << " " << results[i][2]
                           << std::endl;
    }

    file << std::endl;
    file.close();
    statNum++;

    std::cout << " saved." << std::endl;

    return true;
}

#include "ImageProcess.h"

imageprocessing::ImageProcess::ImageProcess() {

}

IplImage* imageprocessing::ImageProcess::QImageToIplImage(QImage *qImg) {

    IplImage *tempImg;
    tempImg = cvCreateImage(cvSize(qImg->width(), qImg->height()), 8, 4);
    tempImg->imageData = (char*)qImg->bits();

    IplImage *resImg;
    resImg = cvCreateImage(cvGetSize(tempImg), 8, 3);
    cvConvertImage(tempImg, resImg);

    cvReleaseImage ( &tempImg );
    if(resImg->imageSize <= 0) {
        return NULL;
    }
    return resImg;
}

QImage* imageprocessing::ImageProcess::IplImageToQImage(IplImage *iplImg) {
    QImage *qimg;

    cvCvtColor(iplImg, iplImg, CV_BGR2RGB);
    qimg = new QImage((uchar *)iplImg->imageData, iplImg->width, iplImg->height, QImage::Format_RGB888);

    if (img == NULL) {
        return NULL;
    }
    else {
        return qimg;
    }
}

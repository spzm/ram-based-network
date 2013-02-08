#ifndef IMAGEPROCESS_H
#define IMAGEPROCESS_H

#include <QImage>
#include <opencv/cv.h>
#include <opencv/highgui.h>

namespace imageprocessing {

class ImageProcess
{
public:
    ImageProcess();

    IplImage* QImageToIplImage(QImage *qImg);
    QImage* IplImageToQImage(IplImage *iplImg);

};

} // namespace imageprocessing end

#endif // IMAGEPROCESS_H

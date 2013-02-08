#ifndef IMAGECAPTURE_H
#define IMAGECAPTURE_H

#include "opencv/cv.h"
#include "opencv/highgui.h"

#include <QString>

#include <iostream>
#include <map>
#include <string>

namespace imageprocessing {

using namespace std;

class ImageCapture
{
private:
    typedef map<string, IplImage*>::iterator sectorsIterator;
    typedef map<string, IplImage*> sectormap;
    sectormap sectors;
    map<string, CvRect> sectorSizes;

    IplImage *cameraImage;
    IplImage *monochromeImage;
    IplImage *resizedImage;
    CvSize captureImageSize, resizedImageSize;
    int emptySpace;
    int height;

    CvCapture *camera;
    int cameraId;

    bool CameraInit();
    bool GrabImage();
    bool ResizeImage();
    bool FilterImage();
    bool DivideToSectors();

public:

//    void DrawLines(IplImage *img);
//    void FileCapture(std::string path);

    bool AddSector(string name, CvPoint coordinate, CvSize size);
    bool DeleteSector(string name);

    map<string, IplImage*> GetCameraImage( );


    ImageCapture(int camId = 0);
	~ImageCapture(void);
};

} // namespace imageprocessing end


#endif // IMAGECAPTURE_H


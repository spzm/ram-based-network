#include "ImageCapture.h"


// TODO add some settings class

imageprocessing::ImageCapture::ImageCapture(int camId) {
    captureImageSize = cvSize(320,240);
    resizedImageSize = cvSize(80, 40);
    cameraImage = cvCreateImage( captureImageSize, 8, 3 );
    resizedImage = cvCreateImage( resizedImageSize, 8, 3 );
    camera = 0;
    cameraId = camId;
    if ( !CameraInit() ) {
        std::cerr << "ImageCapture: Camera init error.";
//        throw err;
    }

    monochromeImage = cvCreateImage( resizedImageSize, 8, 1);

    emptySpace = 40;
    height = cameraImage->height / 4;

}

bool imageprocessing::ImageCapture::CameraInit() {
    if (cameraId >= 0) {
        // if no camera cupture now - create it
        camera = cvCreateCameraCapture(cameraId);
        // If success - set camera proporities
        if (camera) {
            cvSetCaptureProperty(camera, CV_CAP_PROP_FRAME_WIDTH, cameraImage->width);
            cvSetCaptureProperty(camera, CV_CAP_PROP_FRAME_HEIGHT, cameraImage->height);
            cvSetCaptureProperty(camera, CV_CAP_PROP_FPS, 30);

            return true;
        }
    }
    return false;
}

bool imageprocessing::ImageCapture::AddSector(string name, CvPoint coordinate, CvSize size) {
    if (name.length() > 0) {

        if (coordinate.x > resizedImageSize.width || coordinate.y > resizedImageSize.height ||
                coordinate.x > (resizedImageSize.width + size.width) ||
                coordinate.y > (resizedImageSize.height + size.height)) {
            cerr << "ImageCapture: Incorect Sector size.";
            return false;
        }

        sectorsIterator iter = sectors.find(name);
        if (iter == sectors.end()) {
            sectors[name] = cvCreateImage(size, 8, 1);
            if (sectors[name] == NULL) {
                cerr << "ImageCapture: Incorect Sector size.";
                return false;
            }
        }
        else {
            cerr << "ImageCapture: Sector with this name already exist.";
            return false;
        }

        sectorSizes[name] = cvRect(coordinate.x, coordinate.y, size.width, size.width);

        return true;
    }

    return false;

}

bool imageprocessing::ImageCapture::DeleteSector(string name) {
    if (sectors[name] != NULL) {
        cvReleaseImage( &sectors[name] );
        sectors.erase(name);
    }
    
    return true;
}

bool imageprocessing::ImageCapture::GrabImage() {
    if ( camera != 0 ) {
        if( !cvGrabFrame( camera )) {

            std::cerr << "ImageCapture: Grab frame error";
            return false;
        }
        // Retrieve image
        if ((cameraImage = cvRetrieveFrame (camera)) != NULL) {
            std::cerr << "ImageCapture: Retrieve frame error";
            return true;
        }
    }

    return false;
}

bool imageprocessing::ImageCapture::ResizeImage() {
    // Cut not important parts of the image
    cvSetImageROI(cameraImage, cvRect(0, height*2 - emptySpace, cameraImage->width ,cameraImage->height/2));
    // Resize image for future processing
    cvResize(cameraImage, resizedImage);

    return true;
}

bool imageprocessing::ImageCapture::FilterImage() {
    QString st = cameraImage->colorModel;
    if(st == "RGB") {
        cvCvtColor(resizedImage, monochromeImage, CV_RGB2GRAY);
    } else {
        cvCvtColor(resizedImage, monochromeImage, CV_BGR2GRAY);
    }
    // Image binorizing
    cvThreshold(monochromeImage, monochromeImage, 50, 255, CV_THRESH_BINARY);

    return true;
}

bool imageprocessing::ImageCapture::DivideToSectors() {
    // Will happy coding :)

    return true;
}

imageprocessing::ImageCapture::sectormap imageprocessing::ImageCapture::GetCameraImage() {

    if (sectors.size() > 0) {

        bool flag;
        flag = GrabImage();
        if (!flag) {
            sectormap temp;
            temp[string("no")] = NULL;
            return temp;
        }

        flag = ResizeImage();
        if (!flag) {
            sectormap temp;
            temp[string("no")] = NULL;
            return temp;
        }

        flag = FilterImage();
        if (!flag) {
            sectormap temp;
            temp[string("no")] = NULL;
            return temp;
        }

         for (sectorsIterator iter = sectors.begin(); iter != sectors.end(); ++iter) {
            // Set ROI for all sectors
            cvSetImageROI(monochromeImage, sectorSizes[iter->first]);
            // Save part of the sector image
            cvCopy(monochromeImage,iter->second);
            cvResetImageROI(monochromeImage);
        }

        return sectors;
    }
    else {
        sectormap temp;
        temp[string("no")] = NULL;
        return temp;
    }
}

imageprocessing::ImageCapture::~ImageCapture(void) {
    if (cameraImage != 0) {
        cvReleaseImage ( &cameraImage );
    }
    if (resizedImage != 0) {
        cvReleaseImage ( &resizedImage );
    }
    if (monochromeImage != 0) {
        cvReleaseImage ( &monochromeImage );
    }
    if (camera != 0) {
        cvReleaseCapture( &camera );
    }
}


//void imageprocessing::ImageCapture::DrawLines(IplImage *img)
//{

//    cvLine(img, cvPoint(0,height*2 - empty_space), cvPoint(img->width,height*2 - empty_space), CV_RGB(0,255,0));

//    cvLine(img, cvPoint(0,height*3 - empty_space), cvPoint(img->width,height*3 -empty_space), CV_RGB(0,255,0));

//    cvLine(img, cvPoint(0,img->height - empty_space), cvPoint(img->width,img->height - empty_space), CV_RGB(0,255,0));


//    cvLine(img, cvPoint(img->width/3,img->height - empty_space), cvPoint(img->width/3,height*2 - empty_space), CV_RGB(0,255,0));
//    cvLine(img, cvPoint((img->width/3)*2,img->height - empty_space), cvPoint((img->width/3)*2,height*2 - empty_space), CV_RGB(0,255,0));

//}

//void imageprocessing::ImageCapture::FileCapture(std::string path) {

//    img = cvLoadImage(path.c_str());
//    if(!img)
//    {
//        return;
//    }

//    cvResize(img, tempImg);

//    cvShowImage("Main", img);

//    QString st = img->colorModel;
//    if(st == "RGB") {
//        cvCvtColor(tempImg, gray, CV_RGB2GRAY);
//    } else {
//        cvCvtColor(tempImg, gray, CV_BGR2GRAY);
//    }

//    cvShowImage("Gray", gray);

//    cvThreshold(gray, gray, 30, 255, CV_THRESH_BINARY);

//    cvShowImage("Binary", gray);

//    cvWaitKey(0);
//}

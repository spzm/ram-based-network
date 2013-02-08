#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QHttp>
#include <QMessageBox>
#include <QThread>
#include <QString>
#include "opencv/cv.h"
#include "opencv/highgui.h"

#include <vector>
#include <iostream>

#include "src/lib/Image/ImageCapture.h"
//#include "src/lib/RAM/rambasedprocess.h"
//#include "src/lib/RAM/rambasedstudy.h"
//#include "src/lib/RAM/rambaseddiscriminator.h"
#include "src/lib/Robot/robotcontrol.h"



using namespace std;
using namespace robot;
using namespace imageprocessing;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void StartCapture();
    void StudyNetwork();
    void LoadImage();
    void ShowDiscriminator();    
    void SetSizes();
//    void CalculateImagesDiscriminators(int count, vector<string> classes);
    void TrainWithAllTupleSizes();
    void RobotTurnSearch();

private:
//    bool QImageToIplImage(QImage *qImg);

    int height;
    int width;
    int tupleSize;

    IplImage *tempImg;
    IplImage *resImg;

    QString st;
    Ui::MainWindow *ui;
    QImage camImg;    

//    RamBasedStudy studyNN;
//    RamBasedDiscriminator *tuple;

    ImageCapture *camCapture;
    RobotControl robot;
    bool robotMove;

//    void CalculateImagesSetDiscriminators(int count, vector<string> classes);

};

#endif // MAINWINDOW_H

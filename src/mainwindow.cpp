#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
                       QMainWindow(parent),
                       ui(new Ui::MainWindow) {

    ui->setupUi(this);
    QStringList itemsList;
    itemsList << "far_center" << "far_left" << "far_right"
              << "near_center" << "near_left" << "near_right" << "empty";
    ui->cmbClass->addItems(itemsList);

    height = 40;
    width = 80;

    tupleSize = 8;

    ui->lnePathToImg->setText(QApplication::applicationDirPath() + "/");

    camCapture = new ImageCapture();

    robotMove = false;
    robot.robotConnect();


//    tempImg = cvCreateImage(cvSize(80,40), 8, 1);
}


void MainWindow::StudyNetwork() {

//    studyNN.loadImage(ui->lnePathToImg->text().toStdString());
//    studyNN.studyClass(ui->cmbClass->currentText().toStdString());
}


void MainWindow::LoadImage() {

    QImage img(ui->lnePathToImg->text());

    if( !img.isNull() )  {
        ui->Cam->setPixmap(QPixmap::fromImage(img));
    }
}


void MainWindow::ShowDiscriminator() {

    // TODO Must automatic reading
//    tuple = new RamBasedDiscriminator(tupleSize, height * width, ui->cmbClass->currentText().toStdString());
//    tuple->load();

//    cout << ui->cmbClass->currentText().toStdString() << endl;

//    for (int i = 1; i <= tuple->getTuplesCount(); i++) {

//        cout << tuple->getValue(i - 1) << " ";

//        if ((i % 10) == 0) {
//            cout << endl;
//        }
//    }

//    cout << endl;

//    delete tuple;
}

void MainWindow::SetSizes() {

    // TODO: Need to check sizes
//    width = ui->lneWidth->text().toUInt();
//    height = ui->lneHeight->text().toUInt();
//    tupleSize = ui->lneTupleSize->text().toUInt();

//    cout << "Width setted to: " << width << endl;
//    cout << "Height setted to: " << height << endl;
//    cout << "Tuple size setted to: " << tupleSize << endl;
}

/*
 * Experiment 2. Вычисляем дискриминаторы для всех изображений обучающей и тестируемой выборок
 *
 */
//void MainWindow::CalculateImagesDiscriminators(int count, vector<string> classes) {

//    const char* classes_args[] = {"far_center", "far_left", "far_right", "near_center", "near_left", "near_right"};
//    vector<string> classes_temp(classes_args, classes_args + sizeof(classes_args) / sizeof(classes_args[0]));
//    CalculateImagesSetDiscriminators(20, classes_temp);

//    const char* falses_args[] = {"false_black_box", "false_object", "false_orange"};
//    vector<string> falses_temp(falses_args, falses_args + sizeof(falses_args) / sizeof(falses_args[0]));
//    CalculateImagesSetDiscriminators(10, falses_temp);

//    vector<string> true_temp;
//    true_temp.push_back( string("true_random") );
//    CalculateImagesSetDiscriminators(30, true_temp);

//}

/*
 * Вычисление дискриминаторов для count изображений в папках вектора classes
 *
 */
//void MainWindow::CalculateImagesSetDiscriminators(int count, vector<string> classes) {

//    QString path = "/media/sp/data/Dropbox/code/qtcreator_workspace/ram2/results/images/";
//    QString save_path = "results/%1/%2/";

//    static const int args[] = {1, 2, 4, 6, 8, 10, 12, 16, 20};
//    vector<int> tuple_sizes(args, args + sizeof(args) / sizeof(args[0]) );

//    // Вычисляем дискриминаторы для верных образов
//    while (tuple_sizes.size() > 0) {

//        vector<string> tmp_classes(classes);

//        while ( tmp_classes.size() > 0 ) {

//            int size = tuple_sizes.back();
//            RamBasedProcess ramNN(size);

//            string folder_name = tmp_classes.back();

//            for (int j = 0; j < count; j++) {

//                QString file = "%1%2/binary%3.jpg";

//                QString tmp_path = file.arg(path).arg(folder_name.c_str()).arg(j);

//                cout << tmp_path.toStdString() << std::endl;

//                ramNN.loadImage(tmp_path.toStdString());
//                ramNN.processAll();

//                cout << save_path.arg(size).arg(folder_name.c_str()).toStdString() << std::endl;
//                ramNN.saveResult(save_path.arg(size).arg(folder_name.c_str()).toStdString());

//            }

//            tmp_classes.pop_back();

//        }

//        tuple_sizes.pop_back();
//    }

//}

/*
 * Обучаем дискриминаторы для разных размеров картежей
 *
 */
void MainWindow::TrainWithAllTupleSizes() {

//    // Количество тестируемых размерностей кортежей
//    const int tupleCount = 9;
//    // Количество классов секторов детектирования
//    const int classesCount = 6;
//    // Размеры кортежей
//    int sizes[tupleCount] = {1, 2, 4, 6, 8, 10, 12, 16, 20};
//    // Классы секторов
//    string classes_temp[classesCount] = {"far_center", "far_left", "far_right", "near_center", "near_left", "near_right"};

//    QString image_path = "/media/data/Dropbox/code/qtcreator_workspace/ram2/training_set/%1.png";

//    for (int i = 0; i < tupleCount; i++) {

//        for (int j = 0; j < classesCount; j++) {

//            QString path = image_path.arg(classes_temp[j].c_str());
//            studyNN.loadImage(path.toStdString());
//            studyNN.studyClass(classes_temp[j], sizes[i]);
//        }
//    }

}

/*
 * Experiment 2. Робот поворачивается, одновременно совершая поиск ведущего
 *
 */
void MainWindow::RobotTurnSearch() {

//    if (robotMove) {

//        robot.stop();
//        robotMove = false;
//    } else {

//        robot.move(50,-50);
//        robotMove = true;
//        ImageCapture robotCamera = ImageCapture(6);
//        RamBasedProcess robotBrain(6);
//        string winner;

//        while (1) {
//            IplImage *image = robotCamera.GetCameraImage();
//            cout << "a" << endl;
//            robotBrain.loadImage(image);
//            robotBrain.processAll();
//            winner = robotBrain.estimate();

//            if (winner != "") {

//                robot.stop();
//                cout << "Winner: " << winner << endl;
//                break;
//            }

//            cvReleaseImage(&image);
//        }


//    }
}

void MainWindow::StartCapture() {

//    camCapture->CameraCapture();
}

/*bool MainWindow::QImageToIplImage(QImage *qImg) {

    tempImg = cvCreateImage(cvSize(qImg->width(), qImg->height()), 8, 4);
    tempImg->imageData = (char*)qImg->bits();

    resImg = cvCreateImage(cvGetSize(tempImg), 8, 3);
    cvConvertImage(tempImg, resImg);
    if(resImg->imageSize <= 0) {

        return false;
    }

    return true;
}*/


MainWindow::~MainWindow()
{
    delete camCapture;
    delete ui;
}

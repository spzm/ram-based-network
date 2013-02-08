/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Thu Jan 17 23:31:36 2013
**      by: Qt User Interface Compiler version 4.8.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_3;
    QLabel *Cam;
    QSpacerItem *verticalSpacer_2;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QComboBox *cmbClass;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *lnePathToImg;
    QPushButton *btnLoad;
    QPushButton *btnStudy;
    QPushButton *btnShowDiscriminator;
    QPushButton *btnTrainWithAllTupleSizes;
    QSpacerItem *verticalSpacer_3;
    QPushButton *btnCapture;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_4;
    QLineEdit *lneWidth;
    QLabel *label_3;
    QLineEdit *lneHeight;
    QLabel *label_5;
    QLineEdit *lneTupleSize;
    QPushButton *btnSetSizes;
    QSpacerItem *verticalSpacer;
    QPushButton *btnExperiment1;
    QPushButton *btnExperiment2;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QToolBar *toolBar;
    QToolBar *toolBar_2;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(685, 388);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        Cam = new QLabel(centralWidget);
        Cam->setObjectName(QString::fromUtf8("Cam"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Cam->sizePolicy().hasHeightForWidth());
        Cam->setSizePolicy(sizePolicy);
        Cam->setMinimumSize(QSize(352, 240));
        Cam->setFrameShape(QFrame::Panel);

        verticalLayout_3->addWidget(Cam);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_2);


        horizontalLayout->addLayout(verticalLayout_3);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);

        cmbClass = new QComboBox(centralWidget);
        cmbClass->setObjectName(QString::fromUtf8("cmbClass"));

        verticalLayout->addWidget(cmbClass);

        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout->addWidget(label_2);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        lnePathToImg = new QLineEdit(centralWidget);
        lnePathToImg->setObjectName(QString::fromUtf8("lnePathToImg"));

        horizontalLayout_2->addWidget(lnePathToImg);

        btnLoad = new QPushButton(centralWidget);
        btnLoad->setObjectName(QString::fromUtf8("btnLoad"));
        btnLoad->setMaximumSize(QSize(50, 16777215));

        horizontalLayout_2->addWidget(btnLoad);


        verticalLayout->addLayout(horizontalLayout_2);

        btnStudy = new QPushButton(centralWidget);
        btnStudy->setObjectName(QString::fromUtf8("btnStudy"));

        verticalLayout->addWidget(btnStudy);

        btnShowDiscriminator = new QPushButton(centralWidget);
        btnShowDiscriminator->setObjectName(QString::fromUtf8("btnShowDiscriminator"));

        verticalLayout->addWidget(btnShowDiscriminator);

        btnTrainWithAllTupleSizes = new QPushButton(centralWidget);
        btnTrainWithAllTupleSizes->setObjectName(QString::fromUtf8("btnTrainWithAllTupleSizes"));

        verticalLayout->addWidget(btnTrainWithAllTupleSizes);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_3);

        btnCapture = new QPushButton(centralWidget);
        btnCapture->setObjectName(QString::fromUtf8("btnCapture"));

        verticalLayout->addWidget(btnCapture);


        horizontalLayout->addLayout(verticalLayout);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        verticalLayout_2->addWidget(label_4);

        lneWidth = new QLineEdit(centralWidget);
        lneWidth->setObjectName(QString::fromUtf8("lneWidth"));

        verticalLayout_2->addWidget(lneWidth);

        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout_2->addWidget(label_3);

        lneHeight = new QLineEdit(centralWidget);
        lneHeight->setObjectName(QString::fromUtf8("lneHeight"));

        verticalLayout_2->addWidget(lneHeight);

        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        verticalLayout_2->addWidget(label_5);

        lneTupleSize = new QLineEdit(centralWidget);
        lneTupleSize->setObjectName(QString::fromUtf8("lneTupleSize"));

        verticalLayout_2->addWidget(lneTupleSize);

        btnSetSizes = new QPushButton(centralWidget);
        btnSetSizes->setObjectName(QString::fromUtf8("btnSetSizes"));

        verticalLayout_2->addWidget(btnSetSizes);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);

        btnExperiment1 = new QPushButton(centralWidget);
        btnExperiment1->setObjectName(QString::fromUtf8("btnExperiment1"));

        verticalLayout_2->addWidget(btnExperiment1);

        btnExperiment2 = new QPushButton(centralWidget);
        btnExperiment2->setObjectName(QString::fromUtf8("btnExperiment2"));

        verticalLayout_2->addWidget(btnExperiment2);


        horizontalLayout->addLayout(verticalLayout_2);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 685, 25));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);
        toolBar_2 = new QToolBar(MainWindow);
        toolBar_2->setObjectName(QString::fromUtf8("toolBar_2"));
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar_2);

        retranslateUi(MainWindow);
        QObject::connect(btnCapture, SIGNAL(clicked()), MainWindow, SLOT(StartCapture()));
        QObject::connect(btnStudy, SIGNAL(clicked()), MainWindow, SLOT(StudyNetwork()));
        QObject::connect(btnLoad, SIGNAL(clicked()), MainWindow, SLOT(LoadImage()));
        QObject::connect(btnShowDiscriminator, SIGNAL(clicked()), MainWindow, SLOT(ShowDiscriminator()));
        QObject::connect(btnSetSizes, SIGNAL(clicked()), MainWindow, SLOT(SetSizes()));
        QObject::connect(btnExperiment1, SIGNAL(clicked()), MainWindow, SLOT(CalculateImagesDiscriminators()));
        QObject::connect(btnTrainWithAllTupleSizes, SIGNAL(clicked()), MainWindow, SLOT(TrainWithAllTupleSizes()));
        QObject::connect(btnExperiment2, SIGNAL(clicked()), MainWindow, SLOT(RobotTurnSearch()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        Cam->setText(QApplication::translate("MainWindow", "cam", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindow", "Class of pattern", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MainWindow", "Path to image", 0, QApplication::UnicodeUTF8));
        btnLoad->setText(QApplication::translate("MainWindow", "Load ", 0, QApplication::UnicodeUTF8));
        btnStudy->setText(QApplication::translate("MainWindow", "Study network", 0, QApplication::UnicodeUTF8));
        btnShowDiscriminator->setText(QApplication::translate("MainWindow", "Show discriminator", 0, QApplication::UnicodeUTF8));
        btnTrainWithAllTupleSizes->setText(QApplication::translate("MainWindow", "Train with all tuple sizes", 0, QApplication::UnicodeUTF8));
        btnCapture->setText(QApplication::translate("MainWindow", "Start capture", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("MainWindow", " Width ", 0, QApplication::UnicodeUTF8));
        lneWidth->setText(QApplication::translate("MainWindow", "80", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("MainWindow", "Height", 0, QApplication::UnicodeUTF8));
        lneHeight->setText(QApplication::translate("MainWindow", "40", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("MainWindow", "Tuples Size", 0, QApplication::UnicodeUTF8));
        lneTupleSize->setText(QApplication::translate("MainWindow", "8", 0, QApplication::UnicodeUTF8));
        btnSetSizes->setText(QApplication::translate("MainWindow", "Set", 0, QApplication::UnicodeUTF8));
        btnExperiment1->setText(QApplication::translate("MainWindow", "Experiment 1", 0, QApplication::UnicodeUTF8));
        btnExperiment2->setText(QApplication::translate("MainWindow", "Experiment 2", 0, QApplication::UnicodeUTF8));
        toolBar->setWindowTitle(QApplication::translate("MainWindow", "toolBar", 0, QApplication::UnicodeUTF8));
        toolBar_2->setWindowTitle(QApplication::translate("MainWindow", "toolBar_2", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

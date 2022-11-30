/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QWidget *widget;
    QLineEdit *cityLineEdit;
    QLabel *dateLable;
    QFrame *Hline_1;
    QFrame *Hline_2;
    QFrame *Hline_3;
    QLabel *label;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLabel *flTitleLb;
    QLabel *shiduTitleLb_2;
    QLabel *fxTitleLb;
    QLabel *pm25TilleLb;
    QLabel *shiduLb;
    QLabel *pm25Lb;
    QLabel *fxLb;
    QLabel *flLb;
    QWidget *gridLayoutWidget_3;
    QGridLayout *gridLayout_9;
    QGridLayout *gridLayout_2;
    QLabel *quality3Lb;
    QLabel *high3Lb;
    QLabel *type5Lb;
    QLabel *high5Lb;
    QLabel *typeIco5Lb;
    QLabel *quality1Lb;
    QLabel *type0Lb;
    QLabel *low0Lb;
    QLabel *date1Lb;
    QLabel *low4Lb;
    QLabel *type3Lb;
    QLabel *date0Lb;
    QLabel *type4Lb;
    QLabel *date3Lb;
    QLabel *quality0Lb;
    QLabel *quality5Lb;
    QLabel *typeIco3Lb;
    QLabel *low2Lb;
    QLabel *week4Lb;
    QLabel *low5Lb;
    QLabel *typeIco0Lb;
    QLabel *date5Lb;
    QLabel *typeIco2Lb;
    QLabel *week3Lb;
    QLabel *low1Lb;
    QLabel *typeIco4Lb;
    QLabel *type1Lb;
    QLabel *week0Lb;
    QLabel *high2Lb;
    QLabel *quality2Lb;
    QLabel *high1Lb;
    QLabel *week1Lb;
    QLabel *type2Lb;
    QLabel *quality4Lb;
    QLabel *date4Lb;
    QLabel *high0Lb;
    QLabel *week2Lb;
    QLabel *high4Lb;
    QLabel *date2Lb;
    QLabel *week5Lb;
    QLabel *low3Lb;
    QLabel *typeIco1Lb;
    QLabel *curveLb;
    QWidget *gridLayoutWidget_4;
    QGridLayout *gridLayout_12;
    QLabel *label_39;
    QLabel *cityLb;
    QLabel *leafLb;
    QLabel *qualityLb;
    QLabel *temLb;
    QLabel *typeLb;
    QLabel *typeIcoLb;
    QLabel *noticeLb;
    QWidget *gridLayoutWidget_5;
    QGridLayout *gridLayout_13;
    QLabel *label_7;
    QTextBrowser *gangmaoBrowser;
    QFrame *vLine1;
    QToolButton *searchBtn;
    QToolButton *refreshBtn;
    QLabel *sunriseLb;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QLabel *label_18;

    void setupUi(QWidget *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 450);
        MainWindow->setCursor(QCursor(Qt::PointingHandCursor));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        centralWidget->setGeometry(QRect(0, 0, 800, 450));
        widget = new QWidget(centralWidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(0, 0, 800, 450));
        widget->setStyleSheet(QString::fromUtf8("QWidget#widget{\n"
"	border-image: url(:/weaUI/weaUI.png);\n"
"	color:rgb(255, 255, 255);\n"
"}\n"
"\n"
"QLabel{\n"
"	font: 25 10pt \"Microsoft YaHei\";\n"
"	border-radius: 4px;\n"
"	background-color: argb(60, 60, 60, 130);\n"
"	color: rgb(255, 255, 255);\n"
"}\n"
"\n"
"Line{\n"
"	background-color: rgb(0, 85, 0);\n"
"}\n"
"\n"
"\n"
"\n"
""));
        cityLineEdit = new QLineEdit(widget);
        cityLineEdit->setObjectName(QString::fromUtf8("cityLineEdit"));
        cityLineEdit->setGeometry(QRect(570, 10, 171, 31));
        dateLable = new QLabel(widget);
        dateLable->setObjectName(QString::fromUtf8("dateLable"));
        dateLable->setGeometry(QRect(250, 3, 321, 41));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(20);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(50);
        dateLable->setFont(font);
        dateLable->setStyleSheet(QString::fromUtf8("font: 20pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        dateLable->setAlignment(Qt::AlignCenter);
        Hline_1 = new QFrame(widget);
        Hline_1->setObjectName(QString::fromUtf8("Hline_1"));
        Hline_1->setGeometry(QRect(10, 45, 781, 1));
        Hline_1->setFrameShape(QFrame::HLine);
        Hline_1->setFrameShadow(QFrame::Sunken);
        Hline_2 = new QFrame(widget);
        Hline_2->setObjectName(QString::fromUtf8("Hline_2"));
        Hline_2->setGeometry(QRect(10, 183, 351, 1));
        Hline_2->setFrameShape(QFrame::HLine);
        Hline_2->setFrameShadow(QFrame::Sunken);
        Hline_3 = new QFrame(widget);
        Hline_3->setObjectName(QString::fromUtf8("Hline_3"));
        Hline_3->setGeometry(QRect(10, 335, 351, 1));
        Hline_3->setFrameShape(QFrame::HLine);
        Hline_3->setFrameShadow(QFrame::Sunken);
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(80, 10, 141, 31));
        label->setStyleSheet(QString::fromUtf8("font: 20pt \"\345\215\216\346\226\207\347\220\245\347\217\200\";\n"
"background-color::rgba(255,255,255,0);\n"
"color: rgba(0,255,0,255)\n"
""));
        label->setFrameShadow(QFrame::Plain);
        label->setLineWidth(1);
        gridLayoutWidget = new QWidget(widget);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(10, 190, 351, 145));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        flTitleLb = new QLabel(gridLayoutWidget);
        flTitleLb->setObjectName(QString::fromUtf8("flTitleLb"));
        flTitleLb->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(flTitleLb, 3, 0, 1, 1);

        shiduTitleLb_2 = new QLabel(gridLayoutWidget);
        shiduTitleLb_2->setObjectName(QString::fromUtf8("shiduTitleLb_2"));
        shiduTitleLb_2->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(shiduTitleLb_2, 0, 0, 1, 1);

        fxTitleLb = new QLabel(gridLayoutWidget);
        fxTitleLb->setObjectName(QString::fromUtf8("fxTitleLb"));
        fxTitleLb->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(fxTitleLb, 2, 0, 1, 1);

        pm25TilleLb = new QLabel(gridLayoutWidget);
        pm25TilleLb->setObjectName(QString::fromUtf8("pm25TilleLb"));
        pm25TilleLb->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(pm25TilleLb, 1, 0, 1, 1);

        shiduLb = new QLabel(gridLayoutWidget);
        shiduLb->setObjectName(QString::fromUtf8("shiduLb"));
        shiduLb->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(shiduLb, 0, 1, 1, 2);

        pm25Lb = new QLabel(gridLayoutWidget);
        pm25Lb->setObjectName(QString::fromUtf8("pm25Lb"));
        pm25Lb->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(pm25Lb, 1, 1, 1, 2);

        fxLb = new QLabel(gridLayoutWidget);
        fxLb->setObjectName(QString::fromUtf8("fxLb"));
        fxLb->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(fxLb, 2, 1, 1, 2);

        flLb = new QLabel(gridLayoutWidget);
        flLb->setObjectName(QString::fromUtf8("flLb"));
        flLb->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(flLb, 3, 1, 1, 2);

        gridLayoutWidget_3 = new QWidget(widget);
        gridLayoutWidget_3->setObjectName(QString::fromUtf8("gridLayoutWidget_3"));
        gridLayoutWidget_3->setGeometry(QRect(360, 50, 440, 391));
        gridLayout_9 = new QGridLayout(gridLayoutWidget_3);
        gridLayout_9->setSpacing(6);
        gridLayout_9->setContentsMargins(11, 11, 11, 11);
        gridLayout_9->setObjectName(QString::fromUtf8("gridLayout_9"));
        gridLayout_9->setContentsMargins(0, 0, 0, 0);
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setHorizontalSpacing(2);
        gridLayout_2->setVerticalSpacing(0);
        quality3Lb = new QLabel(gridLayoutWidget_3);
        quality3Lb->setObjectName(QString::fromUtf8("quality3Lb"));
        quality3Lb->setStyleSheet(QString::fromUtf8("color:rgb(255,100,0);"));
        quality3Lb->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(quality3Lb, 2, 3, 1, 1);

        high3Lb = new QLabel(gridLayoutWidget_3);
        high3Lb->setObjectName(QString::fromUtf8("high3Lb"));
        high3Lb->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(high3Lb, 6, 3, 1, 1);

        type5Lb = new QLabel(gridLayoutWidget_3);
        type5Lb->setObjectName(QString::fromUtf8("type5Lb"));
        type5Lb->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(type5Lb, 3, 5, 1, 1);

        high5Lb = new QLabel(gridLayoutWidget_3);
        high5Lb->setObjectName(QString::fromUtf8("high5Lb"));
        high5Lb->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(high5Lb, 6, 5, 1, 1);

        typeIco5Lb = new QLabel(gridLayoutWidget_3);
        typeIco5Lb->setObjectName(QString::fromUtf8("typeIco5Lb"));
        typeIco5Lb->setStyleSheet(QString::fromUtf8("image:url(:/day/day/\345\260\217\351\233\250.png);"));
        typeIco5Lb->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(typeIco5Lb, 4, 5, 2, 1);

        quality1Lb = new QLabel(gridLayoutWidget_3);
        quality1Lb->setObjectName(QString::fromUtf8("quality1Lb"));
        quality1Lb->setStyleSheet(QString::fromUtf8("color:rgb(255,255,0)"));
        quality1Lb->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(quality1Lb, 2, 1, 1, 1);

        type0Lb = new QLabel(gridLayoutWidget_3);
        type0Lb->setObjectName(QString::fromUtf8("type0Lb"));
        type0Lb->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(type0Lb, 3, 0, 1, 1);

        low0Lb = new QLabel(gridLayoutWidget_3);
        low0Lb->setObjectName(QString::fromUtf8("low0Lb"));
        low0Lb->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(low0Lb, 10, 0, 1, 1);

        date1Lb = new QLabel(gridLayoutWidget_3);
        date1Lb->setObjectName(QString::fromUtf8("date1Lb"));
        date1Lb->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(date1Lb, 1, 1, 1, 1);

        low4Lb = new QLabel(gridLayoutWidget_3);
        low4Lb->setObjectName(QString::fromUtf8("low4Lb"));
        low4Lb->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(low4Lb, 10, 4, 1, 1);

        type3Lb = new QLabel(gridLayoutWidget_3);
        type3Lb->setObjectName(QString::fromUtf8("type3Lb"));
        type3Lb->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(type3Lb, 3, 3, 1, 1);

        date0Lb = new QLabel(gridLayoutWidget_3);
        date0Lb->setObjectName(QString::fromUtf8("date0Lb"));
        date0Lb->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(date0Lb, 1, 0, 1, 1);

        type4Lb = new QLabel(gridLayoutWidget_3);
        type4Lb->setObjectName(QString::fromUtf8("type4Lb"));
        type4Lb->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(type4Lb, 3, 4, 1, 1);

        date3Lb = new QLabel(gridLayoutWidget_3);
        date3Lb->setObjectName(QString::fromUtf8("date3Lb"));
        date3Lb->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(date3Lb, 1, 3, 1, 1);

        quality0Lb = new QLabel(gridLayoutWidget_3);
        quality0Lb->setObjectName(QString::fromUtf8("quality0Lb"));
        quality0Lb->setStyleSheet(QString::fromUtf8("color: rgb(0,170,0);"));
        quality0Lb->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(quality0Lb, 2, 0, 1, 1);

        quality5Lb = new QLabel(gridLayoutWidget_3);
        quality5Lb->setObjectName(QString::fromUtf8("quality5Lb"));
        quality5Lb->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(quality5Lb, 2, 5, 1, 1);

        typeIco3Lb = new QLabel(gridLayoutWidget_3);
        typeIco3Lb->setObjectName(QString::fromUtf8("typeIco3Lb"));
        typeIco3Lb->setStyleSheet(QString::fromUtf8("image:url(:/day/day/\345\260\217\351\233\250.png);\n"
""));
        typeIco3Lb->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(typeIco3Lb, 4, 3, 2, 1);

        low2Lb = new QLabel(gridLayoutWidget_3);
        low2Lb->setObjectName(QString::fromUtf8("low2Lb"));
        low2Lb->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(low2Lb, 10, 2, 1, 1);

        week4Lb = new QLabel(gridLayoutWidget_3);
        week4Lb->setObjectName(QString::fromUtf8("week4Lb"));
        week4Lb->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(week4Lb, 0, 4, 1, 1);

        low5Lb = new QLabel(gridLayoutWidget_3);
        low5Lb->setObjectName(QString::fromUtf8("low5Lb"));
        low5Lb->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(low5Lb, 10, 5, 1, 1);

        typeIco0Lb = new QLabel(gridLayoutWidget_3);
        typeIco0Lb->setObjectName(QString::fromUtf8("typeIco0Lb"));
        typeIco0Lb->setStyleSheet(QString::fromUtf8("image:url(:/day/day/\345\260\217\351\233\250.png);"));
        typeIco0Lb->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(typeIco0Lb, 4, 0, 2, 1);

        date5Lb = new QLabel(gridLayoutWidget_3);
        date5Lb->setObjectName(QString::fromUtf8("date5Lb"));
        date5Lb->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(date5Lb, 1, 5, 1, 1);

        typeIco2Lb = new QLabel(gridLayoutWidget_3);
        typeIco2Lb->setObjectName(QString::fromUtf8("typeIco2Lb"));
        typeIco2Lb->setStyleSheet(QString::fromUtf8("image:url(:/day/day/\345\260\217\351\233\250.png);"));
        typeIco2Lb->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(typeIco2Lb, 4, 2, 2, 1);

        week3Lb = new QLabel(gridLayoutWidget_3);
        week3Lb->setObjectName(QString::fromUtf8("week3Lb"));
        week3Lb->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(week3Lb, 0, 3, 1, 1);

        low1Lb = new QLabel(gridLayoutWidget_3);
        low1Lb->setObjectName(QString::fromUtf8("low1Lb"));
        low1Lb->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(low1Lb, 10, 1, 1, 1);

        typeIco4Lb = new QLabel(gridLayoutWidget_3);
        typeIco4Lb->setObjectName(QString::fromUtf8("typeIco4Lb"));
        typeIco4Lb->setStyleSheet(QString::fromUtf8("image:url(:/day/day/\345\260\217\351\233\250.png);"));
        typeIco4Lb->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(typeIco4Lb, 4, 4, 2, 1);

        type1Lb = new QLabel(gridLayoutWidget_3);
        type1Lb->setObjectName(QString::fromUtf8("type1Lb"));
        type1Lb->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(type1Lb, 3, 1, 1, 1);

        week0Lb = new QLabel(gridLayoutWidget_3);
        week0Lb->setObjectName(QString::fromUtf8("week0Lb"));
        week0Lb->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(week0Lb, 0, 0, 1, 1);

        high2Lb = new QLabel(gridLayoutWidget_3);
        high2Lb->setObjectName(QString::fromUtf8("high2Lb"));
        high2Lb->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(high2Lb, 6, 2, 1, 1);

        quality2Lb = new QLabel(gridLayoutWidget_3);
        quality2Lb->setObjectName(QString::fromUtf8("quality2Lb"));
        quality2Lb->setStyleSheet(QString::fromUtf8("color:rgb(255,170,0);"));
        quality2Lb->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(quality2Lb, 2, 2, 1, 1);

        high1Lb = new QLabel(gridLayoutWidget_3);
        high1Lb->setObjectName(QString::fromUtf8("high1Lb"));
        high1Lb->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(high1Lb, 6, 1, 1, 1);

        week1Lb = new QLabel(gridLayoutWidget_3);
        week1Lb->setObjectName(QString::fromUtf8("week1Lb"));
        week1Lb->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(week1Lb, 0, 1, 1, 1);

        type2Lb = new QLabel(gridLayoutWidget_3);
        type2Lb->setObjectName(QString::fromUtf8("type2Lb"));
        type2Lb->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(type2Lb, 3, 2, 1, 1);

        quality4Lb = new QLabel(gridLayoutWidget_3);
        quality4Lb->setObjectName(QString::fromUtf8("quality4Lb"));
        quality4Lb->setStyleSheet(QString::fromUtf8("color:rgb(255,0,0);"));
        quality4Lb->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(quality4Lb, 2, 4, 1, 1);

        date4Lb = new QLabel(gridLayoutWidget_3);
        date4Lb->setObjectName(QString::fromUtf8("date4Lb"));
        date4Lb->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(date4Lb, 1, 4, 1, 1);

        high0Lb = new QLabel(gridLayoutWidget_3);
        high0Lb->setObjectName(QString::fromUtf8("high0Lb"));
        high0Lb->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(high0Lb, 6, 0, 1, 1);

        week2Lb = new QLabel(gridLayoutWidget_3);
        week2Lb->setObjectName(QString::fromUtf8("week2Lb"));
        week2Lb->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(week2Lb, 0, 2, 1, 1);

        high4Lb = new QLabel(gridLayoutWidget_3);
        high4Lb->setObjectName(QString::fromUtf8("high4Lb"));
        high4Lb->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(high4Lb, 6, 4, 1, 1);

        date2Lb = new QLabel(gridLayoutWidget_3);
        date2Lb->setObjectName(QString::fromUtf8("date2Lb"));
        date2Lb->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(date2Lb, 1, 2, 1, 1);

        week5Lb = new QLabel(gridLayoutWidget_3);
        week5Lb->setObjectName(QString::fromUtf8("week5Lb"));
        week5Lb->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(week5Lb, 0, 5, 1, 1);

        low3Lb = new QLabel(gridLayoutWidget_3);
        low3Lb->setObjectName(QString::fromUtf8("low3Lb"));
        low3Lb->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(low3Lb, 10, 3, 1, 1);

        typeIco1Lb = new QLabel(gridLayoutWidget_3);
        typeIco1Lb->setObjectName(QString::fromUtf8("typeIco1Lb"));
        typeIco1Lb->setStyleSheet(QString::fromUtf8("image:url(:/day/day/\345\260\217\351\233\250.png);"));
        typeIco1Lb->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(typeIco1Lb, 4, 1, 2, 1);

        curveLb = new QLabel(gridLayoutWidget_3);
        curveLb->setObjectName(QString::fromUtf8("curveLb"));
        curveLb->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(curveLb, 7, 0, 3, 6);


        gridLayout_9->addLayout(gridLayout_2, 0, 0, 1, 1);

        gridLayoutWidget_4 = new QWidget(widget);
        gridLayoutWidget_4->setObjectName(QString::fromUtf8("gridLayoutWidget_4"));
        gridLayoutWidget_4->setGeometry(QRect(100, 50, 160, 37));
        gridLayout_12 = new QGridLayout(gridLayoutWidget_4);
        gridLayout_12->setSpacing(6);
        gridLayout_12->setContentsMargins(11, 11, 11, 11);
        gridLayout_12->setObjectName(QString::fromUtf8("gridLayout_12"));
        gridLayout_12->setContentsMargins(0, 0, 0, 0);
        label_39 = new QLabel(gridLayoutWidget_4);
        label_39->setObjectName(QString::fromUtf8("label_39"));
        label_39->setStyleSheet(QString::fromUtf8("background-color: argb(60,60,60,0);\n"
"image: url(:/weatherIco/location.ico);"));

        gridLayout_12->addWidget(label_39, 0, 0, 1, 1);

        cityLb = new QLabel(gridLayoutWidget_4);
        cityLb->setObjectName(QString::fromUtf8("cityLb"));
        cityLb->setStyleSheet(QString::fromUtf8("font: 25 16pt \"\345\276\256\350\275\257\351\233\205\351\273\221 Light\";"));
        cityLb->setAlignment(Qt::AlignCenter);

        gridLayout_12->addWidget(cityLb, 0, 1, 1, 1);

        leafLb = new QLabel(widget);
        leafLb->setObjectName(QString::fromUtf8("leafLb"));
        leafLb->setGeometry(QRect(18, 58, 20, 20));
        leafLb->setStyleSheet(QString::fromUtf8("image: url(:/weatherIco/leaf.ico);\n"
"background-color: argb(255.255,255,0);"));
        qualityLb = new QLabel(widget);
        qualityLb->setObjectName(QString::fromUtf8("qualityLb"));
        qualityLb->setGeometry(QRect(38, 58, 56, 20));
        qualityLb->setStyleSheet(QString::fromUtf8("background-color: argb(255,255,255,0);"));
        temLb = new QLabel(widget);
        temLb->setObjectName(QString::fromUtf8("temLb"));
        temLb->setGeometry(QRect(0, 90, 131, 71));
        temLb->setStyleSheet(QString::fromUtf8("color: rgb(255,255,255);\n"
"font: 50pt \"Arial\";"));
        temLb->setAlignment(Qt::AlignCenter);
        typeLb = new QLabel(widget);
        typeLb->setObjectName(QString::fromUtf8("typeLb"));
        typeLb->setGeometry(QRect(160, 130, 72, 15));
        typeLb->setStyleSheet(QString::fromUtf8("color: rgb(255,255,255);\n"
"background-color: argb(60,60,60,0);"));
        typeLb->setAlignment(Qt::AlignCenter);
        typeIcoLb = new QLabel(widget);
        typeIcoLb->setObjectName(QString::fromUtf8("typeIcoLb"));
        typeIcoLb->setGeometry(QRect(255, 63, 101, 101));
        typeIcoLb->setStyleSheet(QString::fromUtf8("border-image: url(:/day/day/\346\231\264.png);\n"
"background-color: argb(60,60,60,0);"));
        noticeLb = new QLabel(widget);
        noticeLb->setObjectName(QString::fromUtf8("noticeLb"));
        noticeLb->setGeometry(QRect(10, 160, 351, 21));
        noticeLb->setStyleSheet(QString::fromUtf8("color: rgb(255,255,255);\n"
"background-color: argb(60,60,60,0);"));
        gridLayoutWidget_5 = new QWidget(widget);
        gridLayoutWidget_5->setObjectName(QString::fromUtf8("gridLayoutWidget_5"));
        gridLayoutWidget_5->setGeometry(QRect(10, 340, 171, 111));
        gridLayout_13 = new QGridLayout(gridLayoutWidget_5);
        gridLayout_13->setSpacing(6);
        gridLayout_13->setContentsMargins(11, 11, 11, 11);
        gridLayout_13->setObjectName(QString::fromUtf8("gridLayout_13"));
        gridLayout_13->setContentsMargins(0, 0, 0, 0);
        label_7 = new QLabel(gridLayoutWidget_5);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setStyleSheet(QString::fromUtf8("background-color: argb(60,60,60,130);\n"
"border-radius: 3px;\n"
"color: rgb(255,255,255);"));
        label_7->setAlignment(Qt::AlignCenter);

        gridLayout_13->addWidget(label_7, 0, 0, 1, 1);

        gangmaoBrowser = new QTextBrowser(gridLayoutWidget_5);
        gangmaoBrowser->setObjectName(QString::fromUtf8("gangmaoBrowser"));

        gridLayout_13->addWidget(gangmaoBrowser, 0, 1, 1, 1);

        vLine1 = new QFrame(widget);
        vLine1->setObjectName(QString::fromUtf8("vLine1"));
        vLine1->setGeometry(QRect(180, 340, 1, 101));
        vLine1->setFrameShape(QFrame::VLine);
        vLine1->setFrameShadow(QFrame::Sunken);
        searchBtn = new QToolButton(widget);
        searchBtn->setObjectName(QString::fromUtf8("searchBtn"));
        searchBtn->setGeometry(QRect(700, 10, 47, 31));
        searchBtn->setStyleSheet(QString::fromUtf8("border-image: url(:/weatherIco/search.ico);"));
        refreshBtn = new QToolButton(widget);
        refreshBtn->setObjectName(QString::fromUtf8("refreshBtn"));
        refreshBtn->setGeometry(QRect(750, 10, 37, 31));
        refreshBtn->setStyleSheet(QString::fromUtf8("image: url(:/weatherIco/refresh.ico);\n"
"background-color: argb(255,255,255,0);"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/weatherIco/refresh.ico"), QSize(), QIcon::Normal, QIcon::Off);
        refreshBtn->setIcon(icon);
        refreshBtn->setIconSize(QSize(31, 31));
        sunriseLb = new QLabel(widget);
        sunriseLb->setObjectName(QString::fromUtf8("sunriseLb"));
        sunriseLb->setGeometry(QRect(190, 340, 161, 101));
        dateLable->raise();
        Hline_1->raise();
        Hline_2->raise();
        Hline_3->raise();
        gridLayoutWidget->raise();
        gridLayoutWidget_3->raise();
        gridLayoutWidget_4->raise();
        leafLb->raise();
        qualityLb->raise();
        temLb->raise();
        typeLb->raise();
        typeIcoLb->raise();
        noticeLb->raise();
        gridLayoutWidget_5->raise();
        vLine1->raise();
        refreshBtn->raise();
        sunriseLb->raise();
        cityLineEdit->raise();
        label->raise();
        searchBtn->raise();
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        mainToolBar->setGeometry(QRect(0, 0, 4, 14));
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        statusBar->setGeometry(QRect(0, 0, 3, 25));
        label_18 = new QLabel(MainWindow);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        label_18->setGeometry(QRect(740, 400, 62, 38));

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QWidget *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        dateLable->setText(QApplication::translate("MainWindow", "2022-10-8", nullptr));
        label->setText(QApplication::translate("MainWindow", "\345\244\251\346\260\224\351\242\204\346\212\245", nullptr));
        flTitleLb->setText(QApplication::translate("MainWindow", "\351\243\216\345\212\233", nullptr));
        shiduTitleLb_2->setText(QApplication::translate("MainWindow", "\346\271\277\345\272\246", nullptr));
        fxTitleLb->setText(QApplication::translate("MainWindow", "\351\243\216\345\220\221", nullptr));
        pm25TilleLb->setText(QApplication::translate("MainWindow", "PM2.5", nullptr));
        shiduLb->setText(QApplication::translate("MainWindow", "95%", nullptr));
        pm25Lb->setText(QApplication::translate("MainWindow", "0", nullptr));
        fxLb->setText(QApplication::translate("MainWindow", "\350\245\277\345\214\227\351\243\216", nullptr));
        flLb->setText(QApplication::translate("MainWindow", "<3\347\272\247", nullptr));
        quality3Lb->setText(QApplication::translate("MainWindow", "\344\270\255\345\272\246\346\261\241\346\237\223", nullptr));
        high3Lb->setText(QApplication::translate("MainWindow", "10\302\260", nullptr));
        type5Lb->setText(QApplication::translate("MainWindow", "\351\230\264", nullptr));
        high5Lb->setText(QApplication::translate("MainWindow", "10\302\260", nullptr));
        typeIco5Lb->setText(QString());
        quality1Lb->setText(QApplication::translate("MainWindow", "\350\211\257\345\245\275", nullptr));
        type0Lb->setText(QApplication::translate("MainWindow", "\351\230\264", nullptr));
        low0Lb->setText(QApplication::translate("MainWindow", "-1", nullptr));
        date1Lb->setText(QApplication::translate("MainWindow", "02/02", nullptr));
        low4Lb->setText(QApplication::translate("MainWindow", "-1", nullptr));
        type3Lb->setText(QApplication::translate("MainWindow", "\351\230\264", nullptr));
        date0Lb->setText(QApplication::translate("MainWindow", "01/01", nullptr));
        type4Lb->setText(QApplication::translate("MainWindow", "\351\230\264", nullptr));
        date3Lb->setText(QApplication::translate("MainWindow", "04/04", nullptr));
        quality0Lb->setText(QApplication::translate("MainWindow", "\344\274\230\350\264\250", nullptr));
        quality5Lb->setText(QApplication::translate("MainWindow", "\350\211\257", nullptr));
        typeIco3Lb->setText(QString());
        low2Lb->setText(QApplication::translate("MainWindow", "-1", nullptr));
        week4Lb->setText(QApplication::translate("MainWindow", "\345\221\250\344\272\224", nullptr));
        low5Lb->setText(QApplication::translate("MainWindow", "-1", nullptr));
        typeIco0Lb->setText(QString());
        date5Lb->setText(QApplication::translate("MainWindow", "06/06", nullptr));
        typeIco2Lb->setText(QString());
        week3Lb->setText(QApplication::translate("MainWindow", "\345\220\216\345\244\251", nullptr));
        low1Lb->setText(QApplication::translate("MainWindow", "-1", nullptr));
        typeIco4Lb->setText(QString());
        type1Lb->setText(QApplication::translate("MainWindow", "\351\230\264", nullptr));
        week0Lb->setText(QApplication::translate("MainWindow", "\346\230\250\345\244\251", nullptr));
        high2Lb->setText(QApplication::translate("MainWindow", "10\302\260", nullptr));
        quality2Lb->setText(QApplication::translate("MainWindow", "\350\275\273\345\272\246\346\261\241\346\237\223", nullptr));
        high1Lb->setText(QApplication::translate("MainWindow", "10\302\260", nullptr));
        week1Lb->setText(QApplication::translate("MainWindow", "\344\273\212\345\244\251", nullptr));
        type2Lb->setText(QApplication::translate("MainWindow", "\351\230\264", nullptr));
        quality4Lb->setText(QApplication::translate("MainWindow", "\344\270\245\351\207\215\346\261\241\346\237\223", nullptr));
        date4Lb->setText(QApplication::translate("MainWindow", "05/05", nullptr));
        high0Lb->setText(QApplication::translate("MainWindow", "10\302\260", nullptr));
        week2Lb->setText(QApplication::translate("MainWindow", "\346\230\216\345\244\251", nullptr));
        high4Lb->setText(QApplication::translate("MainWindow", "10\302\260", nullptr));
        date2Lb->setText(QApplication::translate("MainWindow", "03/03", nullptr));
        week5Lb->setText(QApplication::translate("MainWindow", "\345\221\250\345\205\255", nullptr));
        low3Lb->setText(QApplication::translate("MainWindow", "-1", nullptr));
        typeIco1Lb->setText(QString());
        curveLb->setText(QString());
        label_39->setText(QString());
        cityLb->setText(QApplication::translate("MainWindow", "\351\225\277\346\262\231", nullptr));
        leafLb->setText(QString());
        qualityLb->setText(QApplication::translate("MainWindow", "\344\274\230", nullptr));
        temLb->setText(QApplication::translate("MainWindow", "9\302\260", nullptr));
        typeLb->setText(QApplication::translate("MainWindow", "\346\231\264", nullptr));
        typeIcoLb->setText(QString());
        noticeLb->setText(QApplication::translate("MainWindow", "\345\244\251\346\260\224\344\277\241\346\201\257\346\217\220\347\244\272", nullptr));
        label_7->setText(QApplication::translate("MainWindow", "<html><head/><body><p>\346\204\237<br/>\345\206\222<br/>\346\214\207<br/>\346\225\260</p></body></html>", nullptr));
        searchBtn->setText(QApplication::translate("MainWindow", "...", nullptr));
        refreshBtn->setText(QString());
        sunriseLb->setText(QString());
        label_18->setText(QApplication::translate("MainWindow", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

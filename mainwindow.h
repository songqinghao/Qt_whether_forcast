﻿#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#pragma execution_character_set("utf-8")
#include <QMainWindow>
#include <QMenu>
#include <QAction>
#include <QMouseEvent>
#include <QLabel>
#include <QNetworkAccessManager>
#include <QUrl>
#include <QMessageBox>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QByteArray>
#include <QDebug>
#include <QTimer>
#include "weathertool.h"
#include "weatherdata.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    virtual bool eventFilter(QObject *watched, QEvent *event);
protected:
    //bool eventFilter(QObject*watched,QEvent*event);
    void mouseMoveEvent(QMouseEvent* event);
    void mousePressEvent(QMouseEvent* event);
    void contextMenuEvent(QContextMenuEvent* event);
    void getWeatherInfo(QNetworkAccessManager *manager);
    void parseJson(QByteArray& bytes);
    void setLabelContent();//将数据内容更新到ui上
    void paintSunRiseSet();//绘制日出日落
    void paintCurve();//绘制温度曲线
private slots:
    void slot_exitApp();
    void replayFinished(QNetworkReply* reply);
    void on_searchBtn_clicked();

    void on_refreshBtn_clicked();

private:
    Ui::MainWindow *ui;
    QMenu* exitMenu;//右键推出的菜单
    QAction* exitAction;
    QPoint mPos;
    //初始化UI
    QList<QLabel*>forecast_week_list;//星期
    QList<QLabel*>forecast_date_list;//日期
    QList<QLabel*>forecast_aqi_list; //天气指数
    QList<QLabel*>forecast_type_list;//天气
    QList<QLabel*>forecast_typeIco_list;//天气图标
    QList<QLabel*>forecast_high_list;//高温
    QList<QLabel*>forecast_low_list; //低温

    //网络请求的需要
    QString url;    //接口链接
    QString city;   //访问的城市
    QString cityTmp;//临时存放城市变量，防止输入错误
    WeatherTool tool;//天气工具对象
    QNetworkAccessManager* manager;

    //本地数据
    Today today;
    Forecast forecast[6];


    static const QPoint sun[2];//日出日落底线
    static const QRect sunRizeSet[2];//日出日落时间
    static const QRect rect[2];//圆弧

    QTimer* sunTimer;
};

#endif // MAINWINDOW_H

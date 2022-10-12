#ifndef WEATHERDATA_H
#define WEATHERDATA_H
#pragma execution_character_set("utf-8")
#include <QWidget>
#include <QList>
#include <QLabel>
#include <QPoint>
#include <QRect>
#include <QTimer>
#include <QMouseEvent>
#include <QMenu>
#include <QAction>
#include <QByteArray>

#include "WeatherTool.h"

//当日数据
class Today
{
public:
    Today();
    Today& operator=(const QJsonObject& jsObj);
    QString date;//日期
    QString wendu;//温度
    QString city;//城市名称
    QString shidu;//湿度
    QString pm25;//pm2.5
    QString quality;//空气质量
    QString ganmao;//感冒指数
    QString fx;//风向
    QString fl;//风力
    QString type;
    QString sunrise;//日落时间
    QString sunset;//日出时间
    QString notice;//提示
};

//预报数据
class Forecast
{
public:
    Forecast();
    Forecast& operator=(const QJsonObject& obj);
    QString date;//时间
    QString high;//最高温
    QString low;//最低温
    QString aqi;//空气质量
    QString type;
};


#endif // WEATHERDATA_H

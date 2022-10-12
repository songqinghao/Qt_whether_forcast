#include "weatherdata.h"
#include <QDate>
#include <QDebug>
//初始数据的初始化
#pragma execution_character_set("utf-8")
Today::Today()
{
    date = "0000-00-00";
    city = "null";
    fl = u8"无数据";
    fx = u8"无数据";
    ganmao = u8"无数据";
    notice = u8"无数据";
    pm25 = u8"无数据";
    quality = u8"无数据";
    shidu = u8"无数据";
    sunrise = "00:00";
    sunset = "00:00";
    wendu = "null";
    type = u8"无数据";
}

//赋值Json对象
//Today& operator=(const QJsonObject& jsObj);
Today& Today::operator=(const QJsonObject& jsObj)
{
    QString dataStr= jsObj.value("date").toString();
    date = QDate::fromString(dataStr,"yyyyMMdd").toString("yyyy-MM-dd");
    city = jsObj.value("cityInfo").toObject().value("city").toString();

    // 解析相关数据
    QJsonObject dataObj = jsObj.value("data").toObject();
    shidu = dataObj.value("shidu").toString();
    //qDebug()<<"operator= objtt"<<dataObj;
    pm25 = QString::number(dataObj.value("pm25").toDouble());
    //pm25 = dataObj.value("pm25").toString();
    //qDebug()<<"operator= pm25"<<pm25;
    quality = dataObj.value("quality").toString();
    wendu = dataObj.value("wendu").toString();
    ganmao = dataObj.value("ganmao").toString();
    QJsonArray forecastArr = dataObj.value("forecast").toArray();
    QJsonObject todayObj = forecastArr.at(0).toObject();
    fx = todayObj.value("fx").toString();
    fl = todayObj.value("fl").toString();
    type = todayObj.value("type").toString();
    notice = todayObj.value("notice").toString();
    sunrise = todayObj.value("sunrise").toString();
    sunset = todayObj.value("sunset").toString();
    return *this;
}

Forecast::Forecast()
{
    aqi = "0";
    date = u8"00日星期0";
    high = u8"高温 0.0°C";
    low = u8"低温 0.0°C";
    type = "underfined";
}

Forecast &Forecast::operator=(const QJsonObject& obj)
{
    date = obj.value("date").toString();
    aqi = QString::number(obj.value("aqi").toDouble());
    high = obj.value("high").toString();
    low = obj.value("low").toString();
    type = obj.value("type").toString();
    return *this;
}

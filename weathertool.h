#ifndef WEATHERTOOL_H
#define WEATHERTOOL_H
#pragma execution_character_set("utf-8")
#include <QJsonDocument>
#include <QJsonParseError>
#include <QJsonObject>
#include <QJsonValue>
#include <QJsonArray>
#include <map>
#include <QFile>
#include <QApplication>

class WeatherTool
{
public:
    WeatherTool()
    {
        //fileName为当前pro文件目录
        QString fileName = QCoreApplication::applicationDirPath();
        //加上邮政编码集合文件
        fileName+="/citycode-2019-08-23.json";

        QFile file(fileName);
        //文件只读+文本类型
        file.open(QIODevice::ReadOnly|QIODevice::Text);
        //将文件全部读下来，转成QByteArray
        QByteArray json = file.readAll();
        file.close();
        QJsonParseError err;
        //解析json文件
        QJsonDocument jsonDoc = QJsonDocument::fromJson(json,&err);
        QJsonArray cities = jsonDoc.array();
        for(int i = 0;i < cities.size(); i++)
        {
            //拿到城市的邮政编码
            QString code = cities.at(i).toObject().value("city_code").toString();
            //拿到城市的名称
            QString city = cities.at(i).toObject().value("city_name").toString();
            if(code.size() > 0)
            {
               m_mapCity2Code.insert(std::pair<QString,QString>(city,code));
            }
        }
    }
    QString operator[](const QString& city)
    {
        std::map<QString,QString>::iterator it = m_mapCity2Code.find(city);
        //说明没找到
        if(it == m_mapCity2Code.end())
        {
            //加个“市”看看能不能找到
            it = m_mapCity2Code.find(city+u8"市");
        }
        if(it != m_mapCity2Code.end())
        {
            return  it->second;
        }
        return "000000000";

    }
private:
    std::map<QString,QString>m_mapCity2Code;

};
#endif // WEATHERTOOL_H

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>
#define SPAN_INDEX 3 // 温度曲线间隔指数
#define ORIGIN_SIZE 3 // 温度曲线原点大小
#define TEMPERATURE_STARTING_COORDINATE 45 // 高温平均值起始坐标
// 日出日落底线
const QPoint MainWindow::sun[2] = {
    QPoint(20, 75),
    QPoint(130, 75)
};

// 日出日落时间
const QRect MainWindow::sunRizeSet[2] = {
    //相对于他的父类位置QPainter painter(ui->sunriseLb);
    QRect(0, 80, 50, 20),
    QRect(100, 80, 50, 20)
};

// 日出日落圆弧
const QRect MainWindow::rect[2] = {
    QRect(25, 25, 100, 100), // 虚线圆弧
    QRect(50, 80, 50, 20) // “日出日落”文本
};
MainWindow::MainWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //设置窗口属性
    //无边框
    setWindowFlag(Qt::FramelessWindowHint);
    //不可拉伸，固定大小
    setFixedSize(width(),height());
    //菜单父类为Main
    exitMenu = new QMenu(this);
    exitAction=new QAction;
    exitAction->setText("退出");
    //“:”表示资源路径的根目录，icon\icons.qrc不是路径，是资源配置文件
    exitAction->setIcon(QIcon(":/weatherIco/close.ico"));
    //菜单添加行为
    exitMenu->addAction(exitAction);
    connect(exitAction,SIGNAL(triggered(bool)),this,SLOT(slot_exitApp()));

    //UI初始化
    forecast_week_list << ui->week0Lb << ui->week1Lb << ui->week2Lb << ui->week3Lb << ui->week4Lb << ui->week5Lb;
    forecast_date_list << ui->date0Lb << ui->date1Lb << ui->date2Lb << ui->date3Lb << ui->date4Lb << ui->date5Lb;
    forecast_aqi_list << ui->quality0Lb << ui->quality1Lb << ui->quality2Lb << ui->quality3Lb << ui->quality4Lb << ui->quality5Lb;
    forecast_type_list << ui->type0Lb << ui->type1Lb << ui->type2Lb << ui->type3Lb << ui->type4Lb << ui->type5Lb;
    forecast_typeIco_list << ui->typeIco0Lb << ui->typeIco1Lb << ui->typeIco2Lb << ui->typeIco3Lb << ui->typeIco4Lb << ui->typeIco5Lb;
    forecast_high_list << ui->high0Lb << ui->high1Lb << ui->high2Lb << ui->high3Lb << ui->high4Lb << ui->high5Lb;
    forecast_low_list << ui->low0Lb << ui->low1Lb << ui->low2Lb << ui->low3Lb << ui->low4Lb << ui->low5Lb;

    // dateLb和WeekLb样式表设置
    for (int i = 0; i < 6; i++)
    {
        forecast_date_list[i]->setStyleSheet("background-color: rgba(0, 255, 255, 100);");
        forecast_week_list[i]->setStyleSheet("background-color: rgba(0, 255, 255, 100);");
    }
    /*
     *QLineEdit{}:意思是只对QLineEdit有效
     *border:1px solid gray:边界设置为1个像素，实线
     *border-radius:4px:圆角边框半径 4像素
     *QLineEdit::hover:选择器的样式表(hover, 当鼠标移动到QLineEdit时显示的样式)QLineEdit:hover{border-color:rgb(101, 255, 106); }
     */
    ui->cityLineEdit->setStyleSheet("QLineEdit{border: 1px solid gray; border-radius: 4px; background:argb(47, 47, 47, 130); color:rgb(255, 255, 255);} QLineEdit:hover{border-color:rgb(101, 255, 106); }");

    //网络请求初始化
    url = "http://t.weather.itboy.net/api/weather/city/";
    city = u8"长沙";
    cityTmp = city;
    manager = new QNetworkAccessManager(this);
    //信号与槽
    connect(manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(replayFinished(QNetworkReply*)));
    getWeatherInfo(manager);
    ui->sunriseLb->installEventFilter(this);//安装事件

    //信号过滤器
    ui->curveLb->installEventFilter(this);
    ui->cityLineEdit->installEventFilter(this);

    on_refreshBtn_clicked();
    //paintCurve();
    sunTimer = new QTimer(ui->sunriseLb);
    connect(sunTimer,SIGNAL(timeout()),ui->sunriseLb,SLOT(update()));
    //connect(sunTimer,SIGNAL(timeout()),ui->curveLb,SLOT(update()));
    sunTimer->start(1000);
}
void MainWindow::replayFinished(QNetworkReply *reply)
{
    /* 获取响应的信息，状态码为200表示正常 --comment by wsg 2017/12/11 */
    QVariant status_code = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute);

    if(reply->error() != QNetworkReply::NoError || status_code != 200)
    {
        QMessageBox::warning(this, u8"错误", u8"天气：请求数据错误，检查网络连接！", QMessageBox::Ok);
        return;
    }

    //将刚刚读取的数据变成字节数组
    QByteArray bytes = reply->readAll();
    qDebug()<<bytes;
    // QString result = QString::fromLocal8Bit(bytes);
    parseJson(bytes);
}
void MainWindow::getWeatherInfo(QNetworkAccessManager *manager)
{
    //取到city的code
    QString citycode = tool[city];
    if(citycode=="000000000"){
        QMessageBox::warning(this, u8"错误", u8"天气：指定城市不存在！", QMessageBox::Ok);
        return;
    }
    QUrl jsonUrl(url + citycode);
    //请求，等会儿就会有reply
    manager->get( QNetworkRequest(jsonUrl) );
}

void MainWindow::parseJson(QByteArray& bytes)
{
    QJsonParseError err;
    //将传过来的Json的字节数组转换成Json文档类
    //也起到一种检测json格式的作用
    QJsonDocument jsonDoc = QJsonDocument::fromJson(bytes, &err); // 检测json格式
    //如果解析错误
    if (err.error != QJsonParseError::NoError) // Json格式错误
    {
        return;
    }

    QJsonObject jsObj = jsonDoc.object();
    qDebug()<<jsObj;
    qDebug()<<"-------------------------";
    QString message = jsObj.value("message").toString();
    qDebug()<<message;
    //看是不是确实有这个城市，是否包含success
    if (message.contains("success")==false)
    {
        QMessageBox::information(this, tr("The information of Json_desc"),
                                 u8"天气：城市错误！", QMessageBox::Ok );
        city = cityTmp;
        return;
    }

    today = jsObj;
    //把date的整个数组都拿到
    QJsonObject dataObj = jsObj.value("data").toObject();

    // 解析data中的yesterday
    QJsonObject yestObj = dataObj.value("yesterday").toObject();
    forecast[0] = dataObj.value("yesterday").toObject();

    // 解析data中的forecast
    QJsonArray forecastArr = dataObj.value("forecast").toArray();
    int j = 0;
    //预报数据，今天开始
    for (int i = 1; i < 6; i++)
    {
        forecast[i]=forecastArr.at(j).toObject();
        //qDebug()<<forecast[i].high;
        j++;
    }
    setLabelContent();
}
//
void MainWindow::setLabelContent()
{
    // 今日数据
   ui->dateLable->setText(today.date);
   ui->temLb->setText(today.wendu);
   ui->cityLb->setText(today.city);
   ui->typeLb->setText(today.type);
   ui->noticeLb->setText(today.notice);
   ui->shiduLb->setText(today.shidu);
   ui->pm25Lb->setText(today.pm25);
   qDebug()<<"pm25:"<<today.pm25;
   ui->fxLb->setText(today.fx);
   ui->flLb->setText(today.fl);
   ui->gangmaoBrowser->setText(today.ganmao);

   // 判断白天还是夜晚图标
   QString sunsetTime = today.date + " " + today.sunset;
   //qDebug()<<"---------------------";
   //qDebug()<<sunsetTime;
   if (QDateTime::currentDateTime() <= QDateTime::fromString(sunsetTime, "yyyy-MM-dd hh:mm"))
   {
       ui->typeIcoLb->setStyleSheet( tr("border-image: url(:/day/day/%1.png); background-color: argb(60, 60, 60, 0);").arg(today.type) );
   }
   else
   {
       ui->typeIcoLb->setStyleSheet( tr("border-image: url(:/night/night/%1.png); background-color: argb(60, 60, 60, 0);").arg(today.type) );
   }

   ui->qualityLb->setText(today.quality == "" ? "无" : today.quality);
   if (today.quality == "优")
   {
       ui->qualityLb->setStyleSheet("color: rgb(0, 255, 0); background-color: argb(255, 255, 255, 0);");
   }
   else if (today.quality == "良")
   {
       ui->qualityLb->setStyleSheet("color: rgb(255, 255, 0); background-color: argb(255, 255, 255, 0);");
   }
   else if (today.quality == "轻度污染")
   {
       ui->qualityLb->setStyleSheet("color: rgb(255, 170, 0); background-color: argb(255, 255, 255, 0);");
   }
   else if (today.quality == "重度污染")
   {
       ui->qualityLb->setStyleSheet("color: rgb(255, 0, 0); background-color: argb(255, 255, 255, 0);");
   }
   else if (today.quality == "严重污染")
   {
       ui->qualityLb->setStyleSheet("color: rgb(170, 0, 0); background-color: argb(255, 255, 255, 0);");
   }
   else
   {
       ui->qualityLb->setStyleSheet("color: rgb(255, 255, 255); background-color: argb(255, 255, 255, 0);");
   }
   // 六天数据
   for (int i = 0; i < 6; i++)
   {
       //从右向左截取3个字符
       forecast_week_list[i]->setText(forecast[i].date.right(3));

       forecast_date_list[i]->setText(forecast[i].date.left(3));
       forecast_type_list[i]->setText(forecast[i].type);
       //qDebug()<<"i:"<<i;
       //qDebug()<<forecast[i].high;
       forecast_high_list[i]->setText(forecast[i].high.split(" ").at(1));

       forecast_low_list[i]->setText(forecast[i].low.split(" ").at(1));

       forecast_typeIco_list[i]->setStyleSheet( tr("image: url(:/day/day/%1.png);").arg(forecast[i].type) );
       if (forecast[i].aqi.toInt() >= 0 && forecast[i].aqi.toInt() <= 50)
       {
           forecast_aqi_list[i]->setText(u8"优质");
           forecast_aqi_list[i]->setStyleSheet("color: rgb(0, 255, 0);");
       }
       else if (forecast[i].aqi.toInt() > 50 && forecast[i].aqi.toInt() <= 100)
       {
           forecast_aqi_list[i]->setText(u8"良好");
           forecast_aqi_list[i]->setStyleSheet("color: rgb(255, 255, 0);");
       }
       else if (forecast[i].aqi.toInt() > 100 && forecast[i].aqi.toInt() <= 150)
       {
           forecast_aqi_list[i]->setText(u8"轻度污染");
           forecast_aqi_list[i]->setStyleSheet("color: rgb(255, 170, 0);");
       }
       else if (forecast[i].aqi.toInt() > 150 && forecast[i].aqi.toInt() <= 200)
       {
           forecast_aqi_list[i]->setText(u8"重度污染");
           forecast_aqi_list[i]->setStyleSheet("color: rgb(255, 0, 0);");
       }
       else
       {
           forecast_aqi_list[i]->setText(u8"严重污染");
           forecast_aqi_list[i]->setStyleSheet("color: rgb(170, 0, 0);");
       }

   }//for
   //设置昨天和今天
   ui->week0Lb->setText( u8"昨天" );
   ui->week1Lb->setText( u8"今天" );
   //温度曲线绘制
   //ui->curveLb->update();
}

//日出日落
void MainWindow::paintSunRiseSet()
{
    QPainter painter(ui->sunriseLb);
    //反锯齿设置（去毛边）
    painter.setRenderHint(QPainter::Antialiasing,true);

    painter.save();
    QPen pen = painter.pen();
    pen.setWidthF(0.5);
    pen.setColor(Qt::yellow);
    painter.setPen(pen);
    painter.drawLine(sun[0],sun[1]);//绘制直线，从sun[0]绘制到sun[1]
    painter.restore();//重置(和save对应)

    painter.save();
    painter.setFont( QFont("Microsoft Yahei", 8, QFont::Normal) ); // 字体、大小、正常粗细
    painter.setPen(Qt::white);

    if (today.sunrise != "" && today.sunset != "")
    {
        //绘制矩形框
        painter.drawText(sunRizeSet[0], Qt::AlignHCenter, today.sunrise);
        painter.drawText(sunRizeSet[1], Qt::AlignHCenter, today.sunset);
    }

    painter.drawText(rect[1], Qt::AlignHCenter, u8"日出日落");
    painter.restore();

    // 绘制圆弧
   painter.save();
   pen.setWidthF(0.5);//设置宽度
   pen.setStyle(Qt::DotLine);//虚线
   pen.setColor(Qt::green);//设置线的颜色
   painter.setPen(pen);
   //指定矩形，16表示1°（绘制的角度是从左往右搞的）
   painter.drawArc(rect[0], 0 * 16, 180 * 16);
   painter.restore();

   // 绘制日出日落占比
   if (today.sunrise != "" && today.sunset != "")
   {
       //关闭笔
       painter.setPen(Qt::NoPen);
       //使用画刷
       painter.setBrush(QColor(255, 85, 0, 100));
       //起始角度，结束角度
       int startAngle, spanAngle;
       QString sunsetTime = today.date + " " + today.sunset;
       //如果现在的时间大于日落的时间
       if (QDateTime::currentDateTime() > QDateTime::fromString(sunsetTime, "yyyy-MM-dd hh:mm"))
       {
           startAngle = 0 * 16;
           spanAngle = 180 * 16;
       }
       else
       {
           // 计算起始角度和跨越角度
           static QStringList sunSetTime = today.sunset.split(":");
           static QStringList sunRiseTime = today.sunrise.split(":");

           static QString sunsetHour = sunSetTime.at(0);
           static QString sunsetMint = sunSetTime.at(1);
           static QString sunriseHour = sunRiseTime.at(0);
           static QString sunriseMint = sunRiseTime.at(1);
           //日出、日落以及现在的时间均按分钟记
           static int sunrise = sunriseHour.toInt() * 60 + sunriseMint.toInt();
           static int sunset = sunsetHour.toInt() * 60 + sunsetMint.toInt();
           int now = QTime::currentTime().hour() * 60 + QTime::currentTime().minute();

           startAngle = ( (double)(sunset - now) / (sunset - sunrise) ) * 180 * 16;
           spanAngle = ( (double)(now - sunrise) / (sunset - sunrise) ) * 180 * 16;
       }

       if (startAngle >= 0 && spanAngle >= 0)
       {
           painter.drawPie(rect[0], startAngle, spanAngle); // 扇形绘制
       }
   }

}

void MainWindow::paintCurve()
{
    QPainter painter(ui->curveLb);
    //反锯齿
    painter.setRenderHint(QPainter::Antialiasing,true);

    //将温度转换为int类型，并计算平均值，平均值作为curveLb曲线的参考值，参考Y坐标为45
    int tempTotal = 0;
    int high[6] = {};
    int low[6] = {};
    //计算平均值
    QString h, l;
    for (int i = 0; i < 6; i++)
    {
        h = forecast[i].high.split(" ").at(1);
        h = h.left(h.length() - 1);//将℃去掉
        high[i] = (int)(h.toDouble());
        tempTotal += high[i];

        l = forecast[i].low.split(" ").at(1);
        l = l.left(h.length() - 1);
        low[i] = (int)(l.toDouble());
    }
    int tempAverage = (int)(tempTotal / 6); // 最高温平均值

    // 算出温度对应坐标
    int pointX[6] = {35, 103, 172, 241, 310, 379}; // 点的X坐标
    int pointHY[6] = {0};
    int pointLY[6] = {0};
    for (int i = 0; i < 6; i++)
    {
        pointHY[i] = TEMPERATURE_STARTING_COORDINATE - ((high[i] - tempAverage) * SPAN_INDEX);
        pointLY[i] = TEMPERATURE_STARTING_COORDINATE + ((tempAverage - low[i]) * SPAN_INDEX);
    }

    QPen pen = painter.pen();
    pen.setWidth(1);

    // 高温曲线绘制
    painter.save();
    //昨天到今天
    pen.setColor(QColor(255, 170, 0));
    pen.setStyle(Qt::DotLine);
    painter.setPen(pen);
    painter.setBrush(QColor(255, 170, 0));
    //绘制点（小圈圈）
    painter.drawEllipse(QPoint(pointX[0], pointHY[0]), ORIGIN_SIZE, ORIGIN_SIZE);
    painter.drawEllipse(QPoint(pointX[1], pointHY[1]), ORIGIN_SIZE, ORIGIN_SIZE);
    painter.drawLine(pointX[0], pointHY[0], pointX[1], pointHY[1]);

    //今天到未来4天的
    pen.setStyle(Qt::SolidLine);
    pen.setWidth(1);
    painter.setPen(pen);

    for (int i = 1; i < 5; i++)
    {
        painter.drawEllipse(QPoint(pointX[i+1], pointHY[i+1]), ORIGIN_SIZE, ORIGIN_SIZE);
        painter.drawLine(pointX[i], pointHY[i], pointX[i+1], pointHY[i+1]);
    }
    painter.restore();

    // 低温曲线绘制
    pen.setColor(QColor(0, 255, 255));
    pen.setStyle(Qt::DotLine);
    painter.setPen(pen);
    painter.setBrush(QColor(0, 255, 255));
    painter.drawEllipse(QPoint(pointX[0], pointLY[0]), ORIGIN_SIZE, ORIGIN_SIZE);
    painter.drawEllipse(QPoint(pointX[1], pointLY[1]), ORIGIN_SIZE, ORIGIN_SIZE);
    painter.drawLine(pointX[0], pointLY[0], pointX[1], pointLY[1]);
    qDebug()<<"低温0：X:"<<pointX[0]<<" Y:"<<pointHY[0];
    qDebug()<<"低温01：X:"<<pointX[1]<<" Y:"<<pointHY[1];
    pen.setColor(QColor(0, 255, 255));
    pen.setStyle(Qt::SolidLine);
    painter.setPen(pen);
    for (int i = 1; i < 5; i++)
    {
        painter.drawEllipse(QPoint(pointX[i+1], pointLY[i+1]), ORIGIN_SIZE, ORIGIN_SIZE);
        painter.drawLine(pointX[i], pointLY[i], pointX[i+1], pointLY[i+1]);
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow::eventFilter(QObject *watched, QEvent *event)
{
    //如果事件是为绘画事件
    if(watched == ui->sunriseLb && event->type()==QEvent::Paint)
    {
        paintSunRiseSet();
    }
    else if(watched == ui->curveLb&&event->type()==QEvent::Paint){
        paintCurve();
    }
    return QWidget::eventFilter(watched,event);
}
void MainWindow::contextMenuEvent(QContextMenuEvent* event)
{
    exitMenu->exec(QCursor::pos());
    event->accept();
}
void MainWindow::slot_exitApp()
{
    qApp->exit(0);

}
void MainWindow::mouseMoveEvent(QMouseEvent* event)
{
    move(event->globalPos()-mPos);
}

void MainWindow::mousePressEvent(QMouseEvent* event)
{
    mPos=event->globalPos()-this->pos();
}

void MainWindow::on_searchBtn_clicked()
{
    cityTmp= city;
    city = ui->cityLineEdit->text();
    getWeatherInfo(manager);
    ui->curveLb->update();
}

void MainWindow::on_refreshBtn_clicked()
{
    getWeatherInfo(manager);
    ui->curveLb->update();
}

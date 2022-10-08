#include "mainwindow.h"
#include "ui_mainwindow.h"

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
    exitAction->setText("exitApp");
    //“:”表示资源路径的根目录，icon\icons.qrc不是路径，是资源配置文件
    exitAction->setIcon(QIcon(":/weatherIco/close.ico"));
    //菜单添加行为
    exitMenu->addAction(exitAction);
    connect(exitAction,SIGNAL(triggered(bool)),this,SLOT(slot_exitApp()));

}

MainWindow::~MainWindow()
{
    delete ui;
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

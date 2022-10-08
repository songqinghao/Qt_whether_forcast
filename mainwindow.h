#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMenu>
#include <QAction>
#include <QMouseEvent>
namespace Ui {
class MainWindow;
}

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
protected:
    void mouseMoveEvent(QMouseEvent* event);
    void mousePressEvent(QMouseEvent* event);
    void contextMenuEvent(QContextMenuEvent* event);
private slots:
    void slot_exitApp();
private:
    Ui::MainWindow *ui;
    QMenu* exitMenu;//右键推出的菜单
    QAction* exitAction;
    QPoint mPos;
};

#endif // MAINWINDOW_H

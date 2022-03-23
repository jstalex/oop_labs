#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<car.h>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void searchcar();
    void addcar(int f);
private:
    Ui::MainWindow *ui;
    std::vector<car> cars;
};
#endif // MAINWINDOW_H

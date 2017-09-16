#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSlider>
#include <QSpinBox>

#include "controller.h"


namespace Ui {
class MainWindow;
}

struct HJHandler
{
    int ID;
    QSlider* slider;
    QSpinBox* spin;
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;

    void SliderSpinInit();
    HJHandler Handler[22];
    Controller controller;
};

#endif // MAINWINDOW_H

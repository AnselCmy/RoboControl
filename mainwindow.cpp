#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    controller.ControlInit();
    SliderSpinInit();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    for(int id=JID_HEAD_1; id<=JID_RLEG_6; id++)
    {
        controller.QueueAction(JointID(id), Handler[id].slider->value());
    }
    controller.ActQueue();
}

void MainWindow::SliderSpinInit()
{
    Handler[JID_HEAD_1].slider = ui->HEAD_1_Slider;
    Handler[JID_HEAD_2].slider = ui->HEAD_2_Slider;
    Handler[JID_LARM_1].slider = ui->LARM_1_Slider;
    Handler[JID_RARM_1].slider = ui->RARM_1_Slider;
    Handler[JID_LARM_2].slider = ui->LARM_2_Slider;
    Handler[JID_RARM_2].slider = ui->RARM_2_Slider;
    Handler[JID_LARM_3].slider = ui->LARM_3_Slider;
    Handler[JID_RARM_3].slider = ui->RARM_3_Slider;
    Handler[JID_LARM_4].slider = ui->LARM_4_Slider;
    Handler[JID_RARM_4].slider = ui->RARM_4_Slider;
    Handler[JID_LLEG_1].slider = ui->LLEG_1_Slider;
    Handler[JID_RLEG_1].slider = ui->RLEG_1_Slider;
    Handler[JID_LLEG_2].slider = ui->LLEG_2_Slider;
    Handler[JID_RLEG_2].slider = ui->RLEG_2_Slider;
    Handler[JID_LLEG_3].slider = ui->LLEG_3_Slider;
    Handler[JID_RLEG_3].slider = ui->RLEG_3_Slider;
    Handler[JID_LLEG_4].slider = ui->LLEG_4_Slider;
    Handler[JID_RLEG_4].slider = ui->RLEG_4_Slider;
    Handler[JID_LLEG_5].slider = ui->LLEG_5_Slider;
    Handler[JID_RLEG_5].slider = ui->RLEG_5_Slider;
    Handler[JID_LLEG_6].slider = ui->LLEG_6_Slider;
    Handler[JID_RLEG_6].slider = ui->RLEG_6_Slider;

    Handler[JID_HEAD_1].spin = ui->HEAD_1_Spin;
    Handler[JID_HEAD_2].spin = ui->HEAD_2_Spin;
    Handler[JID_LARM_1].spin = ui->LARM_1_Spin;
    Handler[JID_RARM_1].spin = ui->RARM_1_Spin;
    Handler[JID_LARM_2].spin = ui->LARM_2_Spin;
    Handler[JID_RARM_2].spin = ui->RARM_2_Spin;
    Handler[JID_LARM_3].spin = ui->LARM_3_Spin;
    Handler[JID_RARM_3].spin = ui->RARM_3_Spin;
    Handler[JID_LARM_4].spin = ui->LARM_4_Spin;
    Handler[JID_RARM_4].spin = ui->RARM_4_Spin;
    Handler[JID_LLEG_1].spin = ui->LLEG_1_Spin;
    Handler[JID_RLEG_1].spin = ui->RLEG_1_Spin;
    Handler[JID_LLEG_2].spin = ui->LLEG_2_Spin;
    Handler[JID_RLEG_2].spin = ui->RLEG_2_Spin;
    Handler[JID_LLEG_3].spin = ui->LLEG_3_Spin;
    Handler[JID_RLEG_3].spin = ui->RLEG_3_Spin;
    Handler[JID_LLEG_4].spin = ui->LLEG_4_Spin;
    Handler[JID_RLEG_4].spin = ui->RLEG_4_Spin;
    Handler[JID_LLEG_5].spin = ui->LLEG_5_Spin;
    Handler[JID_RLEG_5].spin = ui->RLEG_5_Spin;
    Handler[JID_LLEG_6].spin = ui->LLEG_6_Spin;
    Handler[JID_RLEG_6].spin = ui->RLEG_6_Spin;

    ui->RARM_1_Slider->setRange(-120, 120);
    ui->RARM_2_Slider->setRange(-95, 1);
    ui->RARM_3_Slider->setRange(-120, 120);
    ui->RARM_4_Slider->setRange(-1, 90);
    ui->RLEG_1_Slider->setRange(-90, 1);
    ui->RLEG_2_Slider->setRange(-45, 25);
    ui->RLEG_3_Slider->setRange(-25, 100);
    ui->RLEG_4_Slider->setRange(-130, 1);
    ui->RLEG_5_Slider->setRange(-45, 75);
    ui->RLEG_6_Slider->setRange(-25, 45);
    ui->LARM_1_Slider->setRange(-120, 120);
    ui->LARM_2_Slider->setRange(-1, 95);
    ui->LARM_3_Slider->setRange(-120, 120);
    ui->LARM_4_Slider->setRange(-90, 1);
    ui->LLEG_1_Slider->setRange(-90, 1);
    ui->LLEG_2_Slider->setRange(-25, 45);
    ui->LLEG_3_Slider->setRange(-25, 100);
    ui->LLEG_4_Slider->setRange(-130, 1);
    ui->LLEG_5_Slider->setRange(-45, 75);
    ui->LLEG_6_Slider->setRange(-45, 25);

    ui->RARM_1_Spin->setRange(-120, 120);
    ui->RARM_2_Spin->setRange(-95, 1);
    ui->RARM_3_Spin->setRange(-120, 120);
    ui->RARM_4_Spin->setRange(-1, 90);
    ui->RLEG_1_Spin->setRange(-90, 1);
    ui->RLEG_2_Spin->setRange(-45, 25);
    ui->RLEG_3_Spin->setRange(-25, 100);
    ui->RLEG_4_Spin->setRange(-130, 1);
    ui->RLEG_5_Spin->setRange(-45, 75);
    ui->RLEG_6_Spin->setRange(-25, 45);
    ui->LARM_1_Spin->setRange(-120, 120);
    ui->LARM_2_Spin->setRange(-1, 95);
    ui->LARM_3_Spin->setRange(-120, 120);
    ui->LARM_4_Spin->setRange(-90, 1);
    ui->LLEG_1_Spin->setRange(-90, 1);
    ui->LLEG_2_Spin->setRange(-25, 45);
    ui->LLEG_3_Spin->setRange(-25, 100);
    ui->LLEG_4_Spin->setRange(-130, 1);
    ui->LLEG_5_Spin->setRange(-45, 75);
    ui->LLEG_6_Spin->setRange(-45, 25);

    for(int id=JID_HEAD_1; id<=JID_RLEG_6; id++)
    {
        connect(Handler[id].spin, SIGNAL(valueChanged(int)),
                Handler[id].slider, SLOT(setValue(int)));
        connect(Handler[id].slider, SIGNAL(valueChanged(int)),
                Handler[id].spin, SLOT(setValue(int)));
    }
}

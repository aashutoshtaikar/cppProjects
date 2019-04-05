#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    /*connect(sender,SIGNAL(),
     *         receiver,SLOT()); connects 2 objects of the form */
    ui->progressBar->reset();
    ui->progressBar_2->reset();

    connect(ui->horizontalSlider,SIGNAL(valueChanged(int)),
            ui->progressBar,SLOT(setValue(int)));

    connect(ui->horizontalSlider,SIGNAL(valueChanged(int)),
            ui->progressBar_2,SLOT(setValue(int)));

    //disconnect(ui->horizontalSlider,SIGNAL(valueChanged(int)),
      //         ui->progressBar,SLOT(setValue(int)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

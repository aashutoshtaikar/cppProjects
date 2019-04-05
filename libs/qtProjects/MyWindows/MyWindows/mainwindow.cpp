#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"mydialog.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setCentralWidget(ui->plainTextEdit); //fills the entire window area(central widget) by the text editor
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionNewWindow_triggered()
{
    //1. when you wish to trigger and show the dialog and disable the main window-------
    //MyDialog mDialog;
    //mDialog.setModal(true);
    //mDialog.exec();

    //2. when you wish to trigger and show the dialog but keep the main window enabled-----
    //this: QMainWindow(this) that we created is the parent of the dialog
    //Note: myDialog *mDialog is declared in the mainwindow.h interface
    mDialog = new MyDialog(this);
    mDialog->show();
}

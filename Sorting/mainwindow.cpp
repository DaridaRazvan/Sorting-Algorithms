#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    Rectangle *rect = new Rectangle(25);
    rect->setPos(50,100);
    ui->setupUi(this);


}

MainWindow::~MainWindow()
{
    delete ui;
}


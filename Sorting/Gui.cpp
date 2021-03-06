#include <windows.h>
#include <QGraphicsView>
#include <QHBoxLayout>
#include "Gui.h"
#include "Rectangle1.h"
#include "Algorithms.h"
#include <QDebug>
#include <QCoreApplication>
#include <QApplication>
#include <QTime>
#include <QComboBox>

Gui::Gui(QWidget* parent): QWidget{parent}
{
    this->rectangles = 100;
    this->width = 10;
    algorithm = new Algorithms(this->rectangles);
    this->initGui();
    this->connectSignalsAndSlots();
}

Gui::~Gui(){}

void Gui::initGui()
{
    this->setWindowTitle("Sorting Algorithms");

    finalLayout = new QHBoxLayout{this};
    rightLayout = new QVBoxLayout();

    this->sortButton = new QPushButton("Sort!");
    this->refreshButton = new QPushButton("Refresh!");

    scene = new QGraphicsScene(this);
    graphicsView = new QGraphicsView();
    graphicsView->setMinimumSize(300,200);

    graphicsView->setScene(scene);

    comboBox = new QComboBox();
    comboBox->addItem(" ");
    comboBox->addItem("Bubble Sort");
    comboBox->addItem("Insertion Sort");
    comboBox->addItem("Merge Sort");

    int SHIFT = this->width;
    for(int i = 0; i < this->rectangles; i ++)
    {
        int height = rand() % 300 + 1; // values between 1 and 100
        Rectangle1 *rect = new Rectangle1(height,this->width);
        rect->setColumn(i);
        rect->setPos(SHIFT * i,0);
        scene->addItem(rect);
        list.push_back(rect);
    }

    rightLayout->addWidget(comboBox);
    rightLayout->addWidget(sortButton);
    rightLayout->addWidget(refreshButton);

    finalLayout->addWidget(graphicsView);
    finalLayout->addLayout(rightLayout);

}

void Gui::connectSignalsAndSlots(){
    QObject::connect(this->sortButton,SIGNAL(released()),this,SLOT(sort()));
    QObject::connect(this->refreshButton,SIGNAL(released()),this,SLOT(refresh()));
}

void Gui::sort()
{
    QString text = comboBox->currentText();
    if(text == "Bubble Sort")
       this->algorithm->bubbleSort(list);
    else if(text == "Insertion Sort")
        this->algorithm->insertionSort(list);
    else if(text == "Merge Sort")
        this->algorithm->mergeSort(list,0,this->rectangles - 1);
}

void Gui::refresh()
{
    for(int i=0;i < this->rectangles; i++)
    {
        list[i]->setRandomHeight();
    }
}

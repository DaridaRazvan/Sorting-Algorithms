#include "Rectangle1.h"

Rectangle1::Rectangle1(int height,int width,QGraphicsItem *parent):QGraphicsRectItem(parent)
{
    this->height = height;
    this->width = width;
    setRect(0,0,width,height);
    brush.setStyle(Qt::SolidPattern);
    this->setColor(color);
}

Rectangle1::~Rectangle1(){

}

void Rectangle1::setHeight(int height){
    this->height = height;
    setRect(0,0,this->width,height);
}

void Rectangle1::setColumn(int column){
    this->column = column;
}

void Rectangle1::setColor(QColor color){
    brush.setColor(color);
    setBrush(color);
}

void Rectangle1::setRandomHeight()
{
    int randomHeight = rand() % 300 + 1;
    setHeight(randomHeight);
}

int Rectangle1::getHeight(){
    return this->height;
}

int Rectangle1::getColumn(){
    return this->column;
}

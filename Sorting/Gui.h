#ifndef GUI_H
#define GUI_H

#include <QWidget>
#include "Rectangle1.h"
#include "Algorithms.h"

#include <QComboBox>
#include <QPushButton>
#include <QVBoxLayout>
#include <vector>

class Gui : public QWidget
{
    Q_OBJECT
public:
    Gui(QWidget* parent = 0);
    ~Gui();
private:
    int rectangles;
    int width;

    Algorithms* algorithm;

    std::vector<Rectangle1*> list;
    QGraphicsView* graphicsView;
    QGraphicsScene* scene;
    QComboBox* comboBox;
    QPushButton* sortButton;
    QPushButton* refreshButton;
    QHBoxLayout* finalLayout;
    QVBoxLayout* rightLayout;

    void delay();
    void initGui();
    void connectSignalsAndSlots();
    //void populateView();

public slots:
    void sort();
    void refresh();
};

#endif // GUI_H

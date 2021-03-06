#ifndef ALGORITHMS_H
#define ALGORITHMS_H

#include <vector>
#include "Rectangle1.h"

class Algorithms
{
private:
    int columns;
public:
    Algorithms(int columns);
    ~Algorithms();

    void setColumns(int columns);
    int getColumns();

    void bubbleSort(std::vector<Rectangle1*> list);
    void insertionSort(std::vector<Rectangle1*> list);

    //merge sort
    void mergeSort(std::vector<Rectangle1 *> list,int l, int r);
    void merge(std::vector<Rectangle1 *> list,int l, int m, int r);


private:
    void delay();
};

#endif // ALGORITHMS_H

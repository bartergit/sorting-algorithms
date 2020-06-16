#ifndef SORTING_ALGORITHMS_INSERTIONDISPLAY_H
#define SORTING_ALGORITHMS_INSERTIONDISPLAY_H

#include "Display.h"
#include <vector>
using std::vector;

class InsertionDisplay : public Display {
public:
    InsertionDisplay(int fps = 10);
    void sortAndDraw(vector<int> array);
    vector<int> insertionSort(vector<int> array);
};


#endif //SORTING_ALGORITHMS_INSERTIONDISPLAY_H

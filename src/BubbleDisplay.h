//
// Created by Lenovo on 16.06.2020.
//

#ifndef SORTING_ALGORITHMS_BUBBLEDISPLAY_H
#define SORTING_ALGORITHMS_BUBBLEDISPLAY_H

#include "Display.h"
#include <vector>
using std::vector;

class BubbleDisplay : public Display{
public:
    BubbleDisplay(int fps = 10);
    void sortAndDraw(vector<int> array);
    vector<int> insertionSort(vector<int> array);
};


#endif //SORTING_ALGORITHMS_BUBBLEDISPLAY_H

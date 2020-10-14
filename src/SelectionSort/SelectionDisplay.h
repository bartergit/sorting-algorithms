//
// Created by Lenovo on 21.06.2020.
//

#ifndef SORTING_ALGORITHMS_SELECTIONDISPLAY_H
#define SORTING_ALGORITHMS_SELECTIONDISPLAY_H

#include "../_Display/Display.h"
#include <vector>
using std::vector;

class SelectionDisplay : public Display{
public:
    SelectionDisplay(int fps = 10);
    vector<int> sortAndDraw(vector<int> array);
    static vector<int> selectionSort(vector<int> array);
};


#endif //SORTING_ALGORITHMS_SELECTIONDISPLAY_H

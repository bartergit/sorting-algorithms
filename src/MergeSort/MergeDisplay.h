#ifndef SORTING_ALGORITHMS_MERGEDISPLAY_H
#define SORTING_ALGORITHMS_MERGEDISPLAY_H


#include "../_Display/Display.h"
#include <vector>
using std::vector;

class MergeDisplay: public Display {
public:
    MergeDisplay(int fps = 10);
    vector<int> sortAndDraw(vector<int> array) override;
    static vector<int> mergeSort(vector<int> array);
};


#endif //SORTING_ALGORITHMS_MERGEDISPLAY_H

#ifndef SORTING_ALGORITHMS_SHAKERDISPLAY_H
#define SORTING_ALGORITHMS_SHAKERDISPLAY_H

#include "Display.h"

class ShakerDisplay : public Display {
public:
    ShakerDisplay(int fps = 10);
    void sortAndDraw(std::vector<int> array);
    static std::vector<int> shakerSort(std::vector<int> array);
};


#endif //SORTING_ALGORITHMS_SHAKERDISPLAY_H

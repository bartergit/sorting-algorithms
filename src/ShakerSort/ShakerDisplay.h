#ifndef SORTING_ALGORITHMS_SHAKERDISPLAY_H
#define SORTING_ALGORITHMS_SHAKERDISPLAY_H

#include "../_Display/Display.h"

class ShakerDisplay : public Display {
public:
    ShakerDisplay(int fps = 10);
    std::vector<int> sortAndDraw(std::vector<int> array);
    static std::vector<int> shakerSort(std::vector<int> array);
};


#endif //SORTING_ALGORITHMS_SHAKERDISPLAY_H

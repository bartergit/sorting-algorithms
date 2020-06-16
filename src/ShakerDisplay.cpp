#include "ShakerDisplay.h"
#include <vector>
using std::vector;

ShakerDisplay::ShakerDisplay(int fps) : Display(fps) {
    window.setTitle("Shaker Sort");
}

void ShakerDisplay::sortAndDraw(vector<int> array) {
    int *start = &array[0];
    int *end = &array[array.size() - 1];
    int *current = start;
    bool isSwapped = true;
    while (isSwapped) {
        isSwapped = false;
        while (current < end) {
            if (*current > *(current + 1)) {
                isSwapped = true;
                std::swap(*current, *(current + 1));
                drawArray(array, current - &array[0]);
            }
            current++;
        }
        end--;
        while (current > start) {
            if (*current < *(current - 1)) {
                isSwapped = true;
                std::swap(*current, *(current - 1));
                drawArray(array, current - &array[0]);
            }
            current--;
        }
        start++;
    }
    this->drawArray(array);
}

//pure sort
vector<int> ShakerDisplay::shakerSort(vector<int> array) {
    int *start = &array[0];
    int *end = &array[array.size() - 1];
    int *current = start;
    bool isSwapped = true;
    while (isSwapped) {
        isSwapped = false;
        while (current < end) {
            if (*current > *(current + 1)) {
                isSwapped = true;
                std::swap(*current, *(current + 1));
            }
            current++;
        }
        end--;
        while (current > start) {
            if (*current < *(current - 1)) {
                isSwapped = true;
                std::swap(*current, *(current - 1));
            }
            current--;
        }
        start++;
    }
    return array;
}

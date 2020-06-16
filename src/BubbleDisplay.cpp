#include "BubbleDisplay.h"
#include "Display.h"

BubbleDisplay::BubbleDisplay(int fps) : Display(fps) {
    window.setTitle("Bubble Sort");
}

void BubbleDisplay::sortAndDraw(vector<int> array){
    bool isSwapped = true;
    for (unsigned int i = 0; i < array.size() - 1 && isSwapped; i++) {
        isSwapped = false;
        for (unsigned int j = 0; j < array.size() - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                isSwapped = true;
                std::swap(array[j], array[j + 1]);
                this->drawArray(array, j);
            }
        }
    }
    this->drawArray(array);
}
//pure sort
vector<int> BubbleDisplay::insertionSort(vector<int> array){
    bool isSwapped = true;
    for (unsigned int i = 0; i < array.size() - 1 && isSwapped; i++) {
        isSwapped = false;
        for (unsigned int j = 0; j < array.size() - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                isSwapped = true;
                std::swap(array[j], array[j + 1]);
            }
        }
    }
    return array;
}
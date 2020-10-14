#include "InsertionDisplay.h"

InsertionDisplay::InsertionDisplay(int fps) : Display(fps) {
    window.setTitle("Insertion Sort");
}

vector<int> InsertionDisplay::sortAndDraw(vector<int> array) {
    int *first_el = &array[0];
    for (int i = 0; i < array.size(); i++) {
        int *element = &array[i];
        while (*element < *(element - 1) and element - 1 >= first_el) {
            std::swap(*element, *(element - 1));
            element--;
            drawArray(array, element - first_el);
        }
    };
    drawArray(array);
    return array;
}

//pure sort
vector<int> InsertionDisplay::insertionSort(vector<int> array) {
    int *first_el = &array[0];
    for (int i = 0; i < array.size(); i++) {
        int *element = &array[i];
        while (*element < *(element - 1) and element - 1 >= first_el) {
            std::swap(*element, *(element - 1));
            element--;
        }
    };
    return array;
}

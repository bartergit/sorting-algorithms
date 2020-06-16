//
// Created by Lenovo on 16.06.2020.
//

#include "InsertionDisplay.h"
#include "Display.h"

InsertionDisplay::InsertionDisplay(int fps) : Display(fps) {
    window.setTitle("Insertion Sort");
}

void InsertionDisplay::sortAndDraw(vector<int> array) {
    int *first_el = &array[0];
    for (int i = 0; i < array.size(); i++) {
        int *element = &array[i];
        while (*element < *(element - 1) and element - 1 >= first_el) {
            std::swap(*element, *(element - 1));
            element--;
            this->drawArray(array, element - first_el);
        }
    };
    this->drawArray(array);
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

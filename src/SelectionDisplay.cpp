//
// Created by Lenovo on 21.06.2020.
//

#include "SelectionDisplay.h"
#include "Display.h"
#include <iostream>
#include "utility.h"

SelectionDisplay::SelectionDisplay(int fps) : Display(fps) {
    window.setTitle("Selection sort");
}

void SelectionDisplay::sortAndDraw(vector<int> array){
    int * start = &array[0];
    int * end = &array[array.size() - 1];
    while (end - start >= 1) {
        int * max = start;
        int * min = start;
        for (auto ptr = start + 1; ptr <= end; ptr++){
            if (*ptr < *min)
                min = ptr;
            if (*ptr > *max)
                max = ptr;
        }
        std::swap(*start++, *min);
        this->drawArray(array);
    }
    this->drawArray(array);
}
//pure sort
vector<int> SelectionDisplay::selectionSort(vector<int> array){
    int * start = &array[0];
    int * end = &array[array.size() - 1];
    while (end - start >= 1) {
        int * max = start;
        int * min = start;
        for (auto ptr = start + 1; ptr <= end; ptr++){
            if (*ptr < *min)
                min = ptr;
            if (*ptr > *max)
                max = ptr;
        }
        std::swap(*start++, *min);
    }
    return array;
}

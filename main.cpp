#include <SFML/Graphics.hpp>
#include <ctime>
#include <iostream>
#include <cstdlib>
#include "src/BubbleSort/BubbleDisplay.h"
#include "src/ShakerSort/ShakerDisplay.h"
#include "src/InsertionSort/InsertionDisplay.h"
#include "src/SelectionSort/SelectionDisplay.h"
#include "src/_Display/Display.h"
#include "src/utility.h"
#include "src/MergeSort/MergeDisplay.h"

using std::string;
using std::vector;
using std::cout;

int main() {
    srand(time(nullptr));
//    auto mergeSortPtr = new MergeDisplay;
//    repr((*mergeSortPtr).mergeSort(Display::getMixedArray(11)));
//    repr((*mergeSortPtr).mergeSort(Display::getMixedArray(10)));
//    (*mergeSortPtr).setArray(Display::getMixedArray(10));
//    (*mergeSortPtr).startLoop();
    auto mergeSortPtr = new MergeDisplay;
    auto shakerDisplayPtr = new ShakerDisplay;
    auto insertionDisplayPtr = new InsertionDisplay;
    auto bubbleDisplayPtr = new BubbleDisplay;
    auto selectionDisplayPtr = new SelectionDisplay;
    vector <Display*> displayVector = {mergeSortPtr, selectionDisplayPtr, bubbleDisplayPtr, insertionDisplayPtr, shakerDisplayPtr};
    for (auto i = 0; i < displayVector.size(); i++){
        (*displayVector[i]).setArray(Display::getMixedArray(10));
        (*displayVector[i]).startLoop();
    }
}
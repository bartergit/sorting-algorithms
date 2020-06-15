#include <SFML/Graphics.hpp>
#include <ctime>
#include <iostream>
#include <cstdlib>
#include "src/bubbleSort.cpp"
#include "src/insertionSort.cpp"
#include "src/utility.cpp"

using std::string;
using std::vector;
using std::cout;

int main() {
    srand(time(nullptr));
    vector<int> array = {100, 38, 4, 3, 46, 50, -5, 18};
    array = {3, 44, 11, 38, 5, -9, -19, 47, 15, 36, 26, 27, -64, 2, 38, 46, 4, 28, 33, 0, 19, 50, 48};
    vector<int> sortedArray = insertionSort(array);
    cout << repr(sortedArray) << "\n" << repr(array);
    Drawer drawer;
    drawer.setArray(array);
    drawer.startLoop();
//    dr.insertionSortAndDraw(array);
}
#include <vector>
#include <iostream>
#include "utility.h"

using std::cout;
using std::pair;
using std::vector;

vector<int> bubbleSort(vector<int> array) {
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

vector<int> bubbleSort(vector<int> array, vector<vector<int>> &states, vector<pair<int, int>> &pairs) {
    bool isSwapped = true;
    for (unsigned int i = 0; i < array.size() - 1 && isSwapped; i++) {
        isSwapped = false;
        for (unsigned int j = 0; j < array.size() - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                isSwapped = true;
                std::swap(array[j], array[j + 1]);
                pairs.push_back(pair<int, int>(j, j + 1));
                states.push_back(array);
            }
        }
    }
    return array;
}

//vector<int> bubbleSortGenerator(vector<int> &array) {     // lazy evaluation, each call gives you one rearrangement
//    bool isSwapped = true;
//    static int i = 0;
//    static int j = 0;
//    if (j < array.size() - i - 1) {
//        if (array[j] > array[j + 1]) {
//            isSwapped = true;
//            std::swap(array[j], array[j + 1]);
////            cout << j << " " << j + 1 << "\n";
//            return vector<int>{j++, j + 1};
//        } else {
//            j++;
//        }
//    } else {
//        j = 0;
//        if (i + 1 < array.size() - 1) {
//            i++;
//            bubbleSortGenerator(array);
//        } else {
//            return vector<int>{-1,-1};
//        }
//    }
//}
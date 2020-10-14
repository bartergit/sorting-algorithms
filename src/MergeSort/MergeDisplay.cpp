#include "MergeDisplay.h"
#include <iostream>
#include "../utility.h"

MergeDisplay::MergeDisplay(int fps) : Display(fps) {
    window.setTitle("Merge sort");
}

vector<int> MergeDisplay::sortAndDraw(vector<int> array){
    if (array.size() < 2)
        return array;
    int ind = array.size() / 2;
    vector<int> A(ind);
    vector<int> B(array.size() - ind);
    copy(array.begin(), array.begin() + ind, A.begin());
    copy(array.begin() + ind, array.end(), B.begin());
    A = sortAndDraw(A);
    B = sortAndDraw(B);
    vector<int> result;
    auto a_ptr = &A[0], b_ptr = &B[0], a_end = &A[A.size() - 1], b_end = &B[B.size() - 1];
    while (a_ptr <= a_end or b_ptr <= b_end){
        if (a_ptr > a_end){
            result.push_back(*b_ptr++);
            drawArray(array);
            continue;
        }
        if (b_ptr > b_end){
            result.push_back(*a_ptr++);
            drawArray(array);
            continue;
        }
        if (*a_ptr < *b_ptr){
            result.push_back(*a_ptr++);
            drawArray(array);
        } else {
            result.push_back(*b_ptr++);
            drawArray(array);
        }
    }
    drawArray(array);
}
//pure sort
vector<int> MergeDisplay::mergeSort(vector<int> array){
    if (array.size() < 2)
        return array;
    int ind = array.size() / 2;
    vector<int> A(ind);
    vector<int> B(array.size() - ind);
    copy(array.begin(), array.begin() + ind, A.begin());
    copy(array.begin() + ind, array.end(), B.begin());
    A = mergeSort(A);
    B = mergeSort(B);
    vector<int> result;
    auto a_ptr = &A[0], b_ptr = &B[0], a_end = &A[A.size() - 1], b_end = &B[B.size() - 1];
    while (a_ptr <= a_end or b_ptr <= b_end){
        if (a_ptr > a_end){
            result.push_back(*b_ptr++);
            continue;
        }
        if (b_ptr > b_end){
            result.push_back(*a_ptr++);
            continue;
        }
        if (*a_ptr < *b_ptr){
            result.push_back(*a_ptr++);
        } else {
            result.push_back(*b_ptr++);
        }
    }
    return result;
}

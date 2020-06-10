#include <iostream>
#include <cstdlib>
#include <vector>

using std::string;
using std::vector;
using std::cout;

int random(int min, int max) {
    return std::rand() % (max + 1) + min;
}

string repr(vector<int> array){
    string representation = "[";
    for (auto i: array)
        representation.append(std::to_string(i) + ", ");
    representation.erase(representation.length() - 2);
    return representation.append("]");
}
#include <SFML/Graphics.hpp>
#include <ctime>
#include <iostream>
#include <cstdlib>
#include "src/BubbleDisplay.h"
#include "src/ShakerDisplay.h"
#include "src/InsertionDisplay.h"
#include "src/utility.h"

using std::string;
using std::vector;
using std::cout;

int main() {
    srand(time(nullptr));
    auto * shakerDisplayPtr = new ShakerDisplay;
    auto * insertionDisplayPtr = new InsertionDisplay;
    auto * bubbleDisplayPtr = new BubbleDisplay;
    vector <Display*> displayVector = {bubbleDisplayPtr, insertionDisplayPtr, shakerDisplayPtr};
    for (auto i = 0; i < displayVector.size(); i++){
        (*displayVector[i]).setArray(Display::getMixedArray());
        (*displayVector[i]).startLoop();
    }
}
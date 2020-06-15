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


void startDraw(vector<int> array) {
    int HEIGHT = 480;
    int WIDTH = 640;
    sf::Font font;
    font.loadFromFile("C:\\_git\\sorting-algorithms\\arial.ttf");
    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Title!");
    window.setFramerateLimit(10);
    vector<vector<int>> states = {array};
    vector<pair<int, int>> pairs = {};
    bubbleSort(array, states, pairs);
    int state_ind = -1;
    int pair_ind = -1;
    bool flag = true;
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();
        int size = states[0].size();
        int margin = 10;
        int min_height = *std::min_element(states[0].begin(), states[0].end());
        int max_height = *std::max_element(states[0].begin(), states[0].end());
        int difference_height = max_height - min_height;
        float width = (WIDTH - margin * (size + 1)) / size;
        flag = !flag;
        if (flag)
            pair_ind++;
        else
            state_ind++;
        if (state_ind >= states.size() - 1) {
            state_ind = states.size() - 1;
            pair_ind = -1;
        }
        for (int i = 0; i < size; i++) {
            double height =
                    double(states[state_ind][i] - min_height) / difference_height *
                    (HEIGHT - 3 * margin) + margin;
            if (i == pairs[pair_ind].first || i == pairs[pair_ind].second) {
                drawRect(window, margin + int(width + margin) * i, HEIGHT - margin, (int) width, -int(height),
                         sf::Color::Red);
            } else {
                drawRect(window, margin + int(width + margin) * i, HEIGHT - margin, (int) width, -int(height));
            }
            drawText(window, font, std::to_string(states[state_ind][i]), (int) width / 2,
                     margin + int(width + margin) * i + width / 2, int(HEIGHT - width / 2 - margin));
        }
        window.display();
    }
}

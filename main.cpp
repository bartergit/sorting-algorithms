#include <SFML/Graphics.hpp>
#include <ctime>
#include <iostream>
#include <cstdlib>
#include "bubbleSort.cpp"
#include "utility.cpp"

using std::string;
using std::vector;
using std::cout;


void drawRect(sf::RenderWindow &window, int x, int y, int width, int height, sf::Color color = sf::Color::Green) {
    sf::RectangleShape rect(sf::Vector2f(width, height));
    rect.setFillColor(color);
    sf::Transform transform =
            sf::Transform().translate(x, y);//* sf::Transform().rotate(angle);
    window.draw(rect, sf::RenderStates(transform));
}

void drawText(sf::RenderWindow &window, sf::Font &font, string textValue, int size, int x, int y) {
    sf::Text text;
    text.setFont(font);
    text.setString(textValue);
    text.setCharacterSize(size); // in pixels, not points!
    text.setFillColor(sf::Color::White);
    text.setStyle(sf::Text::Bold);// | sf::Text::Underlined);
    sf::FloatRect textRect = text.getLocalBounds();
    text.setOrigin(textRect.left + textRect.width / 2.0f,
                   textRect.top + textRect.height / 2.0f);
    text.setPosition(sf::Vector2f(x, y));
    window.draw(text);
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
        }\
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

int main() {
    srand(time(nullptr));
    vector<int> array1 = {38, 4, 3, 46, 50, -5, 18};
    array1 = {3, 44, 11, 38, 5, -9, -19, 47, 15, 36, 26, 27, -64, 2, 38, 46, 4, 28, 33, 0, 19, 50, 48};
    startDraw(array1);
}
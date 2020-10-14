#include "Display.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <random>
#include <chrono>

using std::vector;


Display::Display(int fps) {
    this->fps = fps;
    shouldDraw = false;
}

void Display::startLoop() {
    window.create(sf::VideoMode(WIDTH, HEIGHT), "Title!");
    window.setFramerateLimit(this->fps);
    font.loadFromFile(R"(C:\_git\sorting-algorithms\arial.ttf)");
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        if (shouldDraw) {
            this->sortAndDraw(arrayToDraw);
            shouldDraw = false;
        }
    }
}

void Display::setArray(vector<int> array) {
    this->arrayToDraw = array;
    this->shouldDraw = true;
}

void Display::drawArray(vector<int> array, int activePareInd) {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            window.close();
    }
    window.clear();
    int size = array.size();
    int margin = 10;
    int min_height = *std::min_element(array.begin(), array.end());
    int max_height = *std::max_element(array.begin(), array.end());
    int difference_height = max_height - min_height;
    float width = (WIDTH - margin * (size + 1)) / size;
    for (int i = 0; i < size; i++) {
        double height =
                double(array[i] - min_height) / difference_height *
                (HEIGHT - 3 * margin) + margin;
        sf::Color color = (i == activePareInd or i == activePareInd + 1) ? sf::Color::Red : sf::Color::Green;
        drawRect(window, margin + int(width + margin) * i, HEIGHT - margin, (int) width, -int(height), color);
        drawText(window, font, std::to_string(array[i]), (int) width / 2,
                 margin + int(width + margin) * i + width / 2, int(HEIGHT - width / 2 - margin));
    }
    window.display();
}

std::vector<int> Display::getMixedArray(int range, int start) {
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    vector<int> array = {};
    for (int i = start; i < range + start; i++) {
        array.push_back(i);
    }
    std::shuffle(array.begin(), array.end(), std::default_random_engine(seed));
    return array;
}

void Display::drawRect(sf::RenderWindow &window, int x, int y, int width, int height, sf::Color color) {
    sf::RectangleShape rect(sf::Vector2f(width, height));
    rect.setFillColor(color);
    sf::Transform transform =
            sf::Transform().translate(x, y);//* sf::Transform().rotate(angle);
    window.draw(rect, sf::RenderStates(transform));
}

void Display::drawText(sf::RenderWindow &window, sf::Font &font, std::string textValue, int size, int x, int y) {
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




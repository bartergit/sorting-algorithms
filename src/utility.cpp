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

void drawRect(sf::RenderWindow &window, int x, int y, int width, int height, sf::Color color) {
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


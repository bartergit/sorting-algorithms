#include <vector>

int random(int min, int max);

std::string repr(std::vector<int> array);

void drawRect(sf::RenderWindow &window, int x, int y, int width, int height, sf::Color color = sf::Color::Green);

void drawText(sf::RenderWindow &window, sf::Font &font, std::string textValue, int size, int x, int y);
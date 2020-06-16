#ifndef SORTING_ALGORITHMS_DISPLAY_H
#define SORTING_ALGORITHMS_DISPLAY_H


#include <vector>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Font.hpp>
// base class to draw stuff

class Display {
protected:
    int HEIGHT = 480;
    int WIDTH = 640;
    sf::Font font;
    sf::RenderWindow window;
    bool shouldDraw;
    std::vector<int> arrayToDraw;
    int fps;
public:
    Display(int fps = 10);
    void startLoop();
    void setArray(std::vector<int> array);
    virtual void sortAndDraw(std::vector<int> arrayToDraw) = 0;
    void drawArray(std::vector<int> array, int activePareInd = -2);
    void drawRect(sf::RenderWindow &window, int x, int y, int width, int height, sf::Color color);
    void drawText(sf::RenderWindow &window, sf::Font &font, std::string textValue, int size, int x, int y);
    static std::vector<int> getMixedArray(int range = 10, int start = 0);
};


#endif //SORTING_ALGORITHMS_DISPLAY_H

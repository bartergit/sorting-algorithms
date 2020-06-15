//    Создадим массив, в котором после завершения алгоритма будет лежать ответ. Будем поочередно вставлять элементы из
//    исходного массива так, чтобы элементы в массиве-ответе всегда были отсортированы. Асимптотика в среднем и худшем случае – O(n2),
//    в лучшем – O(n). Реализовывать алгоритм удобнее по-другому (создавать новый массив и реально что-то вставлять в него относительно сложно):
//    просто сделаем так, чтобы отсортирован был некоторый префикс исходного массива, вместо вставки будем менять текущий элемент с предыдущим,
//    пока они стоят в неправильном порядке.

#include <vector>
#include <iostream>

using std::cout;
using std::swap;
using std::vector;

vector<int> insertionSort(vector<int> array) {
    int * first_el = &array[0];
    for (int i = 0; i < array.size(); i++){
        int * element = &array[i];
        while (*element < *(element-1) and element - 1 >= first_el){
            swap(*element, *(element-1));
            element--;
        }
    };
    return array;
}

class Drawer{
private:
    int HEIGHT = 480;
    int WIDTH = 640;
    sf::Font font;
    sf::RenderWindow window;
    bool shouldDraw;
    vector<int> arrayToDraw;
    int fps;
public:
    Drawer(int fps=10){
        window.create(sf::VideoMode(WIDTH,HEIGHT), "Title!");
        window.setFramerateLimit(fps);
        font.loadFromFile(R"(C:\_git\sorting-algorithms\arial.ttf)");
        shouldDraw = false;
    }

    void startLoop(){
        while (window.isOpen()) {
            sf::Event event;
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed)
                    window.close();
            }
            if (shouldDraw){
                this->insertionSortAndDraw(arrayToDraw);
                shouldDraw = false;
            }
        }
    }

    void setArray(vector<int> array){
        this->arrayToDraw = array;
        this->shouldDraw = true;
    }

    vector<int> insertionSortAndDraw(vector<int> array) {
        int * first_el = &array[0];
        for (int i = 0; i < array.size(); i++){
            int * element = &array[i];
            while (*element < *(element-1) and element - 1 >= first_el){
                swap(*element, *(element-1));
                element--;
                drawArray(array, element - first_el);
            }
        };
        drawArray(array);
    }

    void drawArray(vector<int> array, int activePareInd = -2){
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
};

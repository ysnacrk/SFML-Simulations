#include "circle.h"
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;

using namespace sf;

int main()
{
    RenderWindow window(VideoMode(1000 ,1000 ), "Fourier") ;   

    window.setFramerateLimit(60);

    Circle circle;
    circle.setCirclePosition({100 , 100});
    circle.setCircleRadius(100);

    Circle circle2;
    circle2.setCircleRadius(50);
    circle2.setCirclePosition({circle.getCirclePositionX() + (2*circle.getCircleRadius()) - circle2.getCircleRadius() , circle.getCirclePositionY() + circle.getCircleRadius() - circle2.getCircleRadius()});
    circle2.setCircleColor();

    int i =0;
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        circle2.setRotate(circle2.getRotate() + 1 );
        window.clear(sf::Color::Black);
        circle.drawCircle(window);
        circle2.drawCircle(window);
        window.display();
        i += 2;
    }
    return 0;
}

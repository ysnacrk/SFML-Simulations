#include "circle.h"
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;

using namespace sf;

int main()
{
    RenderWindow window(VideoMode(1000 ,1000 ), "Fourier") ;   

    window.setFramerateLimit(30);

    RectangleShape line({100 , 2});
    line.setFillColor(Color(164, 164, 164));


    Circle circle;
    circle.setCirclePosition({100 , 100});
    circle.setCircleRadius(100);

    Circle circle2;
    circle2.setCircleRadius(50);
    circle2.setCirclePosition({circle.getCirclePositionX() + (2*circle.getCircleRadius()) - circle2.getCircleRadius() , circle.getCirclePositionY() + circle.getCircleRadius() - circle2.getCircleRadius()});
    circle2.setCircleColor();

    line.setPosition({circle.getCirclePositionX() + circle.getCircleRadius(), circle.getCirclePositionY() + circle.getCircleRadius()});

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        line.rotate(-4);
        circle2.setCirclePosition(line.getTransform().transformPoint( line.getSize().x , line.getSize().y/2));
        circle2.setCirclePosition({circle2.getCirclePositionX() - circle2.getCircleRadius(), circle2.getCirclePositionY() - circle2.getCircleRadius()});
        window.clear(sf::Color::Black);
        circle.drawCircle(window);
        circle2.drawCircle(window);
        window.draw(line);
        window.display();
    }
    return 0;
}

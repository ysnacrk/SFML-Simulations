#include "circle.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

using namespace std;

using namespace sf;

int main()
{
    float x = 0.1;
    RenderWindow window(VideoMode(1000 ,1000 ), "Fourier") ;   

    window.setFramerateLimit(30);

    RectangleShape line({100 , 2});
    RectangleShape line2({1, 2});
    RectangleShape line3({1000, 2});
    RectangleShape line4({100 , 2});
    RectangleShape line5({1, 2});




    line.setFillColor(Color(164, 164, 164));
    line2.setFillColor(Color(0, 255, 0));
    line3.setFillColor(Color(255, 0, 0));
    line4.setFillColor(Color(164, 164, 164));


    Circle circle;
    Circle circle2;
    vector <Circle> v;
    vector <Circle> v2;


    circle.setCirclePosition({0 , 0});
    circle.setCircleRadius(100);
    circle.setOp();

    line.setPosition({circle.getCirclePositionX() + circle.getCircleRadius(), circle.getCirclePositionY() + circle.getCircleRadius()});
    line2.setPosition(line.getTransform().transformPoint( line.getSize().x , line.getSize().y));

    line3.setPosition(line.getTransform().transformPoint( line.getSize().x , line.getSize().y));
    line4.setPosition({circle.getCirclePositionX() + circle.getCircleRadius(), circle.getCirclePositionY() + circle.getCircleRadius()});
    line5.setPosition(line4.getTransform().transformPoint( line4.getSize().x , line4.getSize().y));
    
    
    line4.rotate(-90);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        
        Circle circle2;
        circle2.setCircleRadius(1);

        
        Circle circle3;
        circle3.setCircleRadius(1);
        circle3.setColor();

        line.rotate(-3);
        line4.rotate(-3);
        
        line2.setPosition(line.getTransform().transformPoint( line.getSize().x , line.getSize().y));
        line2.setSize({ ((2*circle.getCircleRadius()) - line2.getPosition().x) , 2});
        
        line5.setPosition(line4.getTransform().transformPoint( line4.getSize().x , line4.getSize().y));
        line5.setSize({ ((2*circle.getCircleRadius()) - line5.getPosition().x) , 2});  

        circle2.setCirclePosition({line2.getTransform().transformPoint( line2.getSize().x + x , line2.getSize().y)});
        circle3.setCirclePosition({line5.getTransform().transformPoint( line5.getSize().x + x , line5.getSize().y)});

        
        window.clear(sf::Color::Black);
        circle.drawCircle(window);
        circle2.drawCircle(window);
        circle3.drawCircle(window);

        v.push_back(circle2);
        v2.push_back(circle3);


        window.draw(line);
        window.draw(line2);
        window.draw(line3);
        window.draw(line4);
        window.draw(line5);



        
        for (auto i : v)
            i.drawCircle(window);
            
        for (auto i : v2)
            i.drawCircle(window);

        window.display();
        x += 1.9 ;
    }
    return 0;
}

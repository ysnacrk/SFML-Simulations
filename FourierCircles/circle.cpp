#include "circle.h"


Circle::Circle(){
    circle.setFillColor(Color::Black);  
    circle.setOutlineThickness(2);
    circle.setOutlineColor(Color(164, 164, 164));
}


void Circle::drawCircle(RenderWindow &window){
        window.draw(circle);
}
void Circle::setCirclePosition(Vector2f position){
    circle.setPosition(position);
}
void Circle::setCircleRadius(float R){
    circle.setRadius(R);
}

void Circle::setCircleColor(){
    circle.setFillColor(Color::Transparent);
}
void Circle::setRotate(int angle){

    circle.setRotation(angle);
}

void Circle::setCircleOrigin(Vector2f originCoordinates){
    circle.setOrigin(originCoordinates);
}
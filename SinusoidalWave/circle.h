#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;
using namespace sf;

class Circle{
        public:
            Circle();
            void drawCircle(RenderWindow &window);
            void move();
            float getCirclePositionX(){
                return circle.getPosition().x;
            }
            float getCirclePositionY(){
                return circle.getPosition().y;
            }
            float getCircleRadius(){ return circle.getRadius() ;}

            void setCirclePosition(Vector2f coordinates);
            void setCircleRadius(float R);
            void setCircleColor();
            void setRotate(int angle);
            void setCircleOrigin(Vector2f originCooridinates);
            void setOp();
            void setColor();


            int getRotate(){ return circle.getRotation() ;}
        private:

            CircleShape circle;
};
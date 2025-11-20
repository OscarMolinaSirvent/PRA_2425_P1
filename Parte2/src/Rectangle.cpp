#include "Rectangle.h"

Rectangle::Rectangle() : Shape(){
	vs = new Point2D[3];
	vs[0] = Point2D(-1,0.5);
	vs[1] = Point2D(1,0.5);
	vs[2] = Point2D(1,-0.5);
	vs[3] = Point2D(-1,-0.5);
}

Rectangle::Rectangle(std::string color, Point2D* vertices) : Shape(color){
	

}

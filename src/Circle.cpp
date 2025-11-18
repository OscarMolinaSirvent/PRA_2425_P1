#include "Circle.h"
#include <ostream>

Circle::Circle() : Shape(){
	center = Point2D(0,0);	
	radius = 1;
}

Circle::Circle(std::string color, Point2D center, double radius) : 
	Shape(color), radius{radius}{}

Point2D Circle::get_center() const{
	return center;
}

double Circle::get_radius() const{
	return radius;
}

void Circle::set_radius(double r){
	radius = r;
}

std::ostream& operator<<(std::ostream &out, const Circle &c){
	out << "Circulo\n" << "Centro en " << c.get_center() << 
		"Radio: " << c.get_radius() << 
		"Color: " << c.color << std::endl;   
	return out;
}

double Circle::area() const override{
	return (M_PI * pow(radius,2);
} 

double Circle::perimeter() const override{
	return (2*M_PI*radius);
}

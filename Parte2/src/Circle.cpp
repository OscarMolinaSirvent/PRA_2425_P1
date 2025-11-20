#include "Circle.h"
#include <iostream>

Circle::Circle() : Shape(){
	center = Point2D(0,0);	
	radius = 1;
}

Circle::Circle(std::string color, Point2D center, double radius) : 
	Shape(color), radius{radius}{}

Point2D Circle::get_center() const{
	return center;
}

void Circle::set_center(Point2D p){
	center.x = p.x;
	center.y = p.y;
}

double Circle::get_radius() const{
	return radius;
}

void Circle::set_radius(double r){
	radius = r;
}

std::ostream& operator<<(std::ostream &out, const Circle &c){
	out << "[Circulo: " << "centro = " << c.get_center() <<"; " 
		"radio = " << c.get_radius() << "; "
		"color = " << c.color <<"]"<<std::endl;   
	return out;
}

double Circle::area() const {
	return (M_PI * pow(radius,2));
} 

double Circle::perimeter() const {
	return (2*M_PI*radius);
}

void Circle::translate(double incX, double incY){
	center.x += incX;
	center.y += incY;
}

void Circle::print(){
	std::cout << "Centro: " << center <<
		"Radio: " << radius << 
		"Color: " << color << std::endl;
}

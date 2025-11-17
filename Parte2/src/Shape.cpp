#include "Shape.h"

Shape::Shape(){
	color = "rojo";
}

Shape::Shape(std::string color) : color{color} {}

std::string Shape::get_color() const{ return color; }

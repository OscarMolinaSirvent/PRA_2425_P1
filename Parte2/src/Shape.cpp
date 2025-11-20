#include "Shape.h"
#include <stdexcept>

Shape::Shape(){
	color = "red";
}

Shape::Shape(std::string color) : color{color} {
	if(color != "red" && color != "green" && color != "blue"){
		throw std::invalid_argument("Color incorrecto\n");
	}
}

std::string Shape::get_color() const{ return color; }

void Shape::set_color(std::string c){ 
	if(color != "red" && color != "green"&& color != "blue"){
		throw std::invalid_argument("Color incorrecto\n");
	}
	color = c;
}

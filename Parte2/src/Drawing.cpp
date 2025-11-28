#include "Drawing.h"

Drawing::Drawing(){
	shapes = new ListArray<Shape*>();
}

Drawing::~Drawing(){
	delete shapes[];
	shapes = nullptr;
}

void Drawing::add_front(Shape* shape){}

void Drawing::add_back(Shape* shape){}

void Drawing::print_all

#include "Drawing.h"
#include <iostream>
#include <cmath>

Drawing::Drawing(){
	shapes = new ListArray<Shape*>();
}

Drawing::~Drawing(){
	delete shapes;
	shapes = nullptr;
}

void Drawing::add_front(Shape* shape){
    shapes -> prepend(shape);
}

void Drawing::add_back(Shape* shape){
    shapes -> append(shape);
}

void Drawing::print_all(){
    int n = shapes -> size();
    for(int i = 0; i < n; i++){
	if(Square *sq = dynamic_cast<Square*>(shapes -> get(i))){
	    std::cout << *sq;
	}   
	if(Circle *c = dynamic_cast<Circle*>(shapes -> get(i))) {
            std::cout << *c;
        }
        if(Rectangle *r = dynamic_cast<Rectangle*>(shapes -> get(i))){
            std::cout << *r;
        }

        std::cout << std::endl;
    }
}

double Drawing::get_area_all_circles(){
    int n = shapes -> size();
    double area = 0;
    for(int i = 0 ; i < n; i++){
        if(Circle *c = dynamic_cast<Circle*>(shapes -> get(i))){
            area += M_PI * pow((c -> get_radius()),2);
        }
    }
    return area;
}

void Drawing::move_squares(double incX, double incY){
    int n = shapes -> size();
    for(int i = 0; i < n; i++){
        if(Square* sq = dynamic_cast<Square*>(shapes -> get(i))){
            sq -> translate(incX,incY);
            }
        }
}

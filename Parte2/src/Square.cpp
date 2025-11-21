#include "Square.h"

Square::Square() : Rectangle(){
	vs[0] = Point2D(-1,1);
	vs[1] = Point2D(1,1);
	vs[2] = Point2D(1,-1);
	vs[3] = Point2D(-1,-1);
} 

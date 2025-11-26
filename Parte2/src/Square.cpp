#include "Square.h"

Square::Square() : Rectangle(){
	vs[0] = Point2D(-1,1);
	vs[1] = Point2D(1,1);
	vs[2] = Point2D(1,-1);
	vs[3] = Point2D(-1,-1);
} 
Square::Square(std::string color, Point2D* vertices) : Rectangle(color,vertices){
	if(check(vertices) == 0){
		throw std::invalid_argument("Vertices erroneos");
	}
}

void Square::set_vertices(Point2D* vertices){
	vs[0] = vertices[0];
	vs[1] = vertices[1];
	vs[2] = vertices[2];
	vs[3] = vertices[3];
}

std::ostream& operator<<(std::ostream &out, const Square &square){
	out << "[Square: color = " << square.get_color() << "; " << 
		"v0 = " << square.get_vertex(0) << "; v1 = " << square.get_vertex(1) << 
		"; v2 = " << square.get_vertex(2) << "; v3 = " << square.get_vertex(3) <<
		"]" ;
	return out;
}

void Square::print() {
	std::cout << "[Square: color = " << color << "; " << 
		"v0 = " << vs[0] << "; v1 = " << vs[1] << 
		"; v2 = " << vs[2] << "; v3 = " << vs[3] <<
		"]" ;
}

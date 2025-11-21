#include "Rectangle.h"

Rectangle::Rectangle() : Shape(){
	vs = new Point2D[N_VERTICES];
	vs[0] = Point2D(-1,0.5);
	vs[1] = Point2D(1,0.5);
	vs[2] = Point2D(1,-0.5);
	vs[3] = Point2D(-1,-0.5);
}

Rectangle::Rectangle(std::string color, Point2D* vertices) : Shape(color){
	if(!check(vertices)){
		throw std::invalid_argument("Los puntos no forman un rectangulo");
	}	
	vs = new Point2D[N_VERTICES];
	for(int i = 0; i < N_VERTICES; i++){
		vs[i] = vertices[i];
	}
}

Rectangle::Rectangle(const Rectangle &r) : Shape(r.color){
	this -> vs = new Point2D[N_VERTICES];
	for(int i = 0; i < N_VERTICES; i++){
		vs[i] = r.vs[i];
	}
}

Rectangle::~Rectangle(){
	delete[] vs;
}

Point2D Rectangle::get_vertex(int ind) const{
	if(ind >= N_VERTICES){
		throw std::invalid_argument("No hay tantos vertices");
	}
	return vs[ind];
	
}

Point2D Rectangle::operator[](int ind) const{
	return get_vertex(ind);
}

void Rectangle::set_vertices(Point2D* vertices){
	if(!check(vertices)){
		throw std::invalid_argument("Estos vertices no son validos");
	}
	for(int i = 0; i < N_VERTICES; i++){
		vs[i] = vertices[i];
	}
}

Rectangle& Rectangle::operator=(const Rectangle &r){
	delete[] vs;
	vs = new Point2D[N_VERTICES];
	for(int i = 0; i < N_VERTICES; i++){
		vs[i] = r.vs[i];
	}
	color = r.color;
	return *this;
}

std::ostream& operator<<(std::ostream &out, const Rectangle &r){
	out << "[Rectangulo: color = " << r.get_color() << "; " "v0 = " << r.get_vertex(0) <<"; "
		" v1 = " << r.get_vertex(1)<< "; " << "v2 = " << r.get_vertex(2) << "; " << 
		"v3 = " << r.get_vertex(3) <<"]";
       return out;	
}

double Rectangle::area() const{
	return (Point2D::distance(vs[0],vs[1]) * 
		Point2D::distance(vs[1],vs[2]));
}

double Rectangle::perimeter() const{
	return 2 * ((Point2D::distance(vs[0],vs[1]) + 
		Point2D::distance(vs[1],vs[2])));
}

void Rectangle::translate(double incX, double incY){
	for(int i = 0; i < N_VERTICES; i++){
		vs[i].x += incX;
		vs[i].y += incY;
	}
}

void Rectangle::print(){
	std::cout << "[Rectangulo: color = " << color << "; " "v0 = " << vs[0] <<"; "
		" v1 = " << vs[1] << "; " << "v2 = " << vs[2] << "; " << "v3 = " << vs[3] <<
		"]";
}

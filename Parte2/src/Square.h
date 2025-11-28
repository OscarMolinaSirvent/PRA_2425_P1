#ifndef SQUARE_H
#define SQUARE_H

#include "Rectangle.h"
#include "Point2D.h"
#include "Shape.h"
#include <ostream>

class Square : public Rectangle{

	private:
		static bool check(Point2D* vertices){
			double d1 = Point2D::distance(vertices[0],vertices[1]);
			double d2 = Point2D::distance(vertices[1],vertices[2]);
			double d3 = Point2D::distance(vertices[2],vertices[3]);
			double d4 = Point2D::distance(vertices[3],vertices[0]); 
			return (d1 == d2 && d2 == d3 && d3 == d4);
		}
	
	public:
		Square();
		Square(std::string color, Point2D* vertices);
		void set_vertices(Point2D* vertices) override;
		friend std::ostream& operator<<(std::ostream &out,const Square &square);
		void print() override;
};

#endif

#include "Rectangle.h"
#include "Point2D.h"
#include "Shape.h"
#include <ostream>

class Square : public Rectangle{

	private:
		static bool check(Point2D* vertices){
			return (Point2D::distance(vertices[0],vertices[1]) == 
				Point2D::distance(vertices[1],vertices[2]) ==
				Point2D::distance(vertices[2],vertices[3]) == 
				Point2D::distance(vertices[3],vertices[0])); 
		}
	
	public:
		Square();
		Square(std::string color, Point2D* vertices);
		void set_vertices(Point2D* vertices) override;
		friend std::ostream& operator<<(std::ostream &out,const Square &square);
		void print() override;
};

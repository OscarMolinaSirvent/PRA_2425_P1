#include <iostream>
#include <stdexcept>
#include "Point2D.h"
#include "Shape.h"
class Rectangle : public Shape{
	protected:
		Point2D* vs;
	private:
		static bool check(Point2D* vertices){
			double l1 = Point2D::distance(vertices[0],vertices[1]);
			double l2 = Point2D::distance(vertices[2],vertices[3]);
			double l3 = Point2D::distance(vertices[1],vertices[2]);
			double l4 = Point2D::distance(vertices[3],vertices[0]);
			return (l1 == l2 && l3 == l4);
		}
	public:
		static int const N_VERTICES = 4;
		Rectangle();
		Rectangle(const Rectangle &r);
		~Rectangle();
		Point2D get_vertex(int id)const;
		Point2D operator[](int ind) const;
		virtual void set_vertices(Point2D* vertices);
		Rectangle& operator=(const Rectangle &r);
		friend std::ostream& operator<<(std::ostream &out, const Rectangle &r);
		double area() const override;
		double perimeter() const override;
		void translate(double incX, double incY) override;
		void print();
};

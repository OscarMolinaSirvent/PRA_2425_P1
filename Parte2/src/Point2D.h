#ifndef POINT2D_H
#define POINT2D_H

#include <ostream>
#include <cmath>

class Point2D{
	public:
		double x,y;
		Point2D(double x=0, double y=0) : x{x}, y{y}{}
		static double distance(const Point2D &a, const Point2D &b){
			return (sqrt((pow(a.x,2) - pow(b.x,2) + 
				(pow(a.y,2) - pow(b.y,2)))));
		}

		friend bool operator==(const Point2D &a, const Point2D &b){
			return a.x == b.x && a.y == b.y;
		}	

		friend std::ostream& operator<<(std::ostream &out,const Point2D &p){
			out << "X = " << p.x << "Y = " << p.y << std::endl;
			return out;
		}


		friend bool operator!=(const Point2D &a, const Point2D &b){
			return a.x != b.x && a.y != b.y;
		}
};

#endif

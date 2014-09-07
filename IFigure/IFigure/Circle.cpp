#include "Circle.h"

//#define M_PI 3.1415926535897932384626433832795

Circle::Circle(const Point& p, double rad) : first(p), radius(rad)
{	
}

double Circle::square() const
{
	return M_PI*pow(radius,2.0);
}

double Circle::perimeter() const
{
	return 2*M_PI*radius;
}

double Circle::distTo (const Point& p) const
{
	double dist = sqrt (pow(first.getX() - p.getX(), 2.0) + pow(first.getY() - p.getY(), 2.0));
	if (dist <= radius)
		return 0;
	return dist - radius;
}
#include "Point.h"
#include <sstream>

using namespace std;


Point::Point (int abscissa, int ordinate)
{
	x = abscissa;
	y = ordinate;
}

bool Point::operator== (const Point& dot) const
{
	if (x == dot.x && y == dot.y)
		return true;
	return false;
}

bool Point::operator!= (const Point& dot) const
{
	return !(*this == dot);
}

bool Point::operator< (const Point& dot) const
{
	if (y < dot.y)
		return true;
	else
		if (y == dot.y)
			if (x < dot.x)
				return true;
	return false;
}

bool Point::operator> (const Point& dot) const
{
	if (y > dot.y)
		return true;
	else
		if (y == dot.y)
			if (x > dot.x)
				return true;
	return false;
}

bool Point::operator<= (const Point& dot) const
{
	if (*this < dot || *this == dot)
		return true;
	return false;
}

bool Point::operator>= (const Point& dot) const
{
	if (*this > dot || *this == dot)
		return true;
	return false;
}

int Point::getX() const
{
	return x;
}

int Point::getY() const
{
	return y;
}

string Point::toString() const
{
	stringstream ss;
	ss << "X = " << x << " and Y = " << y;
	return ss.str();
}

void Point::printPoint() const
{
	cout << toString() << endl;
}

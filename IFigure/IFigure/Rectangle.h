#pragma once

#include "IFigure.h"

class Rectangle : public Figure
{
private:
	double side (const Point* point1, const Point* point2) const;
	double dist (const Point* point1, const Point* point2, const Point& dot) const;
	Point vertical (const Point* point1, const Point* point2, const Point* dot) const;
	bool isPointOutRectangle (const Point& p) const;
public:
	Rectangle (const Point& p1, const Point& p2);
	double square () const;		
	double perimeter () const;
	double distTo (const Point& p) const;
private:	
	const Point first;
	const Point second;
	const Point third;
	const Point fourth;
};
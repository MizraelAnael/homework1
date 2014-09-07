#pragma once

#include "IFigure.h"

class Tringle : public Figure
{
private:
	double side (const Point* point1, const Point* point2) const;
	double dist (const Point* point1, const Point* point2, const Point& dot) const;
	Point vertical (const Point* point1, const Point* point2, const Point* dot) const;
	bool isPointOutTringle (const Point& p) const;
public:
	Tringle(const Point& p1, const Point& p2, const Point& p3);	
	double square () const;	
	double perimeter () const;
	double distTo (const Point& p) const;
private:
	const Point first;
	const Point second;
	const Point third;
};
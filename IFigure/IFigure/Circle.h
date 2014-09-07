#pragma once

#include "IFigure.h"

class Circle : public Figure
{
public:
	Circle(const Point& p, double rad);
	double square () const;
	double perimeter () const;	
	double distTo (const Point& p) const;
private:
	const Point first;
	const double radius;
};
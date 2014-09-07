#pragma once
//#define _USE_MATH_DEFINES
#include "Point.h"

#include <cmath>

class Figure
{
public:
	virtual double square () const = 0;
	virtual double perimeter () const = 0;	
};

double distTo (const Figure& f, const Point& p);
double sq(const Figure& f);
double per(const Figure& f);
double sqByPtr(const Figure* f);
double perByPtr(const Figure* f);

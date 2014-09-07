#include "Tringle.h"

Tringle::Tringle(const Point& p1, const Point& p2, const Point& p3) : first(p1), second(p2), third(p3)
{	
}

double Tringle::square() const
{
	double sqr = 1/2.0 * abs ((first.getX() - third.getX())*(second.getY() - third.getY()) - (second.getX() - third.getX())*(first.getY() - third.getY()));
	return sqr;
}

double Tringle::side (const Point* point1, const Point* point2) const
{
	return  sqrt (pow(point1->getX() - point2->getX(), 2.0) + pow(point1->getY() - point2->getY(), 2.0));
}

double Tringle::perimeter() const
{
	return side (&first, &second) + side (&second, &third) + side (&third, &first);
}

Point Tringle::vertical (const Point* point1, const Point* point2, const Point* dot) const
{
	if (point1->getX() == point2->getX())
		return Point (point1->getX(), dot->getY());
	else
		if (point1->getY() == point2->getY())
			return Point (dot->getX(), point1->getY());
		else
		{
			int x = (point1->getX() * pow(point2->getY() - point1->getY(), 2.0) + dot->getX() * pow(point2->getX() - point1->getX(), 2.0)) + (point2->getX() - point1->getX()) * (point2->getY() - point1->getY()) * (dot->getY() - point1->getY()) /
				(pow(point2->getY() - point1->getY(), 2.0) + pow(point2->getX() - point1->getX(), 2.0));
			int y = (point2->getX() - point1->getX()) * (dot->getX() - x) / (point2->getY() - point1->getY()) + dot->getY();
			return Point (x, y);
		}
}

double Tringle::dist (const Point* point1, const Point* point2, const Point& dot) const
{
	double distTemp = abs(((point1->getX() - point2->getX())*dot.getX() + (point1->getY() - point2->getY())*dot.getY() + point1->getX()*point2->getY() - point2->getX()*point1->getY())) /
			sqrt (pow(point2->getX() - point1->getX(), 2.0) + pow(point2->getY() - point1->getY(), 2.0));
	Point tempPoint = vertical (point1, point2, &dot);
	if (tempPoint.getX() >= point1->getX() && tempPoint.getX() <= point2->getX() && tempPoint.getY() >= point1->getY() && tempPoint.getY() <= point2->getY())
		return distTemp;
	double distTemp1 = side (point1, &dot);
	double distTemp2 = side (point2, &dot);
	return (distTemp1 < distTemp2 ? distTemp1 : distTemp2);
}

double Tringle::distTo (const Point& p) const
{
	if (this->isPointOutTringle(p))
	{
		double dist1 = dist(&first, &second, p);
		double dist2 = dist(&second, &third, p);
		double dist3 = dist(&third, &first, p);
		if (dist1 <= dist2)
			if (dist1 <= dist3)
				return dist1;
			else
				return dist3;
		else
			if (dist2 <= dist3)
				return dist2;
			else
				return dist3;
	}
	else return 0;
}

bool Tringle::isPointOutTringle (const Point& p) const
{
	Tringle temp1 (first, second, p);
	Tringle temp2 (second, third, p);
	Tringle temp3 (third, first, p);
	if (temp1.square() + temp2.square() + temp3.square() == this->square())
		return false;
	return true;
}
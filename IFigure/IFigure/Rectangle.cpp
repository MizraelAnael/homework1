#include "Rectangle.h"
#include "Tringle.h"

Rectangle::Rectangle (const Point& p1, const Point& p2) : first(p1), third(p2), second(p2.getX(), p1.getY()), fourth(p1.getX(), p2.getY())
{	
}

double Rectangle::side (const Point* point1, const Point* point2) const
{
	return  sqrt (pow(point1->getX() - point2->getX(), 2.0) + pow(point1->getY() - point2->getY(), 2.0));
}

double Rectangle::square() const
{
	return side (&first, &second) * side (&second, &third);
}

double Rectangle::perimeter() const
{
	return 2 * side (&first, &second) + 2 *side (&second, &third);
}

Point Rectangle::vertical (const Point* point1, const Point* point2, const Point* dot) const
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

bool Rectangle::isPointOutRectangle (const Point& p) const
{
	Tringle temp1 (first, second, p);
	Tringle temp2 (second, third, p);
	Tringle temp3 (third, fourth, p);
	Tringle temp4 (fourth, first, p);
	if (temp1.square() + temp2.square() + temp3.square() + temp4.square() == this->square())
		return false;
	return true;
}

double Rectangle::dist (const Point* point1, const Point* point2, const Point& dot) const
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

double Rectangle::distTo (const Point& p) const
{
	if (this->isPointOutRectangle(p))
	{
		double dist1 = dist(&first, &second, p);
		double dist2 = dist(&second, &third, p);
		double dist3 = dist(&third, &fourth, p);
		double dist4 = dist(&fourth, &first, p);
		dist1 = (dist1 < dist2 ? dist1 : dist2);
		dist3 = (dist3 < dist4 ? dist3 : dist4);
		return (dist1 < dist3 ? dist1 : dist3);
	}
	return 0;
}
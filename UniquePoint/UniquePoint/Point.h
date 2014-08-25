#pragma once

// Зачем здесь это включение?
#include <iostream>

class Point
{
public:
        Point(int abscissa, int ordinate);      
        //Point (const Point& dot) =  default;
        //Point operator= (const Point& dot) = default;
        std::string toString() const;
        void printPoint() const;
        bool operator == (const Point& dot) const;
        bool operator != (const Point& dot) const;
        bool operator < (const Point& dot) const;
        bool operator > (const Point& dot) const;
        bool operator <= (const Point& dot) const;
        bool operator >= (const Point& dot) const;
        int getX() const;
        int getY() const;
private:
        int x;
        int y;
};
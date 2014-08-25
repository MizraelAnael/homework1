#include "UniquePoint.h"

UniquePoint::UniquePoint (int abscissa, int ordinate)
{
        Uniq = new Point(abscissa, ordinate);
        flagForDestuctor = 0;
}

UniquePoint::~UniquePoint()
{
        if (flagForDestuctor == 0)
                delete Uniq;
}

Point* UniquePoint::get() const
{
        return Uniq;
}

Point* UniquePoint::release() const
{
        // На самом деле можно обойтись без флага. Просто нужно присвоить указателю nullptr. delete 0; - ок!
        // Но вернуть старый указатель.
        flagForDestuctor = 1; 
        return Uniq;
}

void UniquePoint::reset(int abscissa, int ordinate)
{
        delete Uniq;
        Uniq = new Point (abscissa, ordinate);
}

Point& UniquePoint::operator*() const
{
        return *Uniq;
}

Point* UniquePoint::operator->() const
{
        return Uniq;
}
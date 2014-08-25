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
        // �� ᠬ�� ���� ����� ������� ��� 䫠��. ���� �㦭� ��᢮��� 㪠��⥫� nullptr. delete 0; - ��!
        // �� ������ ���� 㪠��⥫�.
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
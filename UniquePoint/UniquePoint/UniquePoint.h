#include "Point.h"

class UniquePoint
{
private:
        UniquePoint operator= (const UniquePoint& UniqPtr);
        UniquePoint (const UniquePoint& UniqPtr);
public:
        UniquePoint (int abscissa, int ordinate);  // ����� ������ �ਭ����� 㪠��⥫�, ᮧ����� � ������� new:
                                                   // UniquePoint p(new Point(3,4));
        ~UniquePoint();
        void reset(int abscissa, int ordinate);    // � �� ᠬ��
        Point* get() const;
        Point* release() const;
        Point& operator*() const;
        Point* operator->() const;
private:
        Point *Uniq;
        int mutable flagForDestuctor;
};
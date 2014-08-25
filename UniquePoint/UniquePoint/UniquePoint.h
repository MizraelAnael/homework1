#include "Point.h"

class UniquePoint
{
private:
        UniquePoint operator= (const UniquePoint& UniqPtr);
        UniquePoint (const UniquePoint& UniqPtr);
public:
        UniquePoint (int abscissa, int ordinate);  // Класс должен принимать указатель, созданный с помощью new:
                                                   // UniquePoint p(new Point(3,4));
        ~UniquePoint();
        void reset(int abscissa, int ordinate);    // то же самое
        Point* get() const;
        Point* release() const;
        Point& operator*() const;
        Point* operator->() const;
private:
        Point *Uniq;
        int mutable flagForDestuctor;
};
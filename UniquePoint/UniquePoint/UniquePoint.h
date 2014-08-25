#include "Point.h"

class UniquePoint
{
private:
	UniquePoint operator= (const UniquePoint& UniqPtr);
	UniquePoint (const UniquePoint& UniqPtr);
public:
	UniquePoint (int abscissa, int ordinate);	
	~UniquePoint();
	void reset(int abscissa, int ordinate);
	Point* get() const;
	Point* release() const;
	Point& operator*() const;
	Point* operator->() const;
private:
	Point *Uniq;
	int mutable flagForDestuctor;
};
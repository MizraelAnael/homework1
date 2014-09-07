#include "IFigure.h"
#include "Tringle.h"
#include "Rectangle.h"
#include "Circle.h"

double distTo (const Figure& f, const Point& p)
{
	try
	{
		const Tringle& trin = dynamic_cast<const Tringle&>(f);
		return trin.distTo(p);
	}
	catch (std::exception&)
	{
		try
		{
			const Rectangle& rect = dynamic_cast<const Rectangle&>(f);
			return rect.distTo(p);
		}
		catch (std::exception&)
		{
			try
			{
				const Circle& circ = dynamic_cast<const Circle&>(f);
				return circ.distTo(p);
			}
			catch (std::exception&)
			{
				throw std::runtime_error ("figure is not valid");
			}
		}
	}
}

double sq(const Figure& f)
{
	return f.square();
}

double per(const Figure& f)
{
	return f.perimeter();
}

double sqByPtr(const Figure* f)
{
	return f->square();
}

double perByPtr(const Figure* f)
{
	return f->perimeter();
}
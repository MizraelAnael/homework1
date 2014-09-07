#include "stdafx.h"
#include "IFigure.h"
#include "Tringle.h"
#include "Rectangle.h"
#include "Circle.h"

//#define M_PI 3.1415926535897932384626433832795

using namespace System;
using namespace System::Text;
using namespace System::Collections::Generic;
using namespace	Microsoft::VisualStudio::TestTools::UnitTesting;

namespace TestIFigure
{
	[TestClass]
	public ref class TestIFigure
	{
	public: 
		[TestMethod]
		void CreateTringle()
		{
			Tringle a (Point(1,1), Point(2,1), Point (2,0));			
		}

		[TestMethod]
		void PerimeterOfTringle()
		{
			Tringle a (Point(1,1), Point(2,1), Point (2,0));	
			Assert::AreEqual (1+1+sqrt(2.0), a.perimeter());
		}

		[TestMethod]
		void SquareOfTringle()
		{
			Tringle a (Point(1,1), Point(2,1), Point (2,0));	
			Assert::AreEqual (0.5, a.square());
		}

		[TestMethod]
		void DistanceFromTringleToPointWichOutOfFigure()
		{
			Tringle a (Point(1,1), Point(2,1), Point (2,0));	
			Assert::AreEqual (sqrt(2.0), a.distTo(Point(0,0)));
		}

		[TestMethod]
		void DistanceFromTringleToPointWichInFigure()
		{
			Tringle a (Point(0,3), Point(3,1), Point (1,0));
			Assert::AreEqual (0.0, a.distTo(Point(1,1)));
		}

		[TestMethod]
		void AllFunctionWithTringle()
		{
			Tringle a (Point(1,1), Point(2,1), Point (2,0));
			Assert::AreEqual (0.5, a.square());
			Assert::AreEqual (1+1+sqrt(2.0), a.perimeter());
			Assert::AreEqual (sqrt(2.0), a.distTo(Point(0,0)));
		}

		[TestMethod]
		void CreateRectangle()
		{
			Rectangle a (Point(1,0), Point(2,1));			
		}
		
		[TestMethod]
		void PerimeterOfRectangle()
		{
			Rectangle a (Point(1,0), Point(2,1));
			Assert::AreEqual (4.0, a.perimeter());
		}

		[TestMethod]
		void SquareOfRectangle()
		{
			Rectangle a (Point(1,0), Point(2,1));
			Assert::AreEqual (1.0, a.square());
		}

		[TestMethod]
		void DistanceFromRectangleToPointWichOutOfFigure()
		{
			Rectangle a (Point(1,0), Point(2,1));
			Assert::AreEqual (1.0, a.distTo(Point(0,0)));
		}

		[TestMethod]
		void DistanceFromRectangleToPointWichInFigure()
		{
			Rectangle a (Point(1,0), Point(3,2));
			Assert::AreEqual (0.0, a.distTo(Point(2,1)));
		}
		[TestMethod]
		void AllFunctionRectangle()
		{
			Rectangle a (Point(1,0), Point(2,1));
			Assert::AreEqual (1.0, a.square());
			Assert::AreEqual (4.0, a.perimeter());
			Assert::AreEqual (1.0, a.distTo(Point(0,0)));
		}

		[TestMethod]
		void CreateCircle()
		{
			Circle a (Point(1,1), 1.0);			
		}		

		[TestMethod]
		void PerimeterOfCircle()
		{
			Circle a (Point(1,1), 1.0);	
			Assert::AreEqual (2*M_PI, a.perimeter());
		}

		[TestMethod]
		void SquareOfCircle()
		{
			Circle a (Point(1,1), 1.0);	
			Assert::AreEqual (M_PI, a.square());
		}

		[TestMethod]
		void DistanceFromCircleToPointWichOutOfFigure()
		{
			Circle a (Point(1,1), 1.0);	
			Assert::AreEqual (1.0, a.distTo(Point(3, 1)));
		}

		[TestMethod]
		void DistanceFromCircleToPointWichInFigure()
		{
			Circle a (Point(1,1), 1.0);	
			Assert::AreEqual (0.0, a.distTo(Point(1, 0)));
		}

		[TestMethod]
		void AllFunctionCircle()
		{
			Circle a (Point(1,1), 1.0);
			Assert::AreEqual (M_PI, sq(a));
			Assert::AreEqual (2*M_PI, a.perimeter());
			Assert::AreEqual (1.0, a.distTo(Point(3, 1)));
		}		

		[TestMethod]
		void DistanceToFigureTringle()
		{
			Tringle a (Point(1,1), Point(2,1), Point (2,0));
			Assert::AreEqual (sqrt(2.0), distTo(a, Point(0,0)));
		}

		[TestMethod]
		void DistanceToFigureRectangle()
		{
			Rectangle a (Point(1,0), Point(2,1));
			Assert::AreEqual (1.0, distTo(a, Point(0,0)));
		}

		[TestMethod]
		void DistanceToFigureCircle()
		{
			Circle a (Point(1,1), 1.0);
			Assert::AreEqual (1.0, distTo(a, Point(3, 1)));
		}

		[TestMethod]
		void PerimeterOfFigureTringleByLink()
		{
			Tringle a (Point(1,1), Point(2,1), Point (2,0));	
			Assert::AreEqual (1+1+sqrt(2.0), per(a));
		}

		[TestMethod]
		void PerimeterOfFigureRectangleByLink()
		{
			Rectangle a (Point(1,0), Point(2,1));
			Assert::AreEqual (4.0, per(a));
		}

		[TestMethod]
		void PerimeterOfFigureCircleByLink()
		{
			Circle a (Point(1,1), 1.0);
			Assert::AreEqual (2*M_PI, per(a));
		}

		[TestMethod]
		void PerimeterOfFigureTringleByPtr()
		{
			Tringle a (Point(1,1), Point(2,1), Point (2,0));	
			Assert::AreEqual (1+1+sqrt(2.0), perByPtr(&a));
		}

		[TestMethod]
		void PerimeterOfFigureRectangleByPtr()
		{
			Rectangle a (Point(1,0), Point(2,1));
			Assert::AreEqual (4.0, perByPtr(&a));
		}

		[TestMethod]
		void PerimeterOfFigureCircleByPtr()
		{
			Circle a (Point(1,1), 1.0);
			Assert::AreEqual (2*M_PI, perByPtr(&a));
		}

		[TestMethod]
		void SquareOfFigureTringleByLink()
		{
			Tringle a (Point(1,1), Point(2,1), Point (2,0));	
			Assert::AreEqual (0.5, sq(a));
		}

		[TestMethod]
		void SquareOfFigureRectangleByLink()
		{
			Rectangle a (Point(1,0), Point(2,1));
			Assert::AreEqual (1.0, sq(a));
		}

		[TestMethod]
		void SquareOfFigureCircleByLink()
		{
			Circle a (Point(1,1), 1.0);	
			Assert::AreEqual (M_PI, sq(a));
		}

		[TestMethod]
		void SquareOfFigureTringleByPtr()
		{
			Tringle a (Point(1,1), Point(2,1), Point (2,0));	
			Assert::AreEqual (0.5, sqByPtr(&a));
		}

		[TestMethod]
		void SquareOfFigureRectangleByPtr()
		{
			Rectangle a (Point(1,0), Point(2,1));
			Assert::AreEqual (1.0, sqByPtr(&a));
		}

		[TestMethod]
		void SquareOfFigureCircleByPtr()
		{
			Circle a (Point(1,1), 1.0);	
			Assert::AreEqual (M_PI, sqByPtr(&a));
		}
	};
}

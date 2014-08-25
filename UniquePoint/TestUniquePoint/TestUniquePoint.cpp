#include "stdafx.h"
#include "Point.h"
#include "UniquePoint.h"
#include <string>

using namespace System;
using namespace System::Text;
using namespace System::Collections::Generic;
using namespace	Microsoft::VisualStudio::TestTools::UnitTesting;

namespace TestUniquePoint
{
	void doSomethingWithPtrByLink (const UniquePoint& p)
			{
				Assert::AreEqual (10, (*p).getX());
				Assert::AreEqual (15, p->getY());
			}

	/*void doSomethingWithPtrByValue (UniquePoint p)
			{
				Assert::AreEqual (10, (*p).getX());
				Assert::AreEqual (15, p->getY());
			}*/

	[TestClass]
	public ref class TestUniquePoint
	{
	public: 
		[TestMethod]
		void AddPoint()
		{
			Point d (1, 10);
		}

		[TestMethod]
		void AddFewPoints()
		{
			Point d1 (1, 10);
			Point d2 (-1, 5);
			Point d3 (4, 9);
			Point d4 (-8, 16);
		}

		[TestMethod]
		void InfoAboutPoint()
		{
			Point d (1, 10);
			Assert::IsTrue (std::string ("X = 1 and Y = 10") == d.toString());
		}

		[TestMethod]
		void GetValueX()
		{
			Point d (1, 10);
			Assert::AreEqual (1, d.getX());
		}

		[TestMethod]
		void GetValueY()
		{
			Point d (1, 10);
			Assert::AreEqual (10, d.getY());
		}

		[TestMethod]
		void GetCopyOfPoint()
		{
			Point d1 (1, 10);
			Point d2 (d1);
			Assert::AreEqual (1, d1.getX());
			Assert::AreEqual (10, d2.getY());
		}

		[TestMethod]
		void AlternativeGetCopyOfPoint()
		{
			Point d1 (1, 10);
			Point d2 = d1;
			Assert::AreEqual (1, d2.getX());
			Assert::AreEqual (10, d2.getY());
		}

		[TestMethod]
		void ConversionPoint()
		{
			Point d1 (1, 10);
			Point d2 (4, 5);
			d2 = d1;
			Assert::AreEqual (1, d2.getX());
			Assert::AreEqual (10, d2.getY());
		}

		[TestMethod]
		void OnePointMoreThanAnotherTrue()
		{
			Point d1 (1, 10);
			Point d2 (4, 5);
			Assert::IsTrue (d1 > d2);
			Point d3 (2, 10);
			Assert::IsTrue (d3 > d1);
		}

		[TestMethod]
		void OnePointMoreThanAnotherFalse()
		{
			Point d1 (1, 10);
			Point d2 (4, 15);
			Assert::IsFalse (d1 > d2);
			Point d3 (2, 10);
			Assert::IsFalse (d1 > d3);
		}

		[TestMethod]
		void OnePointLessThanAnotherTrue()
		{
			Point d1 (1, 10);
			Point d2 (4, 5);
			Assert::IsTrue (d2 < d1);
			Point d3 (2, 10);
			Assert::IsTrue (d1 < d3);
		}

		[TestMethod]
		void OnePointLessThanAnotherFalse()
		{
			Point d1 (1, 4);
			Point d2 (4, 5);
			Assert::IsFalse (d2 < d1);
			Point d3 (2, 10);
			Assert::IsFalse (d3 < d1);
		}

		[TestMethod]
		void OnePointEqualAnotherTrue()
		{
			Point d1 (1, 10);
			Point d2 (1, 10);
			Assert::IsTrue (d2 == d1);			
		}

		[TestMethod]
		void OnePointEqualAnotherFalse()
		{
			Point d1 (1, 10);
			Point d2 (4, 9);
			Assert::IsFalse (d2 == d1);			
		}

		[TestMethod]
		void OnePointNotEqualAnotherTrue()
		{
			Point d1 (1, 10);
			Point d2 (1, 0);
			Assert::IsTrue (d2 != d1);			
		}

		[TestMethod]
		void OnePointNotEqualAnotherFalse()
		{
			Point d1 (1, 10);
			Point d2 (1, 10);
			Assert::IsFalse (d2 != d1);			
		}

		[TestMethod]
		void OnePointEqualOrLessAnotherTrue()
		{
			Point d1 (1, 10);
			Point d2 (1, 10);
			Assert::IsTrue (d2 <= d1);	
			Point d3 (5, 8);
			Assert::IsTrue (d3 <= d1);	
		}

		[TestMethod]
		void OnePointEqualOrLessAnotherFalse()
		{
			Point d1 (1, 10);
			Point d2 (4, 9);
			Assert::IsFalse (d1 <= d2);
		}

		[TestMethod]
		void OnePointEqualOrMoreAnotherTrue()
		{
			Point d1 (1, 10);
			Point d2 (1, 10);
			Assert::IsTrue (d2 >= d1);	
			Point d3 (5, 8);
			Assert::IsTrue (d1 >= d3);	
		}

		[TestMethod]
		void OnePointEqualOrMoreAnotherFalse()
		{
			Point d1 (1, 10);
			Point d2 (4, 9);
			Assert::IsFalse (d2 >= d1);
		}

		[TestMethod]
		void CreatUniquePtr()
		{
			UniquePoint uniq (10, 15);
			Assert::AreEqual (10, (*uniq).getX());
			Assert::AreEqual (15, uniq->getY());
		}

		[TestMethod]
		void GetPtrFromUniquePtr()
		{
			UniquePoint uniq (10, 15);
			Point* ptr = uniq.get();
			Assert::AreEqual (10, (*ptr).getX());
			Assert::AreEqual (15, ptr->getY());
		}

		[TestMethod]
		void ReleaseUniquePtr()
		{
			UniquePoint uniq (10, 15);
			Point* ptr = uniq.release();
			Assert::AreEqual (10, (*ptr).getX());
			Assert::AreEqual (15, ptr->getY());
			delete ptr;
		}

		[TestMethod]
		void ResetUniquePtr()
		{
			UniquePoint uniq (10, 15);
			uniq.reset(-1, 12);
			Assert::AreEqual (-1, (*uniq).getX());
			Assert::AreEqual (12, uniq->getY());			
		}

		[TestMethod]
		void CessionUniquePtrInFunctionByLink()
		{
			UniquePoint uniq (10, 15);
			doSomethingWithPtrByLink (uniq);
		}

		/*[TestMethod]
		void CessionUniquePtrInFunctionByValue()
		{
			UniquePoint uniq (10, 15);
			doSomethingWithPtrByValue (uniq);
		}*/     //error

		[TestMethod]
		void CessionUniquePtrInFunctionUsingPtrAfterFunction()
		{
			UniquePoint uniq (10, 15);
			doSomethingWithPtrByLink (uniq);
			uniq.reset(-1, 12);
			Assert::AreEqual (-1, (*uniq).getX());
			Assert::AreEqual (12, uniq->getY());	
		}
	};
}

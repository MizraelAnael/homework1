#include "stdafx.h"
#include "DynamicArray.h"
#include <string>

using namespace std;

using namespace System;
using namespace System::Text;
using namespace System::Collections::Generic;
using namespace	Microsoft::VisualStudio::TestTools::UnitTesting;

namespace TestDynamicArray
{
	[TestClass]
	public ref class TestDynamicArray
	{
	public: 
		[TestMethod]
		void AddOneElement()
		{
			DynamicArray<int> d;
			d.push_back(2);
			DynamicArray<int>::iterator it;
			it = d.begin();			
			Assert::AreEqual (2, *it);			
		}

		[TestMethod]
		void AddFewElements()
		{
			DynamicArray<int> d;
			d.push_back(2);
			d.push_back(9);
			d.push_back(8);
			d.push_back(30);
			DynamicArray<int>::iterator it;
			it = d.begin();			
			Assert::AreEqual (2, *it);
			++it;
			Assert::AreEqual (9, *it);
			++it;
			Assert::AreEqual (8, *it);
			++it;
			Assert::AreEqual (30, *it);
			++it;
			Assert::IsTrue (d.end() == it);
		}

		[TestMethod]
		void ArrayIsEmpty()
		{
			DynamicArray<int> d;
			Assert::AreEqual (true, d.isEmpty());			
		}

		[TestMethod]
		void ArrayNotEmpty()
		{
			DynamicArray<int> d;
			d.push_back(2);
			d.push_back(9);
			Assert::AreEqual (false, d.isEmpty());			
		}

		[TestMethod]
		void DeleteOneElement()
		{
			DynamicArray<int> d;
			d.push_back(2);
			d.pop_back();
			Assert::AreEqual (0, d.size());			
		}

		[TestMethod]
		void DeleteElementInEmptyArray()
		{
			try
			{
				DynamicArray<int> d;
				d.pop_back();
			}
			catch (std::exception& err)
			{
				Assert::IsTrue (std::string ("Array is empty. You couldn't delete element") == err.what()); 
			}
		}

		[TestMethod]
		void DeleteFewElements()
		{
			DynamicArray<int> d;
			d.push_back(2);
			d.push_back(9);
			d.push_back(8);
			d.push_back(30);
			d.pop_back();
			d.pop_back();
			DynamicArray<int>::iterator it;
			it = d.begin();			
			Assert::AreEqual (2, *it);
			++it;
			Assert::AreEqual (9, *it);			
			Assert::AreEqual (2, d.size());	
			++it;
			Assert::IsTrue (d.end() == it);
		}

		[TestMethod]
		void DoNotUseSuchWayOfIncrementOfIterator()
		{
			DynamicArray<int> d;
			d.push_back(2);
			d.push_back(9);
			d.push_back(8);
			d.push_back(30);
			DynamicArray<int>::iterator it;
			it = d.begin();	
			++++++it;
			Assert::AreEqual (30, *it);
			it = d.begin();	
			it++++++;
			Assert::AreEqual (9, *it);
		}

		[TestMethod]
		void UseSuchWayOfIncrementOfIterator()
		{
			DynamicArray<int> d;
			d.push_back(2);
			d.push_back(9);
			d.push_back(8);
			d.push_back(30);
			DynamicArray<int>::iterator it;
			it = d.begin();	
			Assert::AreEqual (9, *(++it));
			Assert::AreEqual (9, *(it++));
			Assert::AreEqual (8, *it);
		}

		[TestMethod]
		void ParOfIterators_ItIsFreeFromEachOther()
		{
			DynamicArray<int> d;
			d.push_back(2);
			d.push_back(9);
			d.push_back(8);
			d.push_back(30);
			DynamicArray<int>::iterator i;
			DynamicArray<int>::iterator j;
			i = d.begin();
			++i;
			++i;
			j = i;
			Assert::AreEqual (8, *i);
			Assert::AreEqual (8, *j);	
			j++;
			Assert::AreEqual (8, *i);
			Assert::AreEqual (30, *j);
		}

		[TestMethod]
		void ConverstionOfIterators()
		{
			DynamicArray<int> d;
			d.push_back(2);
			d.push_back(9);
			d.push_back(8);
			d.push_back(30);
			DynamicArray<int>::iterator i;
			DynamicArray<int>::iterator j;
			i = d.begin();
			++i;
			++i;
			j = d.begin();
			++i = ++j;
			Assert::AreEqual (9, *i);
			Assert::AreEqual (9, *j);	
		}

		[TestMethod]
		void PlunkArrayByIterator()
		{
			DynamicArray<int> d;
			d.push_back(2);
			d.push_back(9);
			d.push_back(8);
			d.push_back(30);
			DynamicArray<int>::iterator i = d.begin();
			for (; i != d.end(); ++i)
			{}
			Assert::IsTrue (d.end() == i);
		}

		[TestMethod]
		void CompeerIteratorsWhenItsNotEqualeTrue()
		{
			DynamicArray<int> d;
			d.push_back(2);
			d.push_back(9);
			d.push_back(8);
			d.push_back(30);
			DynamicArray<int>::iterator i;
			DynamicArray<int>::iterator j;
			i = d.begin();
			++i;
			++i;
			Assert::IsTrue (j != i);			
		}

		[TestMethod]
		void CompeerIteratorsWhenItsNotEqualeFalse()
		{
			DynamicArray<int> d;
			d.push_back(2);
			d.push_back(9);
			d.push_back(8);
			d.push_back(30);
			DynamicArray<int>::iterator i;
			DynamicArray<int>::iterator j;
			i = d.begin();
			++i;
			++i;
			j=i;
			Assert::IsFalse (j != i);			
		}

		[TestMethod]
		void CompeerIteratorsWhenItsEqualeTrue()
		{
			DynamicArray<int> d;
			d.push_back(2);
			d.push_back(9);
			d.push_back(8);
			d.push_back(30);
			DynamicArray<int>::iterator i;
			DynamicArray<int>::iterator j;
			i = d.begin();
			++i;
			++i;
			j = i;
			Assert::IsTrue (j == i);			
		}

		[TestMethod]
		void CompeerIteratorsWhenItsEqualeFalse()
		{
			DynamicArray<int> d;
			d.push_back(2);
			d.push_back(9);
			d.push_back(8);
			d.push_back(30);
			DynamicArray<int>::iterator i;
			DynamicArray<int>::iterator j;
			i = d.begin();
			++i;
			++i;
			j = d.begin();
			Assert::IsFalse (j == i);			
		}

		[TestMethod]
		void ClearArrayWithoutElements()
		{
			DynamicArray<int> d;			
			d.clear();
			Assert::AreEqual (0, d.size());			
		}

		[TestMethod]
		void ClearArrayWithOneElement()
		{
			DynamicArray<int> d;
			d.push_back(2);			
			d.clear();
			Assert::AreEqual (0, d.size());			
		}

		[TestMethod]
		void ClearArrayWithFewElements()
		{
			DynamicArray<int> d;
			d.push_back(2);
			d.push_back(9);
			d.push_back(8);
			d.push_back(30);
			d.clear();
			Assert::AreEqual (0, d.size());			
		}

		[TestMethod]
		void SizeOfArrayWithotElements()
		{
			DynamicArray<int> d;			
			Assert::AreEqual (0, d.size());			
		}

		[TestMethod]
		void SizeOfArrayWithOneElement()
		{
			DynamicArray<int> d;	
			d.push_back(2);
			Assert::AreEqual (1, d.size());			
		}

		[TestMethod]
		void SizeOfArrayWithFewElements()
		{
			DynamicArray<int> d;
			d.push_back(2);
			d.push_back(9);
			d.push_back(8);
			d.push_back(30);
			Assert::AreEqual (4, d.size());			
		}

		[TestMethod]
		void GetValueOfLastElement()
		{
			DynamicArray<int> d;
			d.push_back(2);
			d.push_back(9);
			d.push_back(8);			
			Assert::AreEqual (8, d.get_back());			
		}

		[TestMethod]
		void GetValueOfLastElementFromEmptyArray()
		{
			try
			{
				DynamicArray<int> d;
				int b = d.get_back();
			}
			catch (std::exception& err)
			{
				Assert::IsTrue (std::string ("Array is empty. You couldn't take element") == err.what()); 
			}					
		}

		[TestMethod]
		void SeeEmptyArrayInString()
		{
			DynamicArray<int> d;					
			Assert::IsTrue (std::string ("Array is empty") == d.toString());
		}

		[TestMethod]
		void SeeArrayInString()
		{
			DynamicArray<int> d;	
			d.push_back(2);
			d.push_back(9);
			d.push_back(8);	
			Assert::IsTrue (std::string ("2 9 8 ") == d.toString());
		}


	};
}

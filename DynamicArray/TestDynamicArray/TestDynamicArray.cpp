#include "stdafx.h"
#include "DynamicArray.h"
#include <vector>

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
			DynamicArray d;
			d.push_back(2);
			DynamicArray::iterator it;
			it = d.begin();			
			Assert::AreEqual (2, *it);			
		}

		[TestMethod]
		void AddFewElements()
		{
			DynamicArray d;
			d.push_back(2);
			d.push_back(9);
			d.push_back(8);
			d.push_back(30);
			DynamicArray::iterator it;
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
			DynamicArray d;
			Assert::AreEqual (true, d.isEmpty());			
		}

		[TestMethod]
		void ArrayNotEmpty()
		{
			DynamicArray d;
			d.push_back(2);
			d.push_back(9);
			Assert::AreEqual (false, d.isEmpty());			
		}

		[TestMethod]
		void DeleteOneElement()
		{
			DynamicArray d;
			d.push_back(2);
			d.pop_back();
			Assert::AreEqual (0, d.size());			
		}

		[TestMethod]
		void DeleteElementInEmptyArray()
		{
			try
			{
				DynamicArray d;
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
			DynamicArray d;
			d.push_back(2);
			d.push_back(9);
			d.push_back(8);
			d.push_back(30);
			d.pop_back();
			d.pop_back();
			DynamicArray::iterator it;
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
			DynamicArray d;
			d.push_back(2);
			d.push_back(9);
			d.push_back(8);
			d.push_back(30);
			DynamicArray::iterator it;
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
			DynamicArray d;
			d.push_back(2);
			d.push_back(9);
			d.push_back(8);
			d.push_back(30);
			DynamicArray::iterator it;
			it = d.begin();	
			Assert::AreEqual (9, *(++it));
			Assert::AreEqual (9, *(it++));
			Assert::AreEqual (8, *it);
		}

		[TestMethod]
		void ParOfIterators_ItIsFreeFromEachOther()
		{
			DynamicArray d;
			d.push_back(2);
			d.push_back(9);
			d.push_back(8);
			d.push_back(30);
			DynamicArray::iterator i;
			DynamicArray::iterator j;
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
			DynamicArray d;
			d.push_back(2);
			d.push_back(9);
			d.push_back(8);
			d.push_back(30);
			DynamicArray::iterator i;
			DynamicArray::iterator j;
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
			DynamicArray d;
			d.push_back(2);
			d.push_back(9);
			d.push_back(8);
			d.push_back(30);
			DynamicArray::iterator i = d.begin();
			for (; i != d.end(); ++i)
			{}
			Assert::IsTrue (d.end() == i);
		}

		[TestMethod]
		void CompeerIteratorsWhenItsNotEqualeTrue()
		{
			DynamicArray d;
			d.push_back(2);
			d.push_back(9);
			d.push_back(8);
			d.push_back(30);
			DynamicArray::iterator i;
			DynamicArray::iterator j;
			i = d.begin();
			++i;
			++i;
			Assert::IsTrue (j != i);			
		}

		[TestMethod]
		void CompeerIteratorsWhenItsNotEqualeFalse()
		{
			DynamicArray d;
			d.push_back(2);
			d.push_back(9);
			d.push_back(8);
			d.push_back(30);
			DynamicArray::iterator i;
			DynamicArray::iterator j;
			i = d.begin();
			++i;
			++i;
			j=i;
			Assert::IsFalse (j != i);			
		}

		[TestMethod]
		void CompeerIteratorsWhenItsEqualeTrue()
		{
			DynamicArray d;
			d.push_back(2);
			d.push_back(9);
			d.push_back(8);
			d.push_back(30);
			DynamicArray::iterator i;
			DynamicArray::iterator j;
			i = d.begin();
			++i;
			++i;
			j = i;
			Assert::IsTrue (j == i);			
		}

		[TestMethod]
		void CompeerIteratorsWhenItsEqualeFalse()
		{
			DynamicArray d;
			d.push_back(2);
			d.push_back(9);
			d.push_back(8);
			d.push_back(30);
			DynamicArray::iterator i;
			DynamicArray::iterator j;
			i = d.begin();
			++i;
			++i;
			j = d.begin();
			Assert::IsFalse (j == i);			
		}

		[TestMethod]
		void ClearArrayWithoutElements()
		{
			DynamicArray d;			
			d.clear();
			Assert::AreEqual (0, d.size());			
		}

		[TestMethod]
		void ClearArrayWithOneElement()
		{
			DynamicArray d;
			d.push_back(2);			
			d.clear();
			Assert::AreEqual (0, d.size());			
		}

		[TestMethod]
		void ClearArrayWithFewElements()
		{
			DynamicArray d;
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
			DynamicArray d;			
			Assert::AreEqual (0, d.size());			
		}

		[TestMethod]
		void SizeOfArrayWithOneElement()
		{
			DynamicArray d;	
			d.push_back(2);
			Assert::AreEqual (1, d.size());			
		}

		[TestMethod]
		void SizeOfArrayWithFewElements()
		{
			DynamicArray d;
			d.push_back(2);
			d.push_back(9);
			d.push_back(8);
			d.push_back(30);
			Assert::AreEqual (4, d.size());			
		}

		[TestMethod]
		void GetValueOfLastElement()
		{
			DynamicArray d;
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
				DynamicArray d;
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
			DynamicArray d;					
			Assert::IsTrue (std::string ("Array is empty") == d.toString());
		}

		[TestMethod]
		void SeeArrayInString()
		{
			DynamicArray d;	
			d.push_back(2);
			d.push_back(9);
			d.push_back(8);	
			Assert::IsTrue (std::string ("2 9 8 ") == d.toString());
		}


	};
}

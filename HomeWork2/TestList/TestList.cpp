#include "stdafx.h"
#include "List.h"
#include <iostream>

using namespace System;
using namespace System::Text;
using namespace System::Collections::Generic;
using namespace Microsoft::VisualStudio::TestTools::UnitTesting;

namespace TestList
{
    [TestClass]
    public ref class TestList
    {
    public: 
            [TestMethod]
            void AddFirstElementEmptyList()
            {
                ListOfElement ListTest;
                ListTest.AddFirstElement(10);
                Assert::AreEqual (10, ListTest.GetFirstElement());
            }

            [TestMethod]
            void AddFirstElementNotEmptyList()
            {
                ListOfElement ListTest;
                ListTest.AddFirstElement(15);
                ListTest.AddFirstElement(10);
                Assert::AreEqual (10, ListTest.GetFirstElement());
            }

            [TestMethod]
            void AddLastElementEmptyList()
            {
                ListOfElement ListTest;
                ListTest.AddLastElement(12);
                Assert::AreEqual (12, ListTest.GetLastElement());
            }

            [TestMethod]
            void AddLastElementNotEmptyList()
            {
                ListOfElement ListTest;
                ListTest.AddFirstElement(15);
                ListTest.AddFirstElement(10);
                ListTest.AddLastElement(12);
                Assert::AreEqual (12, ListTest.GetLastElement());
            }

            [TestMethod]
            void CountElementInEmptyList()
            {
                ListOfElement ListTest;
                Assert::AreEqual (0, ListTest.GetCountElements ());
            }

            [TestMethod]
            void CountElementInListWithOneElement()
            {
                ListOfElement ListTest;
                ListTest.AddFirstElement(15);
                Assert::AreEqual (1, ListTest.GetCountElements ());
            }

            [TestMethod]
            void CountElementInListWithFewElements()
            {
                ListOfElement ListTest;
                ListTest.AddFirstElement(15);
                ListTest.AddFirstElement(10);
                ListTest.AddLastElement(12);
                Assert::AreEqual (3, ListTest.GetCountElements ());
            }

			[TestMethod]
            void deleteFirstElementInListWithOneElement()
            {
                ListOfElement ListTest;
                ListTest.AddFirstElement (10);
				ListTest.removeFirstElement ();
                Assert::AreEqual (NULL, ListTest.GetFirstElement());
            }

            [TestMethod]
            void deleteFirstElementInListWithFewElements()
            {
                ListOfElement ListTest;
                ListTest.AddFirstElement(15);
                ListTest.AddFirstElement(10);
				ListTest.removeFirstElement ();
                Assert::AreEqual (15, ListTest.GetFirstElement());
            }

			[TestMethod]
            void deleteLastElementInListWithOneElement()
            {
                ListOfElement ListTest;
                ListTest.AddFirstElement (10);
				ListTest.removeLastElement ();
                Assert::AreEqual (NULL, ListTest.GetFirstElement());
            }

            [TestMethod]
            void deleteLastElementInListWithFewElements()
            {
                ListOfElement ListTest;
                ListTest.AddFirstElement(15);
                ListTest.AddFirstElement(10);
				ListTest.removeLastElement ();
                Assert::AreEqual (10, ListTest.GetFirstElement());
            }

			[TestMethod]
            void AddLastAndFirstElement()
            {
                ListOfElement ListTest;
				ListTest.AddLastElement(10);
                ListTest.AddFirstElement(15);                			
                Assert::AreEqual (15, ListTest.GetFirstElement());
				Assert::AreEqual (10, ListTest.GetLastElement());
            }

			[TestMethod]
            void AddManyElements()
            {
                ListOfElement ListTest;
                ListTest.AddFirstElement(15);
                ListTest.AddLastElement(10);
				ListTest.AddFirstElement(1);
                ListTest.AddLastElement(13);
				ListTest.AddFirstElement(5);
                ListTest.AddLastElement(19);
				ListTest.AddFirstElement(25);
                ListTest.AddLastElement(11);
				ListTest.AddFirstElement(35);
                ListTest.AddLastElement(74);
				ListTest.AddFirstElement(9);
                ListTest.AddLastElement(17);
				ListTest.AddFirstElement(16);
                ListTest.AddLastElement(14);
				ListTest.AddFirstElement(0);
                ListTest.AddLastElement(101);
				ListTest.AddFirstElement(153);
                ListTest.AddLastElement(105);
                Assert::AreEqual (153, ListTest.GetFirstElement());
				Assert::AreEqual (105, ListTest.GetLastElement());
            }

			[TestMethod]
            void AddFirstAndLastElement()
            {
                ListOfElement ListTest;				
                ListTest.AddFirstElement(15);
				ListTest.AddLastElement(10);
                Assert::AreEqual (15, ListTest.GetFirstElement());
				Assert::AreEqual (10, ListTest.GetLastElement());
            }

			[TestMethod]
            void AddAfterDeleteElement()
            {
                ListOfElement ListTest;
                ListTest.AddFirstElement (10);
				ListTest.removeLastElement ();
				ListTest.AddFirstElement(14);
				ListTest.AddLastElement(11);
                Assert::AreEqual (14, ListTest.GetFirstElement());
				Assert::AreEqual (11, ListTest.GetLastElement());
            }

    };
}

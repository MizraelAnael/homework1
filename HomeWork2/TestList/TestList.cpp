#include "stdafx.h"
#include "List.h"
#include <iostream>

// ToDo:
// 1. У тебя не все файлы залиты в хранилище. В частности, у меня при попытке компиляции вылезает:
//    RC : fatal error RC1110: could not open app.rc
// 

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
                        ListTest.EnterElement (14, 1);
                        ListTest.EnterElement (1, 2);
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
                        ListTest.EnterElement (14, 1);
                        ListTest.EnterElement (1, 2);
                        ListTest.AddLastElement(12);
                        Assert::AreEqual (12, ListTest.GetLastElement());
                }

                [TestMethod]
                void RemoveElementFromListWithOneElement()
                {
                        ListOfElement ListTest;
                        ListTest.EnterElement (14, 1);
                        ListTest.Remove(1);
                        Assert::AreEqual (0, ListTest.CountListElements);
                }

                [TestMethod]
                void RemoveElementFromListWithFewElements()
                {
                        ListOfElement ListTest;
                        ListTest.EnterElement (14, 1);
                        ListTest.EnterElement (1, 2);
                        ListTest.EnterElement (4, 3);
                        ListTest.EnterElement (5, 4);
                        ListTest.Remove(2);
                        Assert::AreEqual (4, ListTest.GetAmountElement(2)) ;
                }

                [TestMethod]
                void AddElementInEmptyList()
                {
                        ListOfElement ListTest;
                        ListTest.EnterElement(11, 1);
                        Assert::AreEqual (11, ListTest.GetAmountElement(1));
                }

                [TestMethod]
                void AddElementInNotEmptyList()
                {
                        ListOfElement ListTest;
                        ListTest.EnterElement(4, 1);
                        ListTest.EnterElement(3, 2);
                        ListTest.EnterElement(2, 3);
                        ListTest.EnterElement(1, 4);
                        Assert::AreEqual (3, ListTest.GetAmountElement(2));
                        Assert::AreEqual (4, ListTest.GetAmountElement(1));
                        Assert::AreEqual (2, ListTest.GetAmountElement(3));
                        Assert::AreEqual (1, ListTest.GetAmountElement(4));
                }

                [TestMethod]
                void CountElementInEmptyList()
                {
                        ListOfElement ListTest;
                        Assert::AreEqual (0, ListTest.CountListElements);
                }

                [TestMethod]
                void CountElementInListWithOneElement()
                {
                        ListOfElement ListTest;
                        ListTest.EnterElement(4, 1);
                        Assert::AreEqual (1, ListTest.CountListElements);
                }

                [TestMethod]
                void CountElementInListWithFewElements()
                {
                        ListOfElement ListTest;
                        ListTest.EnterElement(4, 1);
                        ListTest.EnterElement(3, 2);
                        ListTest.EnterElement(2, 3);
                        ListTest.EnterElement(1, 4);
                        Assert::AreEqual (4, ListTest.CountListElements);
                }
        };
}

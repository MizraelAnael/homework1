#include "stdafx.h"
#include "Task 1.h"
#include <limits>

using namespace System;
using namespace System::Text;
using namespace System::Collections::Generic;
using namespace Microsoft::VisualStudio::TestTools::UnitTesting;

namespace HomeworkTest
{
        [TestClass]
        public ref class Task1Test
        {
        public: 
                [TestMethod]
                void PositivAndPositive()
                {
                        Assert::AreEqual (5, sum (2, 3) );
                }

                [TestMethod]
                void NegativeAndPositive()
                {
                        Assert::AreEqual ( 0, sum (-3, 3) );
                }

                [TestMethod]
                void NegativeAndNegative()
                {
                        Assert::AreEqual ( -10, sum (-4, -6) );
                }

                [TestMethod]
                void DoubleZero()
                {
                        Assert::AreEqual ( 0, sum (0, 0) );
                }

                [TestMethod]
                void ZeroAndPositive()
                {
                        Assert::AreEqual ( 7, sum (7, 0) );
                }

                [TestMethod]
                void OverMax()
                {
                        int maxint = std::numeric_limits<int>::max();
                        int minint = std::numeric_limits<int>::min();
                        Assert::AreEqual ( minint, sum( maxint, 1) );
                }
        };
}

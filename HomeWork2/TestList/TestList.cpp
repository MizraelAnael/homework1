#include "stdafx.h"
#include "List.h"
#include <iostream>

using namespace System;
using namespace System::Text;
using namespace System::Collections::Generic;
using namespace	Microsoft::VisualStudio::TestTools::UnitTesting;

namespace TestList
{
	[TestClass]
	public ref class TestList
	{
	public: 
		[TestMethod]
		void TestAddFirstElement()
		{
			List ListTest;
			ListTest.AddFirstElement(10);
			Assert::AreEqual (10, ListTest.GetFirstElement());
		}
	};
}

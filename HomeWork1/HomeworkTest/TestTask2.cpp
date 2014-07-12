#include "stdafx.h"
#include "Task 2.h"

using namespace System;
using namespace System::Text;
using namespace System::Collections::Generic;
using namespace	Microsoft::VisualStudio::TestTools::UnitTesting;

namespace HomeworkTest
{
	[TestClass]
	public ref class TestTask2
	{
	public: 
		[TestMethod]
		void TwoZeroCount()
		{
			int arr[] = {0, 20, 15, 6, 0, 10, 36, 89, 90, 45, 7};
			Assert::AreEqual ( 2, shet_nul ( arr, sizeof(arr) / sizeof(arr[0]) ) );
		}

		[TestMethod]
		void AllZeroCount()
		{
			int arr[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
			Assert::AreEqual ( 11, shet_nul ( arr, sizeof(arr) / sizeof(arr[0]) ) );
		}

		[TestMethod]
		void NoZeroCount()
		{
			int arr[] = {1, 20, 15, 6, 4, 10, 36, 89, 90, 45, 7};
			Assert::AreEqual ( 0, shet_nul( arr, sizeof(arr) / sizeof(arr[0]) ) );
		}

		[TestMethod]
		void FewCloseZeroCount()
		{
			int arr[] = {0, 0, 0, 6, 4, 10, 36, 89, 90, 45, 7};
			Assert::AreEqual ( 3, shet_nul ( arr, sizeof(arr) / sizeof(arr[0]) ) );
		}

		[TestMethod]
		void ZeroInBeginAndEndCount()
		{
			int arr[] = {0, 20, 15, 6, 1, 10, 36, 89, 90, 45, 0};
			Assert::AreEqual ( 2, shet_nul ( arr, sizeof(arr) / sizeof(arr[0]) ) );
		}
	};
}

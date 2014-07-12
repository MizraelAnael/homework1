#include "stdafx.h"
#include "Task 3.h"
#include <iostream>

using namespace System;
using namespace System::Text;
using namespace System::Collections::Generic;
using namespace Microsoft::VisualStudio::TestTools::UnitTesting;

namespace HomeworkTest
{
	[TestClass]
	public ref class Testtask3
    {
    public: 
		[TestMethod]
        void CountFewWords()
		{
			char str1[] = "Предложение для проверки тестом";
            Assert::AreEqual ( 4, getWordCount (str1) );
        }

        [TestMethod]
        void CountOneWord()
		{
			char test_str[] = "Предложение";
            Assert::AreEqual ( 1, getWordCount ( test_str) );
        }

        [TestMethod]
        void CountZeroWordsWithSpase()
        {
            char test_str[] = " ";
            Assert::AreEqual ( 0, getWordCount ( test_str) );
        }

        [TestMethod]
        void CountZeroWordsWithoutSpase()
        {
            char test_str[] = "";
            Assert::AreEqual ( 0, getWordCount ( test_str) );
        }
                
        [TestMethod]
        void CountWordsWithSpaseInBegin()
        {
            char test_str[] = " Текст проверки";
            Assert::AreEqual ( 2, getWordCount ( test_str) );
        }

        [TestMethod]
		void CountWordsWithSpaseInEnd()
        {
            char test_str[] = "Текст проверки ";
            Assert::AreEqual ( 2, getWordCount ( test_str) );
        }

        [TestMethod]
        void CountWordsWithSpaseEverywhere()
		{
            char test_str[] = " Текст проверки ";
            Assert::AreEqual ( 2, getWordCount ( test_str) );
        }

		[TestMethod]
        void CountWordsWithDoubleSpaseEverywhere()
        {
            char test_str[] = "  Текст  проверки  ";
            Assert::AreEqual ( 2, getWordCount ( test_str) );
        }
		
		[TestMethod]
        void CountWordsWithDoubleSpaseInBegin()
        {
            char test_str[] = "  Текст проверки ";
            Assert::AreEqual ( 2, getWordCount ( test_str) );
        }
		
		[TestMethod]
        void CountWordsWithDoubleSpaseInEnd()
        {
            char test_str[] = "Текст проверки  ";
            Assert::AreEqual ( 2, getWordCount ( test_str) );
        }
		
		[TestMethod]
        void CountWordsWithDoubleSpaseInMiddle()
        {
            char test_str[] = "Текст  проверки ";
            Assert::AreEqual ( 2, getWordCount ( test_str) );
        }
		
		[TestMethod]
        void CountWordsWithThreeSpases()
        {
            char test_str[] = "Текст   проверки ";
            Assert::AreEqual ( 2, getWordCount ( test_str) );
		}
	};
}

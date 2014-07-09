#include "stdafx.h"
#include "Task 3.h"
#include <iostream>

// В целом тесты написаны правильно.

// Давай теперь улучшим нашу программу:
// Скроем детали реализации функции getWordCount в файле Task 3.cpp.
// Под деталями реализации я понимаю функции, которые она вызывает внутри себя:
// getSpaceCount
// getDoubleSpace
// deleteDoubleSpaces
// Их нужно удалить из заголовочного файла.
// В файле Task 3.cpp они останутся и будут доступны только в нем. Соответсвенно тестировать их НЕ НУЖНО!

// Добавь тесты на все возможные случаи (в частности с подряд идущими пробелами).
// После того как ты зафиксируешь работу функции getWordCount тестами, ты можешь не боясь исправлять детали ее реализации.
// Попробуй провести рефакторинг кода функции getWordCount и всех, которые она вызывает.
// Сейчас код написан неплохо, но его можно улучшить.

// Общие замечания:
// 1. Поправь везде форматирование.
// 2. Переименуй проект "Домашнее задание 1" в HomeWork1
// 3. Твой проект все еще не компилируется на моей машине. Исправь пути к файлам.
// 4. Удали из хранилища ненужные файлы и добавь нужные.

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
                void CountFewSpases()
                {
                        char test_str[] = "Предложение для проверки тестом";
                        Assert::AreEqual(3, getSpaceCount ( test_str, sizeof(test_str) ));
                }

                [TestMethod]
                void CountOneSpase()
                {
                        char test_str[] = "Тест программы";
                        Assert::AreEqual(1, getSpaceCount ( test_str, sizeof(test_str) ));
                }

                [TestMethod]
                void CountSpasesInBegin()
                {
                        char test_str[] = " Предложение";
                        Assert::AreEqual(1, getSpaceCount ( test_str, sizeof(test_str) ));
                }

                [TestMethod]
                void CountSpasesInEnd()
                {
                        char test_str[] = "Предложение ";
                        Assert::AreEqual(1, getSpaceCount ( test_str, sizeof(test_str) ));
                }

                [TestMethod]
                void CountZeroSpase()
                {
                        char test_str[] = "Предложение";
                        Assert::AreEqual(0, getSpaceCount ( test_str, sizeof(test_str) ));
                }

                [TestMethod]
                void CountDoubleSpases()
                {
                        char test_str[] = "Тестовое  предложение";
                        Assert::AreEqual(2, getSpaceCount ( test_str, sizeof(test_str) ));
                }

                [TestMethod]
                void CountThreeleSpases()
                {
                        char test_str[] = "Тестовое   предложение";
                        Assert::AreEqual(3, getSpaceCount ( test_str, sizeof(test_str) ));
                }

                [TestMethod]
                void CountSpasesInEverywhere()
                {
                        char test_str[] = " Тестовое предложение ";
                        Assert::AreEqual(3, getSpaceCount ( test_str, sizeof(test_str) ));
                }

                [TestMethod]
                void CheckOneDoubleSpases()
                {
                        char test_str[] = " Тестовое  предложение ";
                        Assert::AreEqual ( true, getDoubleSpace (test_str) );
                }

                [TestMethod]
                void CheckZeroDoubleSpases()
                {
                        char test_str[] = " Тестовое предложение ";
                        Assert::AreEqual ( false, getDoubleSpace (test_str) );
                }

                [TestMethod]
                void CheckFewDoubleSpases()
                {
                        char test_str[] = " Тестовое  предложение  ";
                        Assert::AreEqual ( true, getDoubleSpace (test_str) );
                }

                [TestMethod]
                void CheckDoubleSpasesInBegin()
                {
                        char test_str[] = "  Тестовое предложение";
                        Assert::AreEqual ( true, getDoubleSpace (test_str) );
                }

                [TestMethod]
                void CheckDoubleSpasesInEnd()
                {
                        char test_str[] = "Тестовое предложение  ";
                        Assert::AreEqual ( true, getDoubleSpace (test_str) );
                }

                [TestMethod]
                void DeletOneDoubleSpase() //Тест непредсказуем, бывают необъяснимые сбои
                {
                        char test_str1[] = "Тестовый  пример";
                        char test_str2[] = "Тестовый пример";
                        char test_str3[200] = "\0";
                        deleteDoubleSpaces (test_str1, test_str3);
                        Assert::AreEqual ( 0, strncmp (test_str2, test_str3, strlen (test_str2)) );
                }

                [TestMethod]
                void DeletFewDoubleSpase() 
                {
                        char test_str1[] = "Тестовый  пример  для анализа";
                        char test_str2[] = "Тестовый пример для анализа";
                        char test_str3[200] = "\0";
                        deleteDoubleSpaces (test_str1, test_str3);
                        Assert::AreEqual ( 0, strncmp (test_str2, test_str3, strlen (test_str2)) );
                }

                [TestMethod]
                void DeletZeroDoubleSpase() 
                {
                        char test_str1[] = "Тестовый пример для анализа";
                        char test_str2[] = "Тестовый пример для анализа";
                        char test_str3[200] = "\0";
                        deleteDoubleSpaces (test_str1, test_str3);
                        Assert::AreEqual ( 0, strncmp (test_str2, test_str3, strlen (test_str2)) );
                }

                [TestMethod]
                void DeletDoubleSpaseInBegin() 
                {
                        char test_str1[] = "  Тестовый пример для анализа";
                        char test_str2[] = " Тестовый пример для анализа";
                        char test_str3[200] = "\0";
                        deleteDoubleSpaces (test_str1, test_str3);
                        Assert::AreEqual ( 0, strncmp (test_str2, test_str3, strlen (test_str2)) );
                }

                [TestMethod]
                void DeletDoubleSpaseInEnd() 
                {
                        char test_str1[] = "Тестовый пример для анализа  ";
                        char test_str2[] = "Тестовый пример для анализа ";
                        char test_str3[200] = "\0";
                        deleteDoubleSpaces (test_str1, test_str3);
                        Assert::AreEqual ( 0, strncmp (test_str2, test_str3, strlen (test_str2)) );
                }

                [TestMethod]
                void CountFewWords()
                {
                        char test_str[] = "Предложение для проверки тестом";
                        Assert::AreEqual(4, getWordCount ( test_str, getSpaceCount ( test_str, sizeof(test_str)), strlen(test_str)));
                }

                [TestMethod]
                void CountOneWord()
                {
                        char test_str[] = "Предложение";
                        Assert::AreEqual(1, getWordCount ( test_str, getSpaceCount ( test_str, sizeof(test_str)), strlen(test_str)));
                }

                [TestMethod]
                void CountZeroWordsWithSpase()
                {
                        char test_str[] = " ";
                        Assert::AreEqual(0, getWordCount ( test_str, getSpaceCount ( test_str, sizeof(test_str)), strlen(test_str)));
                }

                [TestMethod]
                void CountZeroWordsWithoutSpase()
                {
                        char test_str[] = "";
                        Assert::AreEqual(0, getWordCount ( test_str, getSpaceCount ( test_str, sizeof(test_str)), strlen(test_str)));
                }
                
                [TestMethod]
                void CountWordsWithSpaseInBegin()
                {
                        char test_str[] = " Текст проверки";
                        Assert::AreEqual(2, getWordCount ( test_str, getSpaceCount ( test_str, sizeof(test_str)), strlen(test_str)));
                }

                [TestMethod]
                void CountWordsWithSpaseInEnd()
                {
                        char test_str[] = "Текст проверки ";
                        Assert::AreEqual(2, getWordCount ( test_str, getSpaceCount ( test_str, sizeof(test_str)), strlen(test_str)));
                }

                [TestMethod]
                void CountWordsWithSpaseEverywhere()
                {
                        char test_str[] = " Текст проверки ";
                        Assert::AreEqual(2, getWordCount ( test_str, getSpaceCount ( test_str, sizeof(test_str)), strlen(test_str)));
                }
        };
}

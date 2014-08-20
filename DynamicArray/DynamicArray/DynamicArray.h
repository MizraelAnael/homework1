#pragma once

// Действительно ли эти включения нужны для компиляции данного заголовочного файла?
#include <string>
#include <sstream> 
#include <iostream> 

using namespace std; // Этого не должно быть в заголовочном файле.

// Константные методы нужно пометить с помощью const

class DynamicArray
{
private:
        void copyArray (DynamicArray& origin, const DynamicArray& temp);
public:
        DynamicArray(); 
        ~DynamicArray();        
        DynamicArray (const DynamicArray& rhs);
        DynamicArray operator= (const DynamicArray& rhs);
        void clear();
        int size();
        bool isEmpty();
        void push_back (int element);
        void pop_back();
        int get_back();
        string toString();
        void printArray();
        class iterator
        {
        public:
                // Данный конструктор можно сделать в виде двух:
                // iterator(int *iter_) : iter(iter_) {}
                // iterator() : iter(0) {}
                // Принципиально эта версия ничем не отличается, но мне больше нравится два разных конструктора.
                // Для справки: значение по умолчанию (которое указывается с помощью = 0 после аргумента) -
                // это пережиток языка С. В нем нельзя было перегружать функции, ну и конструкторы конечно :).
                // Тут кому как нравится - вопрос стиля программирования.
                iterator(int *iter_ = 0) : iter(iter_) {}               
                int& operator*();               
                int* operator->();              
                iterator& operator++();         
                iterator operator++(int);               
                bool operator ==(const iterator& temp);         
                bool operator != (const iterator& temp);                
        private:
                int *iter;
        };
        iterator begin();
        iterator end();
private:
        int *arr;
        int counter;
};

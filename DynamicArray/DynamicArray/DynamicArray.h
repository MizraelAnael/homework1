#pragma once

#include <iostream> 

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
        int size() const;
        bool isEmpty() const;
        void push_back (int element);
        void pop_back();
        int get_back() const;
        std::string toString() const;
        void printArray() const;
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
                int& operator*() const;               
                int* operator->() const;              
                iterator& operator++();         
                iterator operator++(int);               
                bool operator ==(const iterator& temp) const;         
                bool operator != (const iterator& temp) const;                
        private:
                int *iter;
        };
        iterator begin() const;
        iterator end() const;
private:
        int *arr;
        int counter;
};

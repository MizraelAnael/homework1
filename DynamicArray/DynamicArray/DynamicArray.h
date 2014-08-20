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
                // ����� ��������� ����� ᤥ���� � ���� ����:
                // iterator(int *iter_) : iter(iter_) {}
                // iterator() : iter(0) {}
                // �ਭ樯���쭮 �� ����� ��祬 �� �⫨砥���, �� ��� ����� �ࠢ���� ��� ࠧ��� ���������.
                // ��� �ࠢ��: ���祭�� �� 㬮�砭�� (���஥ 㪠�뢠���� � ������� = 0 ��᫥ ��㬥��) -
                // �� ��०�⮪ �몠 �. � ��� ����� �뫮 ��ॣ�㦠�� �㭪樨, �� � ���������� ����筮 :).
                // ��� ���� ��� �ࠢ���� - ����� �⨫� �ணࠬ��஢����.
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

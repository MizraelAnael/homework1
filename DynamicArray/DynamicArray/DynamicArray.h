#pragma once

// ����⢨⥫쭮 �� �� ����祭�� �㦭� ��� �������樨 ������� ��������筮�� 䠩��?
#include <string>
#include <sstream> 
#include <iostream> 

using namespace std; // �⮣� �� ������ ���� � ��������筮� 䠩��.

// ����⠭�� ��⮤� �㦭� ������� � ������� const

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
                // ����� ��������� ����� ᤥ���� � ���� ����:
                // iterator(int *iter_) : iter(iter_) {}
                // iterator() : iter(0) {}
                // �ਭ樯���쭮 �� ����� ��祬 �� �⫨砥���, �� ��� ����� �ࠢ���� ��� ࠧ��� ���������.
                // ��� �ࠢ��: ���祭�� �� 㬮�砭�� (���஥ 㪠�뢠���� � ������� = 0 ��᫥ ��㬥��) -
                // �� ��०�⮪ �몠 �. � ��� ����� �뫮 ��ॣ�㦠�� �㭪樨, �� � ���������� ����筮 :).
                // ��� ���� ��� �ࠢ���� - ����� �⨫� �ணࠬ��஢����.
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

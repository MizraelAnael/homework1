#pragma once

#include <string>
#include <sstream> 
#include <iostream>

using namespace std;


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

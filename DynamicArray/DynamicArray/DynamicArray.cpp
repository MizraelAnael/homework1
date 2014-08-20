#include "DynamicArray.h"

DynamicArray::DynamicArray()
{	
	arr = nullptr;
	counter = 0;
}

DynamicArray::~DynamicArray()
{	
	clear();
}

void DynamicArray::push_back (int element)
{
	int *arrTemp = new int[counter+1];
	for (int i = 0; i < counter; ++i)
		arrTemp[i] = arr[i];
	arrTemp[counter] = element;
	++counter;
	delete []arr;
	arr = arrTemp;
}

void DynamicArray::pop_back()
{
	if (!isEmpty())
	{
		counter--;
		int *arrTemp = new int[counter];		
		for (int i = 0; i < counter; ++i)
			arrTemp[i] = arr[i];		
		delete []arr;
		arr = arrTemp;
	}
	else
		throw std::runtime_error ("Array is empty. You couldn't delete element");	
}

int DynamicArray::get_back()
{
	if (counter > 0)
		return arr[counter - 1];
	else
		throw std::runtime_error ("Array is empty. You couldn't take element");
}

bool DynamicArray::isEmpty()
{
	if (counter == 0)
		return true;	 
	return false;
}

int DynamicArray::size()
{
	return counter;
}

void DynamicArray::clear()
{
	delete []arr;
	counter = 0;
}

string DynamicArray::toString()
{
	stringstream ss;
	if (counter == 0)
	{
		ss << "Array is empty";
		return ss.str();
	}
	else
	{
		for (int i = 0; i < counter; ++i)
			ss << arr[i] << " ";		
		return ss.str();
	}
}

void DynamicArray::printArray()
{
	cout << toString() << endl;
}

DynamicArray::iterator DynamicArray::begin()
{
	return arr;
}

DynamicArray::iterator DynamicArray::end()
{
	return arr+counter;
}

DynamicArray::DynamicArray (const DynamicArray& rhs)
{
	copyArray (*this, rhs);
}

DynamicArray DynamicArray::operator= (const DynamicArray& rhs)
{
	clear();
	copyArray (*this, rhs);
	return *this;
}

void DynamicArray::copyArray(DynamicArray& copy, const DynamicArray& origin)
{
	copy.arr = new int [origin.counter];
	copy.counter = 0;
	for (int i = 0; i < origin.counter; ++i)
		copy.push_back (origin.arr[i]);
}

int& DynamicArray::iterator::operator*()
{
	return *iter;
}

int* DynamicArray::iterator::operator->()
{
	return iter;
}

DynamicArray::iterator& DynamicArray::iterator::operator++()
{
	++iter;
	return *this;
}

DynamicArray::iterator DynamicArray::iterator::operator++(int)
{
	iterator temp = *this;
	++iter;
	return temp;
}

bool DynamicArray::iterator::operator ==(const iterator& temp)
{
	if (this->iter == temp.iter)
		return true;
	return false;
}

bool DynamicArray::iterator::operator != (const iterator& temp)
{
	return !(*this == temp);
}
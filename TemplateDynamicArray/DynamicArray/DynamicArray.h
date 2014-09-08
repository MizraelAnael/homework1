#pragma once

#include <iostream> 
#include <sstream> 

template <class T>
class DynamicArray
{
private:
        void copyArray (DynamicArray<int>& copy, const DynamicArray<int>& origin)
		{
			copy.arr = new int [origin.counter];
			copy.counter = 0;
			for (int i = 0; i < origin.counter; ++i)
				copy.push_back (origin.arr[i]);
		}

public:
        DynamicArray()
		{       
			arr = nullptr;
			counter = 0;
		}

        ~DynamicArray()
		{       
			clear();
		}

        DynamicArray (const DynamicArray& rhs)
		{
			copyArray (*this, rhs);
		}

        DynamicArray operator= (const DynamicArray& rhs)
		{
			clear();
			copyArray (*this, rhs);
			return *this;
		}

        void clear()
		{
			delete []arr;
			counter = 0;
		}

        int size() const
		{
			return counter;
		}

        bool isEmpty() const
		{
			if (counter == 0)
					return true;     
			return false;
		}

        void push_back (int element)
		{
			int *arrTemp = new int[counter+1];
			for (int i = 0; i < counter; ++i)
					arrTemp[i] = arr[i];
			arrTemp[counter] = element;
			++counter;
			delete []arr;
			arr = arrTemp;
		}

        void pop_back()
		{
			if (isEmpty())
				throw std::runtime_error ("Array is empty. You couldn't delete element");
			counter--;
			int *arrTemp = new int[counter];                
			for (int i = 0; i < counter; ++i)
					arrTemp[i] = arr[i];            
			delete []arr;
			arr = arrTemp;
		}

        int get_back() const
		{
			if (counter > 0)
					return arr[counter - 1];
			else
					throw std::runtime_error ("Array is empty. You couldn't take element");
		}

        std::string toString() const
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
        void printArray() const
		{
			cout << toString() << endl;
		}

        class iterator
        {
        public:
                iterator(int *iter_) : iter(iter_) {}
                iterator() : iter(0) {}                      
                int& operator*() const
				{
					return *iter;
				}

                int* operator->() const
				{
					return iter;
				}

                iterator& operator++()
				{
					++iter;
					return *this;
				}

                iterator operator++(int)
				{
					iterator temp = *this;
					++iter;
					return temp;
				}

                bool operator ==(const iterator& temp) const
				{
					if (this->iter == temp.iter)
							return true;
					return false;
				}

                bool operator != (const iterator& temp) const
				{
					return !(*this == temp);
				}

        private:
                int *iter;
        };

        iterator begin() const
		{
			return arr;
		}

        iterator end() const
		{
			return arr+counter;
		}

private:
        int *arr;
        int counter;
};

#pragma once
#include <iostream>


class ListOfElement
{
public:
	int CountListElements;
	
	ListOfElement()
	{
		CountListElements = 0;
		head = tail = NULL;		
	}
	~ListOfElement();
	int GetFirstElement ()
	{
		if (head == NULL)
		{
			return NULL;
		}
		else
		{
			return head->value;
		}
	}
	int GetLastElement ()
	{
		if (tail == NULL)
		{
			return NULL;
		}
		else
		{
			return tail->value;
		}
	}
	void AddFirstElement (int value);
	void AddLastElement (int value);
	void Remove (int value);
	void EnterElement (int value, int position);
	int GetAmountElement (int position);
	int GetCountElements ()
	{
		return CountListElements;
	}
	void GetInfoList ();

private:
	struct node
	{
		node* next;
		int value;

		node (int i, node* n = NULL)
		{
			value = i;
			next = n;
		}
	};
	node* head;
	node* tail;
	int position;
};

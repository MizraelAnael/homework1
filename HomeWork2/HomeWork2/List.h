#pragma once
#include <iostream>


class List
{
public:
	int CountListElements;
	
	List()
	{
		CountListElements = 0;
		head = tail = NULL;
	}
	~List();
	int GetFirstElement ()
	{
		return head->value;
	}
	int GetLastElement ()
	{
		return tail->value;
	}
	void AddFirstElement (int value);
	void AddLastElement (int value);
	void Remove (int value);
	void EnterElement (int value, int position);
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

#include <iostream>
#include "List.h"

List::~List()
{
	node* current = NULL;
	node* next = head;
	while (next)
	{
		current = next;
		next = next->next;
		delete current;
	}
}

void List::AddFirstElement (int value)
{
	node* NewElement = new node (value, head);
	if (!head)
	{
		tail = NewElement;
	}
	head = NewElement;
	CountListElements++;
}

void List::AddLastElement (int value)
{
	node* previous = NULL;
	node* current = head;
	while ( current != NULL )
	{
		previous = current;
		current = current->next;		
	}

	node* NewElement = new node (value, current);
	if (current == NULL)
	{
		tail = NewElement;
	}

	if (previous == NULL)
	{
		head = NewElement;
	}
	else
	{
		previous->next = NewElement;
	}
	CountListElements++;
}

void List::Remove (int position)
{
	node* previous = NULL;
	node* current = head;
	int i = 1;
	while (current != NULL && i < position)
	{
		previous = current;
		current = current->next;
		i++;
	}
		if (previous)
		{
			previous->next = current->next;
		}
		if (current == tail)
		{
			tail = previous;
		}
		delete current;
		CountListElements--;
}

void List::EnterElement (int value, int position)
{
	node* previous = NULL;
	node* current = head;
	int i = 1;
	while ( current != NULL && i < position)
	{
		previous = current;
		current = current->next;
		i++;
	}

	node* NewElement = new node (value, current);
	if (current == NULL)
	{
		tail = NewElement;
	}

	if (previous == NULL)
	{
		head = NewElement;
	}
	else
	{
		previous->next = NewElement;
	}
	CountListElements++;
}

int List::GetAmountElement (int position)
{
	node* previous = NULL;
	node* current = head;
	int i = 1;
	while ( current != NULL && i < position)
	{
		previous = current;
		current = current->next;
		i++;
	}
	return current->value;
}

void List::GetInfoList ()
{
	node* current = head;
	std::cout << "Элементы списка: " << std::endl;
	while (current)
	{
		std::cout << current->value << " ";
		current = current->next;
	}
	std::cout << std::endl;
}
#include <iostream>
#include "List.h"

ListOfElement::~ListOfElement()
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

void ListOfElement::AddFirstElement (int value)
{
	node* NewElement = new node (value, head);
	if (!head)
	{
		tail = NewElement;
	}
	head = NewElement;
	CountListElements++;
}

void ListOfElement::AddLastElement (int value)
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

void ListOfElement::Remove (int position)
{
	if (CountListElements == 1)
	{
		CountListElements = 0;
		head = tail = NULL;
	}
	else
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
		if (current == head)
		{
			head = head->next;
		}
		delete current;
		CountListElements--;
	}	
}

void ListOfElement::EnterElement (int value, int position)
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

int ListOfElement::GetAmountElement (int position)
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

void ListOfElement::GetInfoList ()
{
	if (CountListElements)
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
	else
	{
		std::cout << "Список пуст" << std::endl;
	}
}
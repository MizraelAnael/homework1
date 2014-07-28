#include "List.h"

ListOfElement::ListOfElement ()
    {
        CountListElements = 0;
        head = tail = NULL;             
    }

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

ListOfElement::node::node (int i, node* n)
{
        value = i;
        next = n;
}

int ListOfElement::GetFirstElement ()
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

int ListOfElement::GetLastElement ()
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

int ListOfElement::GetCountElements ()
    {
        return CountListElements;
    }

void ListOfElement::AddLastElement (int value)
{
    node* NewElement = new node (value, NULL);
    if (!head)
		head = NewElement;    
    else
		tail->next = NewElement;
	tail = NewElement;
    CountListElements++;
}

void ListOfElement::removeFirstElement ()
{
	node* current = head;
	if (current)
	{
		if (CountListElements == 1)
		{
			delete current;			
			head = tail = NULL;
		}
		else
		{
			head = current->next;
			delete current;
		}
		CountListElements--;
	}
	else
		std::cout << "Список пуст, нет элемента для удаления!" << std::endl;
}

void ListOfElement::removeLastElement ()
{
	node* previous = NULL;
	node* current = head;
	if (current)
	{
		if (CountListElements == 1)
		{
			delete current;			
			head = tail = NULL;
		}
		else
		{
			while (current != tail)
			{
				previous = current;
				current = current->next;
			}
			delete current;
			previous->next = NULL;
			tail = previous;
		}
		CountListElements--;
	}
	else
		std::cout << "Список пуст, нет элемента для удаления!" << std::endl;
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
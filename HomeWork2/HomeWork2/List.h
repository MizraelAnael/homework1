#pragma once
#include <iostream>

// ToDo:
// 1. Вынеси реализацию всех методов в файл реализации.
// 2. Убери методы:
//        void Remove (int value);
//        void EnterElement (int value, int position);
//        int GetAmountElement (int position); 
//    Их я делать не просил. Они нам не нужны.

class ListOfElement
{
public:
        int CountListElements; 
        // Почему это поле public? Лучше уж тогда сделай поле приватным, и создай метод для его получения. Иначе пользователь может из кода изменить это значение.
        // Убери этот счетчик. Для определения размера списка можно пройтись по всем элементам (см. метод GetListInfo)
        
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
        int position; // Это убрать. Можно добавлять только в конец или в начало.
};

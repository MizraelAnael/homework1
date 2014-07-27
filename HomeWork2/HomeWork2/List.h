#pragma once
#include <iostream>

class ListOfElement
{
public:
              
        ListOfElement();
        ~ListOfElement();
        int GetFirstElement ();         
        int GetLastElement ();              
        void AddFirstElement (int value);
        void AddLastElement (int value);
		void removeFirstElement ();
        void removeLastElement ();
        int GetCountElements ();        
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
		int CountListElements;      
};

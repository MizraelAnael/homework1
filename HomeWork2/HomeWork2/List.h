#pragma once
#include <iostream>

// ToDo:
// 1. �뭥� ॠ������ ��� ��⮤�� � 䠩� ॠ����樨.
// 2. ���� ��⮤�:
//        void Remove (int value);
//        void EnterElement (int value, int position);
//        int GetAmountElement (int position); 
//    �� � ������ �� ��ᨫ. ��� ��� �� �㦭�.

class ListOfElement
{
public:
        int CountListElements; 
        // ��祬� �� ���� public? ���� � ⮣�� ᤥ��� ���� �ਢ���, � ᮧ��� ��⮤ ��� ��� ����祭��. ���� ���짮��⥫� ����� �� ���� �������� �� ���祭��.
        // ���� ��� ���稪. ��� ��।������ ࠧ��� ᯨ᪠ ����� �ன��� �� �ᥬ ����⠬ (�. ��⮤ GetListInfo)
        
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
        int position; // �� ����. ����� ��������� ⮫쪮 � ����� ��� � ��砫�.
};

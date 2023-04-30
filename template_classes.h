#include <iostream>
#include <cstdlib>

using namespace std;

template <class Tdata>
class VectorQueue:
{
    private:
        int head, tail; // ������� ������ � ������
        int maxLength; // ������ �������
        Tdata * data; // ��������� �� ������ ������
    public:
        VectorQueue(int maxLength = 100;) // �����������
        {
            data = new Tdata[maxLength];
            head = 0;
            tail = head - 1;
        }

        ~VectorQueue() // ����������
        {
            delete[] data;
        }

        int isEmpty() // �������� �� �������
        {
            return (tail + 1) % maxLength == head;
        }

        int isFull() // �������� �������
        {
            return (tail + 2) % maxLength == head; 
        }

        Tdata getHead() // ������������� ������ �� ������ �������
        {
            return data[head];
        }

        int EnQueue(Tdata x) // �������� ������� � �������
        {
            if (isFull()) // ���� ������� ��������� 
                return 0;
            tail = (tail + 1) % maxLength; // ����������� ������ ���������� ��������
            data[tail] = x; // ��������� ������ � ������ �������
            return 1;
        }

        Tdata DeQueue() // ���������� �������� �� ������ �������
        {
            int temp = head;
            head = (head + 1) % maxLength;
                return data[temp];
        }
};

template <class Tdata>
class ListQueue:
{
    private:
        struct item
        {
            Tdata data;
            item * next;
        } *head, * tail; //������� ������ � ������
    public:
        ListQueue() // �����������
        {
            head = tail = NULL;
        }

        ~ListQueue() // ����������
        {
            item * temp = head;
            while(head)
            {
                temp = head;
                head = head->next;
                delete temp;
            }
        }

        int isEmpty() // �������� �� �������
        {
            return head == NULL;
        }

        int isFull() // �������� �������
        {   item * temp = new (nothrow) item; // nothrow - �������� �����������, ��� � ����������� �������, � �������, ������� ��� ��������, ������� �� ������� ����������.
            if(temp == NULL) return 1;
            delete temp;
            return 0; 
        }

        Tdata getHead() // ������������� ������ �� ������ �������
        {
            return head->data;
        }

        int EnQueue(Tdata x) // �������� ������� � �������
        {
            item * temp = new (nothrow) item;
            if(temp == NULL)
                return 0;
            temp->data = x;
            if(head == NULL)
                head = tail = temp;
            else
            {
                tail->next = temp;
                tail = tail->next
            }
            return 1;
        }

        Tdata DeQueue() // ���������� �������� �� ������ �������
        {
            Tdata temp = head->data;
            item * tmp = head;
            delete tmp;
            return temp;
        }
};
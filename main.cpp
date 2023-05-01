#include "template_classes.h"
#include <iostream>
#include <locale.h>

using namespace std;

template <class TQueue, class TData>
void add(TQueue &, TData &);

int main(void)
{
    setlocale(LC_ALL, "Rus");
    VectorQueue<double> d_vector_queue;
    VectorQueue<unsigned> u_vector_queue;
    ListQueue<double> d_list_queue;
    ListQueue<unsigned> u_list_queue; 
    
    int menu;
    unsigned utmp;
    double dtmp;

    do
    {
        system("cls");
        cout << "1. �������� �������" << endl;
        cout << "2. ������� �������" << endl;
        cout << "3. ������������� ������" << endl;
        cout << "4. �������� �� �������" << endl;
        cout << "5. �������� �������������" << endl;
        cout << "6. �����" << endl;
        cin >> menu;
        cin.get();
        switch (menu)
        {
            case 1:
                add(d_vector_queue, dtmp);
                add(u_vector_queue, utmp);
                add(d_list_queue, dtmp);
                add(u_list_queue, dtmp);                
                break;
            case 2:
                cout << "�������� �� dVQ: " << d_vector_queue.DeQueue() << endl;
                cout << "�������� �� uVQ: " << u_vector_queue.DeQueue() << endl;
                cout << "�������� �� dLQ: " << d_list_queue.DeQueue() << endl;
                cout << "�������� �� uLQ: " << u_list_queue.DeQueue() << endl;
                while(cin.get() != '\n');
                break;
            case 3:
                cout << "��������� �� dVQ: " << d_vector_queue.getHead() << endl;
                cout << "��������� �� uVQ: " << u_vector_queue.getHead() << endl;
                cout << "��������� �� dLQ: " << d_list_queue.getHead() << endl;
                cout << "��������� �� uLQ: " << u_list_queue.getHead() << endl;
                while(cin.get() != '\n');
                break;
            case 4:
                cout << "������� dVQ - " << (d_vector_queue.isEmpty()? "������" : " �� ������") << endl;
                cout << "������� uVQ - " << (u_vector_queue.isEmpty()? "������" : " �� ������") << endl;
                cout << "������� dLQ - " << (d_list_queue.isEmpty()? "������" : " �� ������") << endl;
                cout << "������� uLQ - " << (u_list_queue.isEmpty()? "������" : " �� ������") << endl;
                while(cin.get() != '\n');
                break;
            case 5:
                cout << "������� dVQ - " << (d_vector_queue.isFull()? "���������" : " �� ���������") << endl;
                cout << "������� uVQ - " << (u_vector_queue.isFull()? "���������" : " �� ���������") << endl;
                cout << "������� dLQ - " << (d_list_queue.isFull()? "���������" : " �� ���������") << endl;
                cout << "������� uLQ - " << (u_list_queue.isFull()? "���������" : " �� ���������") << endl;
                while(cin.get() != '\n');
                break;
        }
    }while(menu != 6);

    return 0;
}

template <class TQueue, class TData>
void add(TQueue &queue, TData &value)
{
    if(queue.isFull())
    {
        cout << "������� ���������" << endl;
        while(cin.get() != '\n');
        return;
    }
    input(value);
    queue.EnQueue(value);
    return;
}

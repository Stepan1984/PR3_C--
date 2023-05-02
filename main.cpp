#include "template_classes.h"
#include <iostream>
#include <locale.h>
#include <sstream>

using namespace std;

template <class TQueue, class TData>
void input(TQueue &queue, TData &value, bool );

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
                input(d_vector_queue, dtmp, 1);
                input(u_vector_queue, utmp, 0);
                input(d_list_queue, dtmp, 1);
                input(u_list_queue, dtmp, 0);                
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

//template<class T>
template <class TQueue, class TData>
void input(TQueue &queue, TData &value, bool data_type)
{
    if(queue.isFull())
    {
        cout << "������� ���������" << endl;
        while(cin.get() != '\n');
        return;
    }
    string input;
    char flag = 1;
    int i; 
    do
    {
        system("cls");
        cout << "������� " << (data_type? "double" : "unsigned int" ) << " : " << endl ;
        cin >> input; 
        cin.get();
        if(!data_type && input[0] == '-' || input[0] != '-' && !isdigit(input[0])  ||  !input.compare("-0") ) // ���� ������ ���� �� "-" � �� ����� ��� ��������� �������� "-0"  
        {
            cout << "������������ ��������, ��������� ������� ";
            flag = 0;
            while(cin.get() != '\n');
            continue;
        }
        
        i = 1;
        while(input[i] != '\0')
        {
            if(!isdigit(input[i]) && input[i] != '.') // ���� �� ����� � �� �����
            {
                cout << "������������ ��������, ��������� �������: ";
                flag = 0;
                while(cin.get() != '\n');
                break;
            }
            else
                flag = 1;
            i++;
        }
    }while(!flag); 

    stringstream ss(input);
    ss >> value;
    queue.EnQueue(value);
    return;
}

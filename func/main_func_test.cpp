#include "function_template.h"
#include "template_classes.h"
#include <iostream>
#include <sstream>
#include <locale.h>


using namespace std;

template <class TQueue, class TData>
void input(TQueue &queue, TData &value, bool );

int main(void)
{
    setlocale(LC_ALL, "Rus");
    ListQueue<double> d_queue;
    ListQueue<unsigned> u_queue;
    double dtmp;
    unsigned utmp;



    int menu;
    do
    {
        system("cls");
        cout << "����" << endl;
        cout << "1. �������� �������" << endl;
        cout << "2. ����� ������������ ��������" << endl;
        cout << "3. �����" << endl;
        cin >> menu;
        cin.get();

        switch(menu)
        {
            case 1:
                input(d_queue, dtmp, 1);
                input(u_queue, utmp, 0);
                break;
            case 2:
                if(d_queue.isEmpty())
                    cout << "������� dQ ������" << endl;
                else
                    cout << "�������� �������� � dQ: " <<  (find_odd_max(d_queue, dtmp)? to_string(dtmp) : "dboba") << endl;;
                if(u_queue.isEmpty())
                    cout << "������� uQ ������" << endl;
                else
                    cout << "�������� �������� � uQ: " << (find_odd_max(u_queue, utmp)? to_string(utmp) : "uboba") << endl;;
                while(cin.get() != '\n');
                break;
            case 4:
                cout << d_queue.getHead() << endl;
                cout << u_queue.getHead() << endl;
                while(cin.get() != '\n');
        }
    }while(menu != 3);

    return 0;
}

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

template<class T>
string to_string(T value)
{
    string stmp;
    stringstream ss;
    ss << value;
    ss >> stmp;
    return stmp;
}
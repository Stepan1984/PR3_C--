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
        cout << "Меню" << endl;
        cout << "1. Добавить элемент" << endl;
        cout << "2. Найти максимальный нечётный" << endl;
        cout << "3. Выход" << endl;
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
                    cout << "Очередь dQ пустая" << endl;
                else
                    cout << "Нечётный максимум в dQ: " <<  (find_odd_max(d_queue, dtmp)? to_string(dtmp) : "dboba") << endl;;
                if(u_queue.isEmpty())
                    cout << "Очередь uQ пустая" << endl;
                else
                    cout << "Нечётный максимум в uQ: " << (find_odd_max(u_queue, utmp)? to_string(utmp) : "uboba") << endl;;
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
        cout << "Очередь заполнена" << endl;
        while(cin.get() != '\n');
        return;
    }
    string input;
    char flag = 1;
    int i; 
    do
    {
        system("cls");
        cout << "Введите " << (data_type? "double" : "unsigned int" ) << " : " << endl ;
        cin >> input; 
        cin.get();
        if(!data_type && input[0] == '-' || input[0] != '-' && !isdigit(input[0])  ||  !input.compare("-0") ) // если первый знак не "-" и не цифра или сочитание символов "-0"  
        {
            cout << "Некорректное значение, повторите попытку ";
            flag = 0;
            while(cin.get() != '\n');
            continue;
        }
        
        i = 1;
        while(input[i] != '\0')
        {
            if(!isdigit(input[i]) && input[i] != '.') // если не цифра и не точка
            {
                cout << "Некорректное значение, повторите попытку: ";
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
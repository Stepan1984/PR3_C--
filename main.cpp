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
        cout << "1. Добавить элемент" << endl;
        cout << "2. Извлечь элемент" << endl;
        cout << "3. Неразрушающее чтение" << endl;
        cout << "4. Проверка на пустоту" << endl;
        cout << "5. Проверка заполненность" << endl;
        cout << "6. Выход" << endl;
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
                cout << "Извлекли из dVQ: " << d_vector_queue.DeQueue() << endl;
                cout << "Извлекли из uVQ: " << u_vector_queue.DeQueue() << endl;
                cout << "Извлекли из dLQ: " << d_list_queue.DeQueue() << endl;
                cout << "Извлекли из uLQ: " << u_list_queue.DeQueue() << endl;
                while(cin.get() != '\n');
                break;
            case 3:
                cout << "Прочитали из dVQ: " << d_vector_queue.getHead() << endl;
                cout << "Прочитали из uVQ: " << u_vector_queue.getHead() << endl;
                cout << "Прочитали из dLQ: " << d_list_queue.getHead() << endl;
                cout << "Прочитали из uLQ: " << u_list_queue.getHead() << endl;
                while(cin.get() != '\n');
                break;
            case 4:
                cout << "Очередь dVQ - " << (d_vector_queue.isEmpty()? "пустая" : " не пустая") << endl;
                cout << "Очередь uVQ - " << (u_vector_queue.isEmpty()? "пустая" : " не пустая") << endl;
                cout << "Очередь dLQ - " << (d_list_queue.isEmpty()? "пустая" : " не пустая") << endl;
                cout << "Очередь uLQ - " << (u_list_queue.isEmpty()? "пустая" : " не пустая") << endl;
                while(cin.get() != '\n');
                break;
            case 5:
                cout << "Очередь dVQ - " << (d_vector_queue.isFull()? "заполнена" : " не заполнена") << endl;
                cout << "Очередь uVQ - " << (u_vector_queue.isFull()? "заполнена" : " не заполнена") << endl;
                cout << "Очередь dLQ - " << (d_list_queue.isFull()? "заполнена" : " не заполнена") << endl;
                cout << "Очередь uLQ - " << (u_list_queue.isFull()? "заполнена" : " не заполнена") << endl;
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
        cout << "Очередь заполнена" << endl;
        while(cin.get() != '\n');
        return;
    }
    input(value);
    queue.EnQueue(value);
    return;
}

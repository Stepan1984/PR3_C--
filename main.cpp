#include "function_template.h"
#include "template_classes.h"
#include <iostream>

using namespace std;

int main(void)
{
    char queue_type, data_type;
    do
    {
        cout << "Ввыберите тип данных" << endl;
        cout << "1. Double" << endl;
        cout << "2. Unsigned int" << endl;
        cout << "3. Выход" << endl;
        cin >> data_type;
        cin.get();
    }while(data_type < 1 || data_type > 3);
    if(data_type == 3)
    {
        system("cls");
        return 0;
    }

    do
    {
        cout << "Ввыберите способ реализации очереди" << endl;
        cout << "1. Массив" << endl;
        cout << "2. Список" << endl;
        cout << "3. Выход" << endl;
        cin >> queue_type;
        cin.get();
    }while(queue_type < 1 || queue_type > 3);
    if(queue_type == 3)
    {
        system("cls");
        return 0;
    }
    if(data_type == 1)
    {
        
    }
    if(queue_type == 1)

    return 0;
}
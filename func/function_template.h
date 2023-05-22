//#include <cmath>
#include <sstream>

using namespace std;

template <class TData, class TQueue>
int find_odd_max(TQueue queue, TData &max)
{
    bool k = false; // флаг наличия нечётного числа в очереди
    stringstream ss;
    TData Ttmp;
    string stmp;
    char ctmp;
    int i, lenght;
    while(!queue.isEmpty()) // пока очередь не пуста
    {
        Ttmp = queue.DeQueue(); // достаём из очереди элемент
        ss << Ttmp; // преобразуем его в строку
        ss >> stmp;
        ctmp = stmp.back(); // берём последний знак числа
        /* lenght = stmp.length(); // находим длину строки
        i = 2;
        while(ctmp == '0' && i < length) // пока последний знак числа 0
        {
            ctmp = stmp[-i];
            i++;
        } */
        if(ctmp ==  '1' || ctmp ==  '3' || ctmp ==  '5' || ctmp ==  '7' || ctmp ==  '9') // если последний знак числа - нечётный
        {
            max = Ttmp; // запоминаем число как нечётный максимум
            k = 1; // запоминаем, что нашли хотя бы одно нечётное число
            break; // перываем выполнение цикла, т.к. нашли первое число
            
        }
    }

    while(!queue.isEmpty()) // пока очередь не пуста
    {
        Ttmp = queue.DeQueue(); // достаём из очереди элемент
        ss << Ttmp; // преобразуем число в строку
        ss >> stmp;
        ctmp = stmp.back(); // берём последний знак числа   
        if((ctmp ==  '1' || ctmp ==  '3' || ctmp ==  '5' || ctmp ==  '7' || ctmp ==  '9') && Ttmp > max) // если послдений знак числа - нечётный и это число больше нынешнего максимума
            max = Ttmp; // запоминаем это число как нечётный максимум
    }
    if(k) // если нашли хотя бы одно число
        return 1; // поиск успешный
    else 
        return 0; // не успешный поиск
}
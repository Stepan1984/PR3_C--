#include <cmath>
#include <sstream>

using namespace std;

template <class TData, class TQueue>
int find_odd_max(TQueue queue, TData &max)
{
    bool k = false;
    stringstream ss;
    TData Ttmp;
    string stmp;
    char ctmp;
    while(!queue.isEmpty()) // поиск первого нечётного (пока не пусто)
    {
        Ttmp = queue.DeQueue();
        ss << Ttmp;
        ss >> stmp ;
        ctmp = stmp.back();
        if(ctmp ==  '1' || ctmp ==  '3' || ctmp ==  '5' || ctmp ==  '7' || ctmp ==  '9') // если нечётное
        {
            max = Ttmp; // запоминаем его
            break; // выходим из цикла
            k = 1;
        }
    }

    while(!queue.isEmpty()) // пока не список не пуст
    {
        Ttmp = queue.DeQueue();
        ss << Ttmp;
        ss >> stmp ;
        ctmp = stmp.back();   
        if((ctmp ==  '1' || ctmp ==  '3' || ctmp ==  '5' || ctmp ==  '7' || ctmp ==  '9') && Ttmp > max) // если нечётное и больше максимума
            max = Ttmp; // запоминаем
    }
    if(k)
        return 1;
    else
        return 0;
}
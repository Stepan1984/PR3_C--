using namespace std;

template <class Tnumber, class Tqueue>
Tnumber find_odd_max(Tqueue &queue)
{
    Tnumber max, * cur = queue; // устанавливаем указатель на 1 элемент очереди
    while(cur)
    {
        if(cur.data & 1) // если элемент нечётный
        {
            max = cur.data; // записываем его в max
            break;
        }
        cur = cur->next; 
    }
    while(cur) // пока в очереди есть элементы
    {
        if(cur.data & 1) // если нечётное
            if(cur.data > max) // если больше нынешнего максимума
                max = cur.data; 
        cur = cur->next;
    }
    return max;
}

/* template <class T ,class T1, class T2>
T find_odd_max(T1 a, T2 b)
{
    if(a & 1 && b & 1) // если оба числа нечётные
    {
        if(a > b)
            return a;
        else
            return b;
    }
    else
        return -0;
} */
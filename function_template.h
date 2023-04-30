using namespace std;

template <class Tdata, class Tnumber>
Tnumber find_odd_max(Tdata * array)
{
    Tnumber max, * cur = array.begin(); // устанавливаем указатель на 1 элемент очереди
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
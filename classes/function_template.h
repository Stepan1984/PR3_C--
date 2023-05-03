using namespace std;

/* template <class Tnumber, class Tqueue>
Tnumber find_odd_max(Tqueue &queue)
{
    Tnumber max, 
    * cur = queue.tail; // ������������� ��������� �� 1 ������� �������
    while(cur)
    {
        if(cur.data & 1) // ���� ������� ��������
        {
            max = cur.data; // ���������� ��� � max
            break;
        }
        cur = cur->next; 
    }
    while(cur) // ���� � ������� ���� ��������
    {
        if(cur.data & 1) // ���� ��������
            if(cur.data > max) // ���� ������ ��������� ���������
                max = cur.data; 
        cur = cur->next;
    }
    return max;
} */

/* template <class T ,class T1, class T2>
T find_odd_max(T1 a, T2 b)
{
    if(a & 1 && b & 1) // ���� ��� ����� ��������
    {
        if(a > b)
            return a;
        else
            return b;
    }
    else
        return -0;
} */

template <class TData, class TQueue>
TData find_odd_max(TQueue &queue)
{
    void * cur = queue->tail;
    TData max;
    while(cur) // ����� ������� ���������
    {
        if(cur.data & 1) // ���� ��������
        {
            max = cur.data;
            break;    
        }
        cur = cur->next;
    }

    while(cur)
    {
        if(cur.data & 1 && max < cur.data) // ���� ��������
            max = cur.data;
        cur = cur->next;
    }
    return max;
}
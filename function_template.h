using namespace std;

template <class Tdata, class Tnumber>
Tnumber find_odd_max(Tdata * array)
{
    Tnumber max, * cur = array.begin(); // ������������� ��������� �� 1 ������� �������
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
}
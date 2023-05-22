//#include <cmath>
#include <sstream>

using namespace std;

template <class TData, class TQueue>
int find_odd_max(TQueue queue, TData &max)
{
    bool k = false; // ���� ������� ��������� ����� � �������
    stringstream ss;
    TData Ttmp;
    string stmp;
    char ctmp;
    int i, lenght;
    while(!queue.isEmpty()) // ���� ������� �� �����
    {
        Ttmp = queue.DeQueue(); // ������ �� ������� �������
        ss << Ttmp; // ����������� ��� � ������
        ss >> stmp;
        ctmp = stmp.back(); // ���� ��������� ���� �����
        /* lenght = stmp.length(); // ������� ����� ������
        i = 2;
        while(ctmp == '0' && i < length) // ���� ��������� ���� ����� 0
        {
            ctmp = stmp[-i];
            i++;
        } */
        if(ctmp ==  '1' || ctmp ==  '3' || ctmp ==  '5' || ctmp ==  '7' || ctmp ==  '9') // ���� ��������� ���� ����� - ��������
        {
            max = Ttmp; // ���������� ����� ��� �������� ��������
            k = 1; // ����������, ��� ����� ���� �� ���� �������� �����
            break; // �������� ���������� �����, �.�. ����� ������ �����
            
        }
    }

    while(!queue.isEmpty()) // ���� ������� �� �����
    {
        Ttmp = queue.DeQueue(); // ������ �� ������� �������
        ss << Ttmp; // ����������� ����� � ������
        ss >> stmp;
        ctmp = stmp.back(); // ���� ��������� ���� �����   
        if((ctmp ==  '1' || ctmp ==  '3' || ctmp ==  '5' || ctmp ==  '7' || ctmp ==  '9') && Ttmp > max) // ���� ��������� ���� ����� - �������� � ��� ����� ������ ��������� ���������
            max = Ttmp; // ���������� ��� ����� ��� �������� ��������
    }
    if(k) // ���� ����� ���� �� ���� �����
        return 1; // ����� ��������
    else 
        return 0; // �� �������� �����
}
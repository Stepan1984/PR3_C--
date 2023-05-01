#include <iostream>
#include <cstdlib>
#include <typeinfo>

using namespace std;

template <class Tdata>
class VectorQueue
{
    private:
        int head, tail; // ������� ������ � ������
        int maxLength; // ������ �������
        Tdata * data; // ��������� �� ������ ������
    public:
        VectorQueue(int n = 10): maxLength(n) // �����������
        {
            data = new Tdata[maxLength]; // ������ ������
            head = 0;
            tail = head - 1;
        }

        ~VectorQueue() // ����������
        {
            delete[] data;
        }

        int isEmpty() // �������� �� �������
        {
            return (tail + 1) % maxLength == head;
        }

        int isFull() // �������� �������
        {
            return (tail + 2) % maxLength == head; 
        }

        Tdata getHead() // ������������� ������ �� ������ �������
        {
            if(isEmpty())
                return 0;
            return data[head];
        }

        int EnQueue(Tdata x) // �������� ������� � �������
        {
            if (isFull()) // ���� ������� ��������� 
                return 0;
            tail = (tail + 1) % maxLength; // ����������� ������ ���������� ��������
            data[tail] = x; // ��������� ������ � ������ �������
            return 1;
        }

        Tdata DeQueue() // ���������� �������� �� ������ �������
        {
            if(isEmpty())
                return 0;
            int temp = head;
            head = (head + 1) % maxLength;
            return data[temp];
        }

};

template <class Tdata>
class ListQueue
{
    private:
        struct item
        {
            Tdata data;
            item * next;
        } *head, * tail; //������� ������ � ������
    public:
        ListQueue() // �����������
        {
            head = tail = NULL;
        }

        ~ListQueue() // ����������
        {
            item * temp = head;
            while(head)
            {
                temp = head;
                head = head->next;
                delete temp;
            }
        }

        int isEmpty() // �������� �� �������
        {
            return head == NULL;
        }

        int isFull() // �������� �������
        { // �� ���������, ���� ����� �������� ������ ��� ��� ���� �� ���� �������
            item * temp = new (nothrow) item; // nothrow - �������� �����������, ��� � ����������� �������, � �������, ������� ��� ��������, ������� �� ������� ����������.
            if(temp == NULL) 
                return 1;
            delete temp;
            return 0; 
        }

        Tdata getHead() // ������������� ������ �� ������ �������
        {
            if(isEmpty())
                return 0;
            return head->data;
        }

        int EnQueue(Tdata x) // �������� ������� � �������
        {
            item * temp = new (nothrow) item; // �������� ������
            if(temp == NULL)
                return 0;
            temp->data = x; // ��������� ������ � ���� ������
            temp->next = NULL;
            if(head == NULL) // ���� ������ ������
                head = tail = temp;
            else // ���� �� ������
            {
                tail->next = temp;
                tail = tail->next;
            }
            return 1;
        }

        Tdata DeQueue() // ���������� �������� �� ������ �������
        {
            if(isEmpty()) // ���� ������ ������
                return 0;
            Tdata temp = head->data; // ��������� ������ �� ��������� ����������
            item * tmp = head; // ���������� ��������� �� ������ ������
            if(head == tail)
                tail = head = NULL;
            else
                head = head->next;
            delete tmp; // ������� ���� ������ ������
            return temp; // ���������� 
        }
};


template<class T>
T input(T &value)
{
    string input;
    int i;
    char flag;
    do
    {
        system("cls");
        cout << "������� " << typeid(value).name() << " : " << endl ;
        cin >> input; 
        cin.get();
        if(input[0] != '-' && !isdigit(input[0])  ||  !input.compare("-0") ) // ���� ������ ���� �� "-" ��� �� �����
        {
            cout << "������������ ��������, ��������� �������: ";
            continue;
        }
        
        i = 1;
        flag = 1;
        while(input[i] != '\0')
        {
            if(!isdigit(input[i]) || input[i] != '.')
            {
                cout << "������������ ��������, ��������� �������: ";
                flag = 0;
                break;
            }
            else
                flag = 1;
            i++;
        }
    }while(!flag);
    return value = stoi(input);
}

// �������� � ������
// ���� ������ ���� �� "-" ��� �� �����
//      ���������� ��������� ����
// ���� ������ ���� �� �����
//      ���������� ��������� ����


// �������� � ������
// ���� ������ ���� �� "-" ��� �� �����
//  ���������� ��������� ����
// int i = 1;
// ���� �� ����� ������
//      ���� string[i] �� �����
//          ������ ���������� �����
//          break;
//      i++;
// value = stoi(input);
// return 1;
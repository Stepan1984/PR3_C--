#include <iostream>
#include <cstdlib>

using namespace std;

template <class Tdata>
class VectorQueue:
{
    private:
        int head, tail; // индексы головы и хвоста
        int maxLength; // размер массива
        Tdata * data; // указатель на массив данных
    public:
        VectorQueue(int maxLength = 100;) // конструктор
        {
            data = new Tdata[maxLength];
            head = 0;
            tail = head - 1;
        }

        ~VectorQueue() // деструктор
        {
            delete[] data;
        }

        int isEmpty() // проверка на пустоту
        {
            return (tail + 1) % maxLength == head;
        }

        int isFull() // проверка полноты
        {
            return (tail + 2) % maxLength == head; 
        }

        Tdata getHead() // неразрушающее чтение из головы очереди
        {
            return data[head];
        }

        int EnQueue(Tdata x) // добавить элемент в очередь
        {
            if (isFull()) // если очередь заполнена 
                return 0;
            tail = (tail + 1) % maxLength; // увеличиваем индекс последнеги элемента
            data[tail] = x; // сохран€ем данные в €чейку массива
            return 1;
        }

        Tdata DeQueue() // извлечение элемента из головы очереди
        {
            int temp = head;
            head = (head + 1) % maxLength;
                return data[temp];
        }
};

template <class Tdata>
class ListQueue:
{
    private:
        struct item
        {
            Tdata data;
            item * next;
        } *head, * tail; //индексы головы и хвоста
    public:
        ListQueue() // конструктор
        {
            head = tail = NULL;
        }

        ~ListQueue() // деструктор
        {
            item * temp = head;
            while(head)
            {
                temp = head;
                head = head->next;
                delete temp;
            }
        }

        int isEmpty() // проверка на пустоту
        {
            return head == NULL;
        }

        int isFull() // проверка полноты
        {   item * temp = new (nothrow) item; // nothrow - сообщает компил€тору, что и объ€вленна€ функци€, и функции, которые она вызывает, никогда не создают исключений.
            if(temp == NULL) return 1;
            delete temp;
            return 0; 
        }

        Tdata getHead() // неразрушающее чтение из головы очереди
        {
            return head->data;
        }

        int EnQueue(Tdata x) // добавить элемент в очередь
        {
            item * temp = new (nothrow) item;
            if(temp == NULL)
                return 0;
            temp->data = x;
            if(head == NULL)
                head = tail = temp;
            else
            {
                tail->next = temp;
                tail = tail->next
            }
            return 1;
        }

        Tdata DeQueue() // извлечение элемента из головы очереди
        {
            Tdata temp = head->data;
            item * tmp = head;
            delete tmp;
            return temp;
        }
};
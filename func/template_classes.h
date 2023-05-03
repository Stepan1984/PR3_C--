#include <iostream>
#include <typeinfo>

using namespace std;

template <class Tdata>
class VectorQueue
{
    private:
        int head, tail; // индексы головы и хвоста
        int maxLength; // размер массива
        Tdata * data; // указатель на массив данных
    public:
        VectorQueue(int n = 10): maxLength(n) // конструктор
        {
            data = new Tdata[maxLength]; // создаЄм массив
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
            if(isEmpty())
                return 0;
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
        } *head, * tail; //индексы головы и хвоста
    public:
        ListQueue() // конструктор
        {
            head = tail = NULL;
        }

        ~ListQueue() // деструктор
        {
            while(head)
                this->DeQueue();
        }

        int isEmpty() // проверка на пустоту
        {
            return head == NULL;
        }

        int isFull() // проверка полноты
        { // не заполнена, если можно выделить пам€ть под ещЄ хот€ бы один элемент
            item * temp = new (nothrow) item; // nothrow - сообщает компил€тору, что и объ€вленна€ функци€, и функции, которые она вызывает, никогда не создают исключений.
            if(temp == NULL) 
                return 1;
            delete temp;
            return 0; 
        }

        Tdata getHead() // неразрушающее чтение из головы очереди
        {
            if(isEmpty())
                return 0;
            return head->data;
        }

        int EnQueue(Tdata x) // добавить элемент в очередь
        {
            item * temp = new (nothrow) item; // выдел€ем пам€ть
            if(temp == NULL)
                return 0;
            temp->data = x; // сохран€ем данные в узел списка
            temp->next = NULL;
            if(head == NULL) // если список пустой
                head = tail = temp;
            else // если не пустой
            {
                tail->next = temp;
                tail = tail->next;
            }
            return 1;
        }

        Tdata DeQueue() // извлечение элемента из головы очереди
        {
            if(isEmpty()) // если список пустой
                return 0;
            Tdata temp = head->data; // сохран€ем данные во временную переменную
            item * tmp = head; // запоминаем указатель на голову списка
            if(head == tail)
                tail = head = NULL;
            else
                head = head->next;
            delete tmp; // удал€ем узел головы списка
            return temp; // возвращаем значение из списка
        }
};




// считываю в строку
// если первый знак не "-" или не цифра
//      запрашиваю повторный ввод
// если второй знак не цифра
//      запрашиваю повторный ввод


// считываю в строку
// если первый знак не "-" или не цифра
//  запрашиваю повторный ввод
// int i = 1;
// пока не конец строки
//      если string[i] не цифра
//          «апрос повторного ввода
//          break;
//      i++;
// value = stoi(input);
// return 1;
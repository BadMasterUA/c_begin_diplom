#include<iostream>

using namespace std;

template <class T> //шаблон класса с переменной Т
class List
{
public:
    List() : head(0), tail(0), theCount(0) {}
	virtual ~List();
    T front() const {}; //возврашает значение первого эл.
    T back() const {}; //возврашает значение последнего эл.
    void push_front(T value) {}; //добавдление дового эд. в начало списка
    void push_back(T value) {}; //добавдление дового эд. в конец списка
    void pop_front() {}; //удаление первого здачения в списе
    void pop_back() {}; //удаление последнего здачения в списе
	void insert(T value); //вставка эл. в список

    //тут я что-то на городил
    class Iterator; // объявление класса итератора
    Iterator begin() const; // функция begin
    Iterator end() const; // функция end
    //тут закончил

    int size() { return theCount; } //возврашаем кол-во эл.
	bool is_present(T value) const;
	T is_empty() const
	{
    	return head == 0;
	}
	T count() const { return theCount; }
private:
	class ListCell
	{
	public:
    	ListCell(T value, ListCell *cell = 0) : val(value), next(cell) {}
    	T val;
    	ListCell *next;
	};
	T val;
	ListCell *next; // списокзначений
	ListCell *head; // первый эл.
	ListCell *tail; // полседний эл.
	T theCount;
};

//деструктор
template <typename T>
List<T>::~List()
{
	while (head != nullptr)
	{
		ListCell *temp = head;
		head = head->next;
		delete temp;
	}	
}

//возврашает значение первого эл.
template <typename T>
T List<T>::front() const
{
    if(head != nullptr)
    {
        return head->val;
    }
    throw std::cout << "List is empty";
}
//возврашает значение последнего эл.
template <typename T>
T List<T>::front() const
{
    if(head != nullptr)
    {
        return tail->val;
    }
    throw std::cout << "List is empty";
}

//вставка
template <typename T>
void List<T>::insert(T value)
{
    head = new ListCell(value, head);
    if (tail == nullptr)
    {
        tail = head;
    }
    ++theCount;
}

//добавление в начало списка
template <typename T>
void List<T>::push_front(T value)
{
    ListCell *newCell = new ListCell(value, head);
    head = newCell;
    if(tail == null)
    {
        tail = newCell;
    }
    ++theCount;
}

//додавление в конец списка
template <typename T>
void push_back(T value)
{
    ListCell *newCell = new ListCell(value, tail);
    tail = newCell;
    if(tail == null)
    {
        tail = newCell;
    }
    ++theCount;
}

//удаление первого эл.
template <typename T>
void pop_front()
{
    if(head != nullptr)
    {
        ListCell *oldHead = head;
        head = head->next;
        delete oldHead; // удаление старого варианта
        --theCount; // уменьшаем длину
    }
}

//удаление последнего эл.
template <typename T>
void pop_back()
{
    if (tail != nullptr)
    {
        //если начало и конец одинаковые
        if (head == tail)
        {
            delete head; // удал. начальное значь.  
            head = tail = nullptr;// зануляем
        }
        else
        {
            ListCell *prev = head;
            while (prev->next != tail)
            {
                prev = prev->next;
            }
            delete tail;
            tail = prev;
            tail->next = nullptr;
        }
        --theCount;
    }
}

template <typename T>
bool List<T>::is_present(T value) const
{
    for (ListCell *cell = head; cell != nullptr; cell = cell->next)
    {
        if (cell->val == value)
        {
            return true;
        }
    }
    return false;
}

//тут реализиция велосепеда
// класс итератора
template <typename T>
class List<T>::Iterator
{
public:
    Iterator(ListCell *ptr) : current(ptr) {}
    T& operator*() { return current->val; }
    Iterator& operator++() { current = current->next; return *this; }
    bool operator!=(const Iterator& other) const { return current != other.current; }
private:
    ListCell *current;
};

// функция begin
template <typename T>
typename List<T>::Iterator List<T>::begin() const
{
    return Iterator(head);
}

// функция end
template <typename T>
typename List<T>::Iterator List<T>::end() const
{
    return Iterator(nullptr);
}
//велосепед окончен

int main()
{
    List<int> myList;
    myList.push_front(1);
    myList.push_back(2);
    myList.push_back(3);

    //вывод
    for(auto it = myList.begin(); it != myList.end(); ++it)
    {
        std::cout << *it << " ";
    }
    return 0;
}

/*
(*)front() – Повертає значення першого елемента в списку.
(*)back() – Повертає значення останнього елемента в списку.
(*)push_front() – додає новий елемент на початку списку.
(*)push_back() – додає новий елемент у кінець списку.
(*)pop_front() – видаляє перший елемент списку та зменшує розмір списку на 1.
(*)pop_back() – видаляє останній елемент списку та зменшує розмір списку на 1.
(*)insert() – вставляє нові елементи в список перед елементом у вказаній позиції.
(*)size() – повертає кількість елементів у списку.
(*)begin() – функція begin() повертає ітератор, що вказує на перший елемент списку.
(*)end() – функція end() повертає ітератор, що вказує на теоретичний останній елемент, який слідує за останнім елементом.
*/
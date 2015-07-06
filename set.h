#ifndef SET_H
#define SET_H
#include <iostream>
using namespace std;

template <class T>
class root{
    T inf;
    root *next,*prev;
};

template <class T>
class List
{
    root<T> *head;
public:
    List(){
    head = NULL;
    }
    ~List(){
    }
    List(const List&); //конструктор копии
    void addLast(T); //добавление в конец списка
    void removeLast(); //удаление с конца списка
    bool findElem(T);// проверка наличия элемента в списке
    bool isEmpty(); // проверка на пустоту
    T count(); // количество элементов списка

};

template <class T>
class Set : List<T>
{
public:
    Set& operator|=(T); //добавление элемента в множество
    Set& operator/=(T); //исключение элемента из множества
    Set& operator||(Set&); //объединение множеств
    Set& operator&&(Set&); //пересечение множеств
    Set& operator==(Set&); //сравнение множеств на равенство
    friend ostream& operator<<(ostream &,Set &); //вывод в поток
    friend istream& operator>>(istream &,Set &); //ввод из потока

};

#endif // SET_H

#ifndef SET_H
#define SET_H
#include <iostream>
using namespace std;

template <class T>
class node{
public:
    T inf;
    node *next,*prev;
};

template <class T>
class List
{
    node<T> *head;
public:
    List(){
    head = NULL;
    }
    ~List();

    List(const List<T&>&); //конструктор копии (Саша)
    void addLast(T&); //добавление в конец списка (Саша)
    void removeLast(); //удаление с конца списка (Илья)
    bool findElem(T&);// проверка наличия элемента в списке (Илья)
    bool isEmpty(); // проверка на пустоту (Илья)
    int count(); // количество элементов списка (Илья)

};

template <class T>
class Set : List<T>
{
public:
    Set& operator|=(T&); //добавление элемента в множество (Саша)
    Set& operator/=(T&); //исключение элемента из множества (Саша)
    Set& operator||(Set&); //объединение множеств (Саша)
    Set& operator&&(Set&); //пересечение множеств (Илья)
    Set& operator==(Set&); //сравнение множеств на равенство (Илья)
    friend ostream& operator<<(ostream &,Set &); //вывод в поток (Илья)
    friend istream& operator>>(istream &ist,Set &s){
        T data;
        while(!ist.eof()){
            ist>>data;
            s.addLast(data);
        }
       return ist;
    } //ввод из потока (Саша)

    int numElem(T&); //выдает номер заданного элемента в множестве

};


template <class T>
List<T>::~List()
{
    while(head){
        node<T> *t = head;
        head = head -> next;
        head -> prev = 0;
        delete t;
    }
}

template <class T>
List<T>::List(const List<T&>& s){
    head = 0;
    node<T> *q = s.head;
    while (q){
        addLast(q->inf);
        q = q->next;
    }
}

template <class T>
void List<T>::addLast(T& data){
    node<T> *elem = new node;
    node<T> *t = head;
    elem->inf = data;
    elem->next = nullptr;
    elem->prev = nullptr;
    if(head){
        while(t->next) t=t->next;
        t->next = elem;
        elem->prev = t;
    }
     else head = elem;
}

template <class T>
Set<T>& Set<T>::operator|=(T& data){
    if(!findElem(data)){
        addLast(data);
        node<T> *t = head;
        for(int i=1;i<count();i++)
           for(int j=0;j<count()-i;j++)
              if(t->inf>t->next->inf) swap(t->inf,t->next->inf);
    }
}

template <class T>
Set<T>& Set<T>::operator/=(T& data){
    if(findElem(data)){
        node<T> *t = head;
        for(int i=0;i<numElem(data);i++) t = t->next;
        node<T> *q = t;
        while(t->next)t = t->next;
        q->prev->next = q->next;
        t->next = q; q->prev = t; q->next = 0;
        removeLast();
    }
}

template <class T>
Set<T>& Set<T>::operator||(Set& s){
    node<T> *t = s.head;
    if(!isEmpty()){
        if(s.head)
            while(t->next){
               *this|=t->inf;
                t = t->next;
            }
    }
    return *this;
}


template <class T>
int Set<T>::numElem(T& comp){
    int k = 0;
    if(head){
        node<T> *t = head;
         if(findElem(comp)){
         while(t->inf != comp) {
                t = t->next;
                k++;
             }
         }
    }
   return k;
}

#endif // SET_H

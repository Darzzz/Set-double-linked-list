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

    List(const List<T&>&); //конструктор копии (Саша) -
    void addLast(T&); //добавление в конец списка (Саша) -
    void removeLast(); //удаление с конца списка (Илья) -
    bool findElem(T&);// проверка наличия элемента в списке (Илья)-
    bool isEmpty(); // проверка на пустоту (Илья)-
    int count(); // количество элементов списка (Илья)-

};

template <class T>
class Set : List<T>
{
public:
    Set& operator|=(T&); //добавление элемента в множество (Саша)-
    Set& operator/=(T&); //исключение элемента из множества (Саша)-
    Set& operator||(Set&); //объединение множеств (Саша)
    Set& operator&&(Set&); //пересечение множеств (Илья)
    Set& operator==(Set&); //сравнение множеств на равенство (Илья)
    friend ostream& operator<<(ostream &ost,Set &s){ //вывод в поток (Илья)
        Node<T> *t = s.head;
        while(t->next !=nullptr){
           ost<<t->inf;
           t=t->next;}
        return ost;
    }
    friend istream& operator>>(istream &ist,Set &s){//эту штуку нужно вынести из класса
        T data;
        while(ist.good){
            ist>>data;
            s.addLast(data);
        }
       return ist;
    } //ввод из потока (Саша)

    int numElem(T&); //выдает номер заданного элемента в множестве

};

/*istream& operator>>(istream &ist,Set &s){
        T data;
        while(ist.good()){
            ist>>data;
            s.addLast(data);
        }
       return ist;
    } //ввод из потока (Саша)*/


template <class T>//деструктор
List<T>::~List()
{
    while(head){
        node<T> *t = head;
        head = head -> next;
        head -> prev = 0;
        delete t;
    }
}

template <class T>// конструктор
List<T>::List(const List<T&>& s){
    head = 0;
    node<T> *q = s.head;
    while (q){
        addLast(q->inf);
        q = q->next;
    }
}

template <class T>//добавление в конец списка
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

template <class T>//добавление элем во множ-во
Set<T>& Set<T>::operator|=(T& data){
    if(!findElem(data)){
        addLast(data);
        node<T> *t = head;
        for(int i=1;i<count();i++)
           for(int j=0;j<count()-i;j++)
              if(t->inf>t->next->inf) swap(t->inf,t->next->inf);
    }
}

template <class T>//исключение элемента
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

template <class T>//объединение мн-в
Set<T>& Set<T>::operator||(Set& s){
    node<T> *t = s.head;
    if(!isEmpty()){
        if(s.head)
            while(t->next){
               if(!findElem(t->inf))
                   *this|=t->inf;
               t = t->next;
            }
    }
    return *this;
}


template <class T>//выдает номер заданного элемента
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

template <class T>//оператор пересечения
Set<T>& Set<T>::operator&&(Set& s){
    node<T> *t = s.head;
    if(!isEmpty()){
        while(t->next!=nullptr){
            if(!findElem(t->inf))
                s/=t->inf;
            t= t->next; }
        }
     return s;
}

template <class T>//сравнение мн-в
Set<T>& Set<T>:: operator==(Set& s){
    node<T>* t = s.head;
    if(!isEmpty()){
        while(t->next!=nullptr){
           if(!findElem(t->inf)){
               return false;
               break;  }
           t=t->next;  }
    }
    return true;
}

template <class T>// удаление последнего
void List<T>::removeLast(){
    node<T>* t = head;
    if(head){
       t= t->next;
       t->prev= nullptr;}
    else{
       while(t->next!=nullptr)
          t=t->next;
       t=t->prev;
       t->next = nullptr;
       delete t1;
    }
}

template <class T>//поиск элемента
bool List<T>:: findElem(T&){
    node<T>* t = head;
    while(t->next==nullptr){
        if(t->inf == T*){
            return true;
            break;}
        t= t->next;
    }
    return false;
}

template <class T>// проверка на пустоту
bool List<T>::isEmpty(){
    node<T>* t = head;
    if(t==nullptr)
        return true;
    else return false;
}

template <class T>// счет
int List<T>:: count(){
    node<T>* t= head;
    int k=0;
    while(t!=nullptr){
        k++;
        t=t->next;}
    return k;
}




#endif // SET_H

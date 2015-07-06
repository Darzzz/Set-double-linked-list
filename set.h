#ifndef SET_H
#define SET_H
#include <iostream>
using namespace std;

template <class T>
struct root{
    T inf;
    root *next,*prev;
};

template <class T>
class List
{
    root *head;
public:
    ~List();

    void addLast(T newData);
    void removeLast();
    T getItem(T index);
    friend istream &operator>>(istream &ist,List &A);
    bool findElem(T);
    bool isEmpty();
    T count();

};

template <class T>
class Set : List
{
    root *head;
public:
    Set();
    ~Set();
    Set& operator|=(T);
    Set& operator/=(T);
    Set& operator||(Set&);
    Set& operator&&(Set&);
    Set& operator==(Set&);
    friend ostream& operator<<(ostream &,Set &);
    friend istream& operator>>(istream &,Set &);

};

#endif // SET_H

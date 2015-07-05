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
class Set
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
    bool isEmpty();
    bool findElem(T);
};

#endif // SET_H

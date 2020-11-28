#ifndef USUARIOS_H
#define USUARIOS_H
#include<iostream>
#include"Usuario.h"

using namespace std;
template<class T>
class Usuarios{
private:

    struct Nodo
    {
        T date;
        Nodo*next;
        Nodo*back;
        Nodo(T date , Nodo*next = nullptr, Nodo*back = nullptr)
            :date(date), next(next), back(back) {}
    }*Head;
     int len;
public:
    Usuarios() {
        Head = nullptr;
        len = 0;
    }
    ~Usuarios() {}
    void AddInicio(T date) {
        if (len == 0) {
            Head = new Nodo(date);
            Head->next=Head;
            Head->back=Head;
        }
        else {
            Nodo *nuevo = new Nodo(date,Head->back,Head);
            Head->back=nuevo;
            nuevo->back->next = nuevo;
            Head= nuevo;
        }
        len++;
    }
    void addLast(T elem) {
           if (len == 0) {
               AddInicio(elem);
           } else {
               Nodo *newest = new Nodo(elem, Head->back, Head);
               Head->back = newest;
               newest->back->next = newest;
               len++;
           }
       }
    void eliminateEnd() {
        if (len == 0) {
            return;
        }
        if (len== 1) {
            delete Head;
            Head = nullptr;
        } else {
            Nodo *aux = Head->back;
            aux->back->next = Head;
            Head->back = aux->back;
            delete aux;
        }
        --len;
    }
    T getPos(int pos){
        Nodo* aux = Head;
                for (int i = 0; i < pos; i++) {
                    aux = aux->next;
                }
        return aux->date;
    }
    int getTam(){return len;}
};

#endif // USUARIOS_H

#ifndef AMIGOS_H
#define AMIGOS_H
#include<iostream>
#include"Persona.h"
#include<functional>
#include<QApplication>

using namespace std;
template<class T,class R=T>
class Amigos
{
private:
    T len;
    struct Node
    {
        Persona<string,int>*date;
        Node*next;
        Node*back;
        Node(Persona<string,int>*date = nullptr, Node*next = nullptr, Node*back = nullptr) :next(next), date(date), back(back) {}
    }*Head, *End, *actual;
public:
    Amigos() {
        Head = nullptr;
        actual = nullptr;
        End = nullptr;
        //	End = nullptr;
        len = 0;
    }
    ~Amigos() {}
    void Add(Persona<string,int>*date) {
        Node*nuevo = new Node(date);
        if (Head == nullptr) {
            Head = nuevo;
            actual = nuevo;
        }
        else {
            nuevo->next = Head;
            End->next = nuevo;
            nuevo->back = End;
            Head->back = nuevo;
        }
        End = nuevo;
        len++;
    }
    void eliminate() {
        Node*aux = actual;
        aux->back->next = aux->next;
        aux->next->back = aux->back;
        if (actual == Head) {
            actual = aux->next;
            Head = actual->next;
        }
        else if (actual == End) {
            actual = aux->next;
            End = actual->next;
        }

        else actual = aux->next;

        delete aux;
        len--;
      if (len == 0) {
          actual = nullptr;
          Head = nullptr;
          End = nullptr;
        }
    }
    void LoveLambda(function<void(R)>operacion) {
        Node*aux = Head;
        for (T i = 1; i <= len; i++) {
            operacion(aux->date);
            aux=aux->next;
        }

    }
    template<class C>//C=Persona*
    void sort(
        function<C(R)> valor) {
        Node*aux1 = Head;

        for (int i =1; i <=len ; ++i,aux1=aux1->next) {
             Node*aux2 = aux1->next;
            for (int j =i ; j <=len-1; ++j,aux2=aux2->next) {
                if (valor(aux1->date)>valor(aux2->date)) {
                swap(aux1->date, aux2->date);
                }
            }
        }
    }
    bool empty() {
        return (Head == nullptr) ? true : false;
    }
    void Next() {
        actual = actual->next;
    }
    void Back() {
        actual = actual->back;
    }
    Node*getHead() {
            return Head;
        }
        Node*getEnd() {
            return End;
        }
    Node*getActual() {
        return actual;
    }
    void Again() {
           actual = Head;
       }
    int size() {
            return len;
        }
};


#endif // AMIGOS_H

#ifndef PERSONAS_H
#define PERSONAS_H
#include<iostream>
#include"Persona.h"
using namespace std;
template<class T>
class Personas
{
private:
    T len;
    struct Node
    {
        Persona<string,int>*date;
        Node*next;
        Node(Persona<string,int>*date = nullptr, Node*next = nullptr) :next(next), date(date) {}
    }*Head, *End;
public:
    Personas() {
        Head = nullptr;
        End = nullptr;
        len = 0;
    }
    ~Personas() {}
    void push(Persona<string,int>*date) {
        Node*nuevo = new Node(date);
        if (Head == nullptr) {
            Head = nuevo;
        }
        else {
            End->next = nuevo;
        }
        End = nuevo;
        len++;
    }
    Node*front() {
        return Head;
    }
    void pop() {
        Node*aux = Head;
        Head = aux->next;
        delete aux;
        len--;
    }
    bool empty() {
        return (Head == nullptr) ? true : false;
    }
    int size() {
        return len;
    }

};

#endif //PERSONAS_H

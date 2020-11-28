#ifndef Persona_H
#define Persona_H
#include<string>
#include<functional>
#include"Mensajes.h"
using namespace std;
template <class T, class R = T>
class Persona {
    T nombre;
    T trabajo;
    T estado;
    T hobby;
    R edad;
    R numero;
    T photo;
    bool like, heart, smile;
    Mensajes<string>*chat = new Mensajes<string>();
public:
    Persona(T nombre, T trabajo, T hobby, T estado, R edad, R numero, T photo) :nombre(nombre), trabajo(trabajo), hobby(hobby), estado(estado), edad(edad), numero(numero), photo(photo) {
        like = heart = smile = false;
    }
    T getNombre() { return  nombre; }
    T getTrabajo() { return  trabajo; }
    T getEstado() { return  estado; }
    R getEdad() { return  edad; }
    R getNumero() { return numero; }
    T getHobby() { return hobby; }
    T getFoto() { return photo; }
    Mensajes<string>*getChat() {
        return chat;
    }
    void setNombre(T x) { nombre = x;}
    void setTrabajo(T x) { trabajo = x;}
    void setEstado(T x) { estado = x;}
    void setEdad(R x) { edad = x; }
    void setNumero(R x) { numero = x;}
    void setHobby(T x) { hobby = x;}
    void setFoto(T x) { photo = x;}
    bool getLike() { return like;}
    bool getHeart() { return heart;}
    bool getSmile() { return smile;}

    void setLike(bool x) { like = x; }
    void setHeart(bool x) { heart = x; }
    void setSmile(bool x) { smile = x ;};
};

#endif // Persona_H

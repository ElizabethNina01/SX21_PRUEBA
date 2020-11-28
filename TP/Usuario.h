#ifndef USUARIO_H
#define AMIGO_H
#include<string>
#include<QApplication>
#include<QLabel>
#include <QString>
#include "mainwindow.h"
using namespace std;
template <typename T>
class Usuario {
    T nombre;
    T apellido;
    T correo;
    T contrasena;
    T fecha;
    T photo;
    MainWindow *perfil;
public:
    Usuario(T nombre, T apellido, T correo,T contrasena, T fecha, T p) :
        nombre(nombre), apellido ( apellido), correo(correo), contrasena(contrasena),fecha(fecha), photo(p){
        perfil=new MainWindow(nullptr,photo,nombre,apellido,fecha);
    }
    T getNombre(){return  nombre; }
    T getApellido() {return  apellido; }
    T getCorreo() { return  correo; }
    T getContrasena() {   return  contrasena; }
    T getFecha(){return fecha;}
    T getPhoto(){return photo;}
    void setNombre(T n){nombre=n;}
    void setApellido(T n){apellido=n;}
    void setCorreo(T n){correo=n;}
    void setContrasena(T n){contrasena=n;}
    void setFecha(T n){fecha=n;}
    void setPhoto(T n){photo=n;}
    MainWindow* getPerfil(){return perfil;}
};

#endif // AMIGO_H

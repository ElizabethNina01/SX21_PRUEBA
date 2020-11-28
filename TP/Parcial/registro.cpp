#include "registro.h"
#include "ui_registro.h"
#include <QFileDialog>
#include <QPixmap>
#include <QMessageBox>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <QTextStream>
Registro::Registro(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Registro)
{
    direccionArch = QDir::currentPath()+"/archivo.txt";
    ui->setupUi(this);

  lista=new Usuarios<Usuario<QString>>();
    auxfoto=":/EXTRAS/EXTRAS/userdesc.jpg";
    ui->stackedWidget->setCurrentIndex(1);
   this->resize(830,730);

    QPixmap mypix(":/EXTRAS/EXTRAS/userdesc.jpg");
    ui->label->setPixmap(mypix);
    ui->label->setPixmap(mypix.scaled(230,230,Qt::KeepAspectRatio));
    QPixmap mix(":/EXTRAS/EXTRAS/logooooo.jpg");
    ui->labelparalogo->setPixmap(mix);
    ui->labelparalogo->setPixmap(mix.scaled(900,300,Qt::KeepAspectRatio));
    connect(ui->btnNuevacuenta,SIGNAL(released()),this,SLOT(ventanaCrearCuenta()));
    connect(ui->btnIngresar,SIGNAL(released()),this,SLOT(ventanaLogin()));
    connect(ui->btnVolver,SIGNAL(released()),this,SLOT(ventanaPrincipal()));
   cargarUsuariosArchivo();
}

void Registro::cargarUsuariosArchivo(){
    fstream archivo;
    archivo.open(direccionArch.toStdString(), ios::in);
    string texto;int cant=0;
    while (getline(archivo, texto)) {
        cant++;
    }
    archivo.close();
    cant=cant/6;
    archivo.open(direccionArch.toStdString(), ios::in);
    for(int i=0;i<cant;i++){
        QString nom,ape,correo,contrase,auxFecha,auxfoto;
        getline(archivo, texto);nom=QString::fromStdString(texto);
        getline(archivo, texto);ape=QString::fromStdString(texto);
        getline(archivo, texto);correo=QString::fromStdString(texto);
        getline(archivo, texto);contrase=QString::fromStdString(texto);
        getline(archivo, texto);auxFecha=QString::fromStdString(texto);
        getline(archivo, texto);auxfoto=QString::fromStdString(texto);

        Usuario<QString> aux(nom,ape,correo,contrase,auxFecha,auxfoto);
        lista->addLast(aux);
    }
    archivo.close();
}

Registro::~Registro()
{
    delete ui;
}

void Registro::ventanaCrearCuenta(){
    QPixmap auxp(":/EXTRAS/EXTRAS/userdesc.jpg");
    ui->label->setPixmap(auxp);
     ui->label->setPixmap(auxp.scaled(230,230,Qt::KeepAspectRatio));
    ui->stackedWidget->setCurrentIndex(0);
}
void Registro::ventanaPrincipal(){
    ui->stackedWidget->setCurrentIndex(1);
}

void Registro::ventanaLogin(){
    QString auxcorreo=ui->tbxIngresCorr->text();
    QString auxcontra=ui->tbxIngresaContra->text();

    bool correcto=false;
    int pos;
    for(int i=0;i<lista->getTam();++i){
        if((lista->getPos(i).getCorreo())==auxcorreo && (lista->getPos(i).getContrasena())==auxcontra){
            correcto=true;pos=i; break;
        }
    }
    if(correcto){
        lista->getPos(pos).getPerfil()->show();
        ui->tbxIngresaContra->setText("");
        ui->tbxIngresCorr->setText("");
    }else{
        QMessageBox::information(this,tr("Advertencia"),tr("Contraseña o correo electrónico incorrecto"));
    }
}

void Registro::on_btnRegistrarse_clicked(){
    QString nom=ui->tbxNombre->text();
    QString ape=ui->tbxApellido->text();
    QString correo=ui->tbxCorreo->text();
    QString contrase=ui->tbxContra->text();
    string fecha="";
    fecha+= (ui->boxDia->text()).toLocal8Bit().constData(); fecha+="/";
    fecha+= (ui->boxMes->text()).toLocal8Bit().constData();fecha+="/";
    fecha+= (ui->boxA->text()).toLocal8Bit().constData();
    QString auxFecha=QString::fromUtf8(fecha.c_str());;
    QString aux=ui->tbxCorreo->text();

   bool valido=false;
   for (int i=0;i<aux.size() ;i++ ) {
       if(aux.at(i)==char(64)){
           for (int j=i;j<aux.size();j++ ) {
                if(aux.at(j)=='.') valido=true;
           }
       }
   }

   if(valido==false){
       ui->tbxCorreo->setText("");
       QMessageBox::information(this,tr("Advertencia"),tr("Ingresa un correo electrónico real"));
   }else{
       for(int i=0;i<lista->getTam();i++){
           if(lista->getPos(i).getCorreo()==correo){
               valido= false;
                QMessageBox::information(this,tr("Advertencia"),tr("El correo electrónico ya ha sido usado"));
           }
       }
   }

   if(ui->tbxNombre->text()!="" && ui->tbxApellido->text()!="" && valido){
        Usuario<QString> nuevo(nom,ape,correo,contrase,auxFecha,auxfoto);
        lista->addLast(nuevo);
        ui->tbxNombre->setText("");
        ui->tbxApellido->setText("");
        ui->tbxCorreo->setText("");
        ui->tbxContra->setText("");
        ui->btnVolver->click();

        ofstream archivo;
        archivo.open(direccionArch.toStdString(), ios::out);
        for(int i=0;i<lista->getTam();i++){
            archivo<<lista->getPos(i).getNombre().toStdString()<<endl;
            archivo<<lista->getPos(i).getApellido().toStdString()<<endl;
            archivo<<lista->getPos(i).getCorreo().toStdString()<<endl;
            archivo<<lista->getPos(i).getContrasena().toStdString()<<endl;
            archivo<<lista->getPos(i).getFecha().toStdString()<<endl;
            archivo<<lista->getPos(i).getPhoto().toStdString()<<endl;

        }
        archivo.close();
   }
}


void Registro::on_btnCargarImg_clicked()
{   QString filename;
    filename=QFileDialog::getOpenFileName(this,tr("Choose"),"",tr("Images(*.png *.jpg *.jpeg *.bmp *.gif)"));
    if(QString::compare(filename,QString())!=0){
        QImage image;
        bool valid=image.load(filename);
        if(valid){
            image=image.scaledToWidth(ui->label->width(),Qt::SmoothTransformation);
            ui->label->setPixmap(QPixmap::fromImage(image));
            auxfoto=filename;
        }
    }

}

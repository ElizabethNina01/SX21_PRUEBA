#include "mainwindow.h"
#include "ui_mainwindow.h"
using namespace std;
MainWindow::MainWindow(QWidget *parent, QString fotoperfil, QString nombre, QString apellido, QString cumplea)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap mypix(":/EXTRAS/EXTRAS/LOGODIMLIM.jpg");
    ui->label_2->setPixmap(mypix);
    ui->label_2->setPixmap(mypix.scaled(330,430,Qt::KeepAspectRatio));
    ui->stackedWidget->setCurrentIndex(0);
    QPixmap aux(fotoperfil);
    ui->lblYo->setPixmap(aux);
    ui->lblNombreUsu->setText("Nombre: " +nombre);
    ui->lblApellido->setText("Apellido: "+apellido);
    ui->lblNacimiento->setText("Fecha de naciemiento: "+cumplea);
    ui->lblCantAmigos->setText("Cantidad de amigos: "+ QString::number(amigos->size()));
    connect(ui->btnExplorar,SIGNAL(released()),this,SLOT(MostrarFake()));
    connect(ui->btnFake_next,SIGNAL(released()),this,SLOT(NextFake()));
    connect(ui->btnAmigoMiPerfil,SIGNAL(released()),this,SLOT(MostrarPerfil()));
    connect(ui->btnMiPerfilFake,SIGNAL(released()),this,SLOT(MostrarPerfil()));
     connect(ui->btnMisAmigos,SIGNAL(released()),this,SLOT(MostrarAmigo()));
    connect(ui->btnFake_agregar,SIGNAL(released()),this,SLOT(AgregarAmigo()));
     connect(ui->btnCerrarSesion,SIGNAL(released()),this,SLOT(CerrarSesion()));
    ColaDeFakes();
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::CerrarSesion(){

    this->close();

}
void MainWindow::ColaDeFakes(){
    string nombres[10]={"Nicole","Juan","Caro","Sol","Daniel","Santi","Thiago","Georgi","Zoey","Stef"};
    string trabajos[10]={"Estudiante","Ingeniero","Chef","Programador","Administrador","Chofer","Streamer"," Futbolista","Arquitecto","Abogado"};
    string estados[4]={"Soltero y feliz","Casado","En una relación","Es complicado"};
    string hobbys[5]={"Tocar la guitarra","Jugar al futbol","Las matematicas","La juerga","Comer y comer"};

   for(int i=1;i<=50;i++){
       string nombre = nombres[rand() % 9];
       string trabajo = trabajos[rand() % 10];
       string estado = estados[rand() % 4];
       string hobby = hobbys[rand() % 5];
       int edad = 15 + rand() % 25;
       long long numero = 932921988 + rand() % 999999999;
       string photo = ":/Perfiles Fake/PerfilesFake/" + to_string(i) + ".jpg";
      Persona<string,int>*new_fake = new Persona<string,int>(nombre, trabajo, estado, hobby,edad,numero, photo);
       fakes->push(new_fake);
   }
}

 void MainWindow::MostrarFake(){
       ui->stackedWidget->setCurrentIndex(1);
       if(!fakes->empty()){
       QString nombre =  fakes->front()->date->getNombre().c_str();
       QString trabajo = fakes ->front()->date->getTrabajo().c_str()  ;
       QString estado =  fakes ->front()->date->getEstado().c_str()   ;
       QString hobby =   fakes ->front()->date->getHobby().c_str()    ;
       QString anios =    to_string(fakes ->front()->date->getEdad()).c_str()     ;
       QString number = to_string( fakes ->front()->date->getNumero()).c_str()   ;
       QString photo =   fakes ->front()->date->getFoto().c_str()   ;

       ui->lblFake_nombre->setText("Nombre: "+nombre);
       ui->lblFake_trabajo->setText("Trabajo: "+trabajo);
       ui->lblFake_estado->setText("Estado: "+estado);
       ui->lblFake_hobby->setText("Hobby: "+hobby);
       ui->lblFake_edad->setText("Edad: "+anios);
       ui->lblNumero_fake->setText("Número: "+number);
       QPixmap aux(photo);
       ui->lblFake_foto->setPixmap(aux);
       }
  }

   void MainWindow::AgregarAmigo(){
     if(!fakes->empty())
     amigos->Add(fakes->front()->date);
     MostrarLista();
     fakes->pop();
     ui->btnFake_next->click();
   }
   void MainWindow::NextFake(){
             fakes->pop();
             MostrarFake();
   }
   void MainWindow::MostrarAmigo(){
        ui->stackedWidget->setCurrentIndex(2);
       if(!amigos->empty()){
       QString nombre =   amigos->getActual()->date->getNombre().c_str();
       QString trabajo =amigos->getActual()->date->getTrabajo().c_str();
       QString estado = amigos->getActual()->date->getEstado().c_str();
       QString hobby =  amigos->getActual()->date->getHobby().c_str();
       QString anios =  to_string(amigos->getActual()->date->getEdad()).c_str();
       QString number = to_string(amigos->getActual()->date->getNumero()).c_str();
       QString photo =amigos->getActual()->date->getFoto().c_str();
       ui->lblAmigoNombre->setText("Nombre: "+nombre);
       ui->lblAmigoTrabajo->setText("Trabajo: "+trabajo);
       ui->lblAmigoEstado->setText("Estado: "+estado);
       ui->lblAmigoHobby->setText("Hobby: "+hobby);
       ui->lblAmigoEdad->setText("Edad: "+anios);
        ui->lblAmigoNumero->setText("Numero: "+number);
       QPixmap aux(photo);
       ui->lblAmigoFoto->setPixmap(aux);
       }
       else {
           ui->lblAmigoNombre->setText(" ");
           ui->lblAmigoTrabajo->setText(" ");
           ui->lblAmigoEstado->setText(" ");
           ui->lblAmigoHobby->setText(" ");
           ui->lblAmigoEdad->setText(" ");
           ui->lblAmigoNumero->setText(" ");
           QPixmap aux(":/EXTRAS/EXTRAS/sinamigos.jpg");
           ui->lblAmigoFoto->setPixmap(aux);
       }
   }

void MainWindow::on_lblAmigoSiguiente_released()
{
    if(!amigos->empty()){
    amigos->Next();
    MostrarAmigo();
    }
}

void MainWindow::on_lblAmigoVolver_released()
{   if(!amigos->empty()){
    amigos->Back();
    MostrarAmigo();}
}
void MainWindow::MostrarPerfil(){
        ui->lblCantAmigos->setText("Cantidad de amigos: "+ QString::number(amigos->size()));
    ui->stackedWidget->setCurrentIndex(0);
}
 void MainWindow::MostrarLista(){
     ui->listAmigos->clear();
     amigos->LoveLambda([&](Persona<string,int>*a) {
     QString nombre= a->getNombre().c_str();
     QString edad=to_string(a->getEdad()).c_str();
     ui->listAmigos->addItem(nombre+"  "+edad);
     });
 }
 void MainWindow::OrdenarLista(){
      QString opcion=ui->cboxOrden->currentText();
      if(opcion=="Nombre") 	amigos->sort<string>([](Persona<string, int>* r) { return r->getNombre(); });
      else if(opcion=="Edad") amigos->sort<int>([](Persona<string, int>* r) { return r->getEdad()*-1; });
      else if(opcion=="Estado")amigos->sort<string>([](Persona<string, int>* r) { return r->getEstado(); });
      else if(opcion=="Hobby")	amigos->sort<string>([](Persona<string, int>* r) { return r->getHobby(); });
      else if(opcion=="Trabajo")	amigos->sort<string>([](Persona<string, int>* r) { return r->getTrabajo();});
      else if(opcion=="Numero")	amigos->sort<int>([](Persona<string, int>* r) { return r->getNumero()*-1; });
      amigos->Again();

                       }

 void MainWindow:: ActualizarChat(){
     ui->textEditMensajes->clear();
     amigos->getActual()->date->getChat()->LoveLambda([&](string a) {
             QString aux= a.c_str();
             ui->textEditMensajes->append(aux+"\n");
         });
 }
void MainWindow::on_cboxOrden_currentIndexChanged(const QString &arg1)
{
    OrdenarLista();
    MostrarAmigo();
    MostrarLista();
}

void MainWindow::on_lblAmigoEliminar_released()
{
   if(!amigos->empty()){
//hay un bug aqui eh
    amigos->eliminate();
    MostrarLista();
    MostrarAmigo();
    }
}

void MainWindow::on_btnEnviarMensaje_released()
{    if(!amigos->empty()){
     ui->stackedWidget->setCurrentIndex(3);
     ActualizarChat();
    }
}



void MainWindow::on_btnSend_released()
{

    string aux= ui->lineMensaje->text().toStdString();
    amigos->getActual()->date->getChat()->Add(aux);
    ui->lineMensaje->setText(" ");
    ActualizarChat();

}

void MainWindow::on_VolverChat_released()
{
   ui->textEditMensajes->clear();
   ui->stackedWidget->setCurrentIndex(2);

}

void MainWindow::on_btnReactionSmile_released()
{

    if( fakes->front()->date->getSmile()==false){
        fakes->front()->date->setSmile(true);
        ui->btnReactionSmile->setStyleSheet("background-color:red");
        }
     else {
          fakes->front()->date->setSmile(false);
           ui->btnReactionSmile->setStyleSheet("background-color:white");

         }
}

void MainWindow::on_btnReactionHeart_clicked()
{

    if( fakes->front()->date->getHeart()==false){

        ui->btnReactionHeart->setStyleSheet("background-color:red");
        fakes->front()->date->setHeart(true);
        }
     else {
          fakes->front()->date->setHeart(false);
           ui->btnReactionHeart->setStyleSheet("background-color:white");
         }

}

void MainWindow::on_btnReactionLike_released()
{

    if( fakes->front()->date->getLike()==false){
        fakes->front()->date->setLike(true);
        ui->btnReactionLike->setStyleSheet("background-color:red");
        }
     else {
          fakes->front()->date->setLike(false);
           ui->btnReactionLike->setStyleSheet("background-color:white");

         }
}


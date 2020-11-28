#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include"Personas.h"
#include"Amigos.h"
#include<string>
#include<ctime>
#include<cstdlib>
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent, QString fotoperfil, QString nombre, QString apellido, QString cumplea);
    ~MainWindow();
    //funcion para almacenar las personas fake
    void ColaDeFakes();

    Personas<int>*fakes=new Personas<int>();

    Amigos<int, Persona<string, int>*>*amigos = new Amigos<int, Persona<string, int>*>;

private slots:
    void MostrarFake();
    void AgregarAmigo();
    void MostrarAmigo();
    void on_lblAmigoSiguiente_released();
    void on_lblAmigoVolver_released();
    void MostrarPerfil();
    void NextFake();
    void MostrarLista();
    void OrdenarLista();
    void on_cboxOrden_currentIndexChanged(const QString &arg1);
    void on_lblAmigoEliminar_released();
    void on_btnEnviarMensaje_released();
    void ActualizarChat();
    void on_btnSend_released();
    void on_VolverChat_released();
    void on_btnReactionSmile_released();
    void on_btnReactionHeart_clicked();
    void on_btnReactionLike_released();
void CerrarSesion();





private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H

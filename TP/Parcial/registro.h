#ifndef REGISTRO_H
#define REGISTRO_H
#include <QMainWindow>
#include "Usuarios.h"
#include"mainwindow.h"
QT_BEGIN_NAMESPACE
namespace Ui { class Registro; }
QT_END_NAMESPACE

class Registro : public QMainWindow
{
    Q_OBJECT

public:
    QString direccionArch;

    Usuarios<Usuario<QString>> *lista;
   QString auxfoto;
    Registro(QWidget *parent = nullptr);
    ~Registro();

private slots:

    void on_btnRegistrarse_clicked();

void ventanaPrincipal();
void ventanaCrearCuenta();
void on_btnCargarImg_clicked();
void ventanaLogin();
void cargarUsuariosArchivo();

private:
    Ui::Registro *ui;
};
#endif // REGISTRO_H

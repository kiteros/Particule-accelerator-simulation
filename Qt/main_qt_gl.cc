#include <QApplication>
#include <QWidget>
#include "glwidget.h"

int main(int argc, char* argv[])
{

    //On aimerait premièrement ouvrir une fenetre de choix

    QApplication a(argc, argv);
    QWidget choice_window;
    choice_window.resize(320, 240);
    choice_window.show();
    choice_window.setWindowTitle(
    QApplication::translate("toplevel", "Accelerateur"));


    //GLWidget w;
    //.w.show();

  return a.exec();
}

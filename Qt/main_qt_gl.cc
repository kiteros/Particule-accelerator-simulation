#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include "glwidget.h"
#include "glwidget_menu.h"



int main(int argc, char* argv[])
{


    QApplication a(argc, argv);

    GLWidgetMenu menu;
    menu.show();

    GLWidget gl;

    gl.show();
    gl.resize(1000, 500);

    /*QWidget choice_window;
    choice_window.resize(600, 400);
    QPushButton *button = new QPushButton("Hello World", &choice_window);
    button->setGeometry(10, 10, 80, 30);
    choice_window.show();
    choice_window.setWindowTitle(
    QApplication::translate("toplevel", "Accelerateur"));*/






  return a.exec();
}

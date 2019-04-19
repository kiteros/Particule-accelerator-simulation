#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include "glwidget.h"
#include "glwidget_menu.h"
#include "elements.h"
#include "accelerateur.h"


int main(int argc, char* argv[])
{


    QApplication a(argc, argv);

    //GLWidgetMenu menu;
    //menu.show();

    GLWidget gl;


    VueOpenGL* vue = gl.get_GL_vu();
   // Accelerateur LHC = Accelerateur(vue, "LHC");
        Quadrupoles Q1(Vecteur3D(3,2,0),Vecteur3D(3,1,0),0.1,1.2,nullptr);
        Quadrupoles Q2(Vecteur3D(3,0,0),Vecteur3D(3,-1,0),0.1,-1.2,nullptr);
        Quadrupoles Q3(Vecteur3D(2,-3,0),Vecteur3D(1,-3,0),0.1,1.2,nullptr);
        Quadrupoles Q4(Vecteur3D(0,-3,0),Vecteur3D(-1,-3,0),0.1,-1.2,nullptr);
        Quadrupoles Q5(Vecteur3D(-3,-2,0),Vecteur3D(-3,-1,0),0.1,1.2,nullptr);
        Quadrupoles Q6(Vecteur3D(-3,0,0),Vecteur3D(-3,1,0),0.1,-1.2,nullptr);
        Quadrupoles Q7(Vecteur3D(-2,3,0),Vecteur3D(-1,3,0),0.1,1.2,nullptr);
        Quadrupoles Q8(Vecteur3D(0,3,0),Vecteur3D(1,3,0),0.1,-1.2,nullptr);


        Element_droit E1(Vecteur3D(3,1,0),Vecteur3D(3,0,0),0.1,nullptr);
        Element_droit E2(Vecteur3D(3,-1,0),Vecteur3D(3,-2,0),0.1,nullptr);
        Element_droit E3(Vecteur3D(1,-3,0),Vecteur3D(0,-3,0),0.1,nullptr);
        Element_droit E4(Vecteur3D(-1,-3,0),Vecteur3D(-2,-3,0),0.1,nullptr);
        Element_droit E5(Vecteur3D(-3,-1,0),Vecteur3D(-3,0,0),0.1,nullptr);
        Element_droit E6(Vecteur3D(-3,1,0),Vecteur3D(-3,2,0),0.1,nullptr);
        Element_droit E7(Vecteur3D(-1,3,0),Vecteur3D(0,3,0),0.1,nullptr);
        Element_droit E8(Vecteur3D(1,3,0),Vecteur3D(2,3,0),0.1,nullptr);

        Dipole D1(Vecteur3D(3,-2,0),Vecteur3D(2,-3,0),0.1,1,5.89158,vue);
        Dipole D2(Vecteur3D(-2,-3,0),Vecteur3D(-3,-2,0),0.1,1,5.89158,vue);
        Dipole D3(Vecteur3D(-3,2,0),Vecteur3D(-2,3,0),0.1,1,5.89158,vue);
        Dipole D4(Vecteur3D(2,3,0),Vecteur3D(3,2,0),0.1,1,5.89158,vue);

        Q1.set_element_suivant(&E1);
        E1.set_element_suivant(&Q2);
        Q2.set_element_suivant(&E2);
        E2.set_element_suivant(&D1);
        D1.set_element_suivant(&Q3);
        Q3.set_element_suivant(&E3);
        E3.set_element_suivant(&Q4);
        Q4.set_element_suivant(&E4);
        E4.set_element_suivant(&D2);
        D2.set_element_suivant(&Q5);
        Q5.set_element_suivant(&E5);
        E5.set_element_suivant(&Q6);
        Q6.set_element_suivant(&E6);
        E6.set_element_suivant(&D3);
        D3.set_element_suivant(&Q7);
        Q7.set_element_suivant(&E7);
        E7.set_element_suivant(&Q8);
        Q8.set_element_suivant(&E8);
        E8.set_element_suivant(&D4);
        D4.set_element_suivant(&Q1);

        vector<Element*> v{ &Q1,&Q2,&Q3,&Q4,&Q5,&Q6,&Q7,&Q8,&D1,&D2,&D3,&D4,&E1,&E2,&E3,&E4,&E5,&E6,&E7,&E8} ;
        gl.get_acc()->add_elements(v);
        //gl.set_ele(&D2);

        gl.show();
        gl.resize(1000, 500);

    //gl.affiche_accelerateur(&LHC);

    /*QWidget choice_window;
    choice_window.resize(600, 400);
    QPushButton *button = new QPushButton("Hello World", &choice_window);
    button->setGeometry(10, 10, 80, 30);
    choice_window.show();
    choice_window.setWindowTitle(
    QApplication::translate("toplevel", "Accelerateur"));*/






  return a.exec();
}

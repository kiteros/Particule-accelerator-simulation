#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include "glwidget.h"
#include "glwidget_menu.h"
#include "elements.h"
#include "accelerateur.h"
#include "faisceau.h"
#include "constantes.h"

int main(int argc, char* argv[])
{


    QApplication a(argc, argv);

    //GLWidgetMenu menu;
    //menu.show();

    GLWidget gl;

    double rayon = constantes::rayon;

    constantes::load();

    VueOpenGL* vue = gl.get_GL_vu();

    Particle proton = Particle(0.938272, 1.60217653e-19, Vecteur3D(0,-2.64754e+08,0), Vecteur3D(2.8,0,0));
    Particle electron = Particle(0.938272, 1.60217653e-19, Vecteur3D(0,-2.64754e+08,0), Vecteur3D(3.01,0,0));

    FODO F1(Vecteur3D(0,0,0),Vecteur3D(0,4,0),0.5,nullptr,1,1.2);
    Quadrupoles Q1(Vecteur3D(3,2,0),Vecteur3D(3,1,0),rayon,1.2,nullptr);
    Quadrupoles Q2(Vecteur3D(3,0,0),Vecteur3D(3,-1,0),rayon,-1.2,nullptr);
    Quadrupoles Q3(Vecteur3D(2,-3,0),Vecteur3D(1,-3,0),rayon,1.2,nullptr);
    Quadrupoles Q4(Vecteur3D(0,-3,0),Vecteur3D(-1,-3,0),rayon,-1.2,nullptr);
    Quadrupoles Q5(Vecteur3D(-3,-2,0),Vecteur3D(-3,-1,0),rayon,1.2,nullptr);
    Quadrupoles Q6(Vecteur3D(-3,0,0),Vecteur3D(-3,1,0),rayon,-1.2,nullptr);
    Quadrupoles Q7(Vecteur3D(-2,3,0),Vecteur3D(-1,3,0),rayon,1.2,nullptr);
    Quadrupoles Q8(Vecteur3D(0,3,0),Vecteur3D(1,3,0),rayon,-1.2,nullptr);


    Element_droit E1(Vecteur3D(3,1,0),Vecteur3D(3,0,0),rayon,nullptr);
    Element_droit E2(Vecteur3D(3,-1,0),Vecteur3D(3,-2,0),rayon,nullptr);
    Element_droit E3(Vecteur3D(1,-3,0),Vecteur3D(0,-3,0),rayon,nullptr);
    Element_droit E4(Vecteur3D(-1,-3,0),Vecteur3D(-2,-3,0),rayon,nullptr);
    Element_droit E5(Vecteur3D(-3,-1,0),Vecteur3D(-3,0,0),rayon,nullptr);
    Element_droit E6(Vecteur3D(-3,1,0),Vecteur3D(-3,2,0),rayon,nullptr);
    Element_droit E7(Vecteur3D(-1,3,0),Vecteur3D(0,3,0),rayon,nullptr);
    Element_droit E8(Vecteur3D(1,3,0),Vecteur3D(2,3,0),rayon,nullptr);

    Dipole D1(Vecteur3D(3,-2,0),Vecteur3D(2,-3,0),rayon,1,5.89158,vue);
    Dipole D2(Vecteur3D(-2,-3,0),Vecteur3D(-3,-2,0),rayon,1,5.89158,vue);
    Dipole D3(Vecteur3D(-3,2,0),Vecteur3D(-2,3,0),rayon,1,5.89158,vue);
    Dipole D4(Vecteur3D(2,3,0),Vecteur3D(3,2,0),rayon,1,5.89158,vue);

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
    gl.get_acc()->add_particles(&proton);
    gl.get_acc()->set_name("LHC");
    //Faisceau()
    Faisceau* f1 = new Faisceau_P14(1000, 1, 1.60217653e-19, 0.938272, 2.64745e+8,nullptr,gl.get_acc(),0.5,Vecteur3D(0.0,0.2,1));
    Faisceau* f2 = new Faisceau_P14(1000, 1, -1.60217653e-19, 0.938272, -2.64745e+8,nullptr,gl.get_acc(),0.7);
    //Faisceau* f = new Faisceau(1000,50,1.60217653e-19,0.938272,2.64745e+8, nullptr,gl.get_acc());

    //type Faisceau est le Faisceau normal qui n'a pas des interactions entre les particules
    Faisceau* f = new Faisceau(40,1,1.60217653e-19,0.938272,2.64745e+8, nullptr,gl.get_acc());

    //type Faisceau_P13 est herite de type Faisceau et implimente la methode de calcule les interations entre particules de exercise 13
    //Faisceau* f = new Faisceau_P13(40,1,1.60217653e-19,0.938272,2.64745e+8, nullptr,gl.get_acc());

    //type Faisceau_P14 est herite de type Faisceau et implimente la methode de calcule les interations entre particules de exercise 14
    //Faisceau* f = new Faisceau_P14(40,1,1.60217653e-19,0.938272,2.64745e+8, nullptr,gl.get_acc());

    gl.get_acc()->add_faisceau(f1);
    gl.get_acc()->add_faisceau(f2);

    gl.showMaximized();

    return a.exec();
}

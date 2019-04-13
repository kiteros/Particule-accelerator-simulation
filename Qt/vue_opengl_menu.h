#ifndef VUEOPENGLMENU_H
#define VUEOPENGLMENU_H

#include <QOpenGLShaderProgram> // Classe qui regroupe les fonctions OpenGL liées aux shaders
#include <QMatrix4x4>
#include "supportadessin.h"
#include "accelerateur.h"
#include "elements.h"
#include <QOpenGLFunctions>

class VueOpenGLMenu : protected QOpenGLFunctions {
 public:
  // méthode(s) de dessin (héritée(s) de SupportADessin)
    virtual void dessine(Accelerateur const& a_dessiner);
    virtual void dessine(Element const& a_dessiner);
    virtual void dessine();

    ~VueOpenGLMenu();


  // méthodes de (ré-)initialisation
  void init();
  void initializePosition();

  // méthode set
  void setProjection(QMatrix4x4 const& projection)
  { prog.setUniformValue("projection", projection); }

  // Méthodes set
  void translate(double x, double y, double z);
  void rotate(double angle, double dir_x, double dir_y, double dir_z);
  
  // méthode utilitaire offerte pour simplifier
  void dessineButton(QMatrix4x4 const& point_de_vue = QMatrix4x4() );

 private:
  // Un shader OpenGL encapsulé dans une classe Qt
  QOpenGLShaderProgram prog;

  // Caméra
  QMatrix4x4 matrice_vue;

  GLuint textureDeChat;
  GLuint textureFractale;
};

#endif

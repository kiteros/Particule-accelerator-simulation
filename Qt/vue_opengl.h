#ifndef VUEOPENGL_H
#define VUEOPENGL_H

#include <QOpenGLShaderProgram> // Classe qui regroupe les fonctions OpenGL liées aux shaders
#include <QMatrix4x4>
#include <QOpenGLFunctions>
#include "supportadessin.h"
#include "accelerateur.h"
#include "elements.h"
#include "glcylindre.h"
#include "glsphere.h"

class VueOpenGL : public SupportADessin {
 public:
  // méthode(s) de dessin (héritée(s) de SupportADessin)
  virtual void dessine(Accelerateur const& a_dessiner) override;
  virtual void dessine(Element* a_dessiner) override;
  virtual void dessine(Faisceau const& a_dessiner) override;
  virtual void dessine() override;

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
  void dessineCube(QMatrix4x4 const& point_de_vue = QMatrix4x4() );
  void dessineCylindre(Glcylindre cylindre,QMatrix4x4 const& point_de_vue,
                     double rouge = 1.0, double vert = 1.0, double bleu = 1.0);
  void dessineSphere(GLSphere sphere, QMatrix4x4 const& point_de_vue,
                     double rouge = 1.0, double vert = 1.0, double bleu = 1.0);
  //Couleur calcul_couleur(Particle *);
  void dessineAccelerateur(Accelerateur const * acc,QMatrix4x4 const& point_de_vue);
  void dessineAxes(QMatrix4x4 const& point_de_vue, bool en_couleur = true);

 private:
  // Un shader OpenGL encapsulé dans une classe Qt
  QOpenGLShaderProgram prog;

  // Caméra
  QMatrix4x4 matrice_vue;


};

#endif

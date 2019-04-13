#include "vue_opengl_menu.h"
#include "vertex_shader_menu.h" // Identifiants Qt de nos différents attributs
#include "accelerateur.h"
#include "elements.h"
#include <QOpenGLShaderProgram> // Classe qui regroupe les fonctions OpenGL liées aux shaders
#include <QOpenGLFunctions>
#include <QGLContext>

// ======================================================================
void VueOpenGLMenu::dessine()
{
   // Dessine le 1er cube (à l'origine)
  dessineButton();

}

VueOpenGLMenu::~VueOpenGLMenu()
{
  // Libère la mémoire des textures

  QGLContext* context =  const_cast<QGLContext*>(QGLContext::currentContext());

  context->deleteTexture(textureDeChat);
}

void VueOpenGLMenu::dessine(Accelerateur const& a_dessiner)
{

}

void VueOpenGLMenu::dessine(Element const& a_dessiner)
{

}



// ======================================================================
void VueOpenGLMenu::init()
{
  /* Initialise notre vue OpenGL.
   * Dans cet exemple, nous créons et activons notre shader.
   *
   * En raison du contenu des fichiers *.glsl, le shader de cet exemple
   * NE permet QUE de dessiner des primitives colorées
   * (pas de textures, brouillard, reflets de la lumière ou autres).
   *
   * Il est séparé en deux parties VERTEX et FRAGMENT.
   * Le VERTEX :
   * - récupère pour chaque sommet des primitives de couleur (dans
   *     l'attribut couleur) et de position (dans l'attribut sommet)
   * - multiplie l'attribut sommet par les matrices 'vue_modele' et
   *     'projection' et donne le résultat à OpenGL
   *   - passe la couleur au shader FRAGMENT.
   *
   * Le FRAGMENT :
   *   - applique la couleur qu'on lui donne
   */

    initializeOpenGLFunctions();

  prog.addShaderFromSourceFile(QOpenGLShader::Vertex,   ":/vertex_shader_menu.glsl");
  prog.addShaderFromSourceFile(QOpenGLShader::Fragment, ":/fragment_shader_menu.glsl");

  /* Identifie les deux attributs du shader de cet exemple
   * (voir vertex_shader.glsl).
   *
   * L'attribut identifié par 0 est particulier, il permet d'envoyer un
   * nouveau "point" à OpenGL
   *
   * C'est pourquoi il devra obligatoirement être spécifié et en dernier
   * (après la couleur dans cet exemple, voir plus bas).
   */

  prog.bindAttributeLocation("sommet",  SommetId);
  prog.bindAttributeLocation("coordonnee_texture", CoordonneeTextureId);

  // Compilation du shader OpenGL
  prog.link();

  // Activation du shader
  prog.bind();

  /* Activation du "Test de profondeur" et du "Back-face culling"
   * Le Test de profondeur permet de dessiner un objet à l'arrière-plan
   * partielement caché par d'autres objets.
   *
   * Le Back-face culling consiste à ne dessiner que les face avec ordre
   * de déclaration dans le sens trigonométrique.
   */
  glEnable(GL_DEPTH_TEST);
  glEnable(GL_CULL_FACE);

  // Préparation d'une première texture à partir d'une image (cat.jpeg).
  QGLContext* context =  const_cast<QGLContext*>(QGLContext::currentContext());
  textureDeChat = context->bindTexture(QPixmap(":/start.jpg"), GL_TEXTURE_2D);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_MIRRORED_REPEAT);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_MIRRORED_REPEAT);
  // Autres variantes au lieu de GL_MIRRORED_REPEAT : GL_REPEAT, GL_CLAMP_TO_EDGE


  initializePosition();
}

// ======================================================================
void VueOpenGLMenu::initializePosition()
{
  // position initiale
  matrice_vue.setToIdentity();
  matrice_vue.translate(0.0, 0.0, -4.0);
}

// ======================================================================
void VueOpenGLMenu::translate(double x, double y, double z)
{
  /* Multiplie la matrice de vue par LA GAUCHE.
   * Cela fait en sorte que la dernière modification apportée
   * à la matrice soit appliquée en dernier (composition de fonctions).
   */
  QMatrix4x4 translation_supplementaire;
  translation_supplementaire.translate(x, y, z);
  matrice_vue = translation_supplementaire * matrice_vue;
}

// ======================================================================
void VueOpenGLMenu::rotate(double angle, double dir_x, double dir_y, double dir_z)
{
  // Multiplie la matrice de vue par LA GAUCHE
  QMatrix4x4 rotation_supplementaire;
  rotation_supplementaire.rotate(angle, dir_x, dir_y, dir_z);
  matrice_vue = rotation_supplementaire * matrice_vue;
}

// ======================================================================
void VueOpenGLMenu::dessineButton (QMatrix4x4 const& point_de_vue)
{
  prog.setUniformValue("vue_modele", matrice_vue * point_de_vue);

  /// Indique au shader quel numéro de texture il doit utiliser (0,1,2,...)
  prog.setUniformValue("textureId", 0);

  /// Attribut la texture 'textureDeChat' à la texture numéro 0 du shader
    QOpenGLFunctions *glFuncs = QOpenGLContext::currentContext()->functions();
    glFuncs->glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, textureDeChat);

  glBegin(GL_QUADS);


  prog.setAttributeValue(CoordonneeTextureId, 0.0, 1.0);
  prog.setAttributeValue(SommetId, -1.0, 0.4, 1.0);
  prog.setAttributeValue(CoordonneeTextureId, 0.0, 0.0);
  prog.setAttributeValue(SommetId, -1.0, -0.4, 1.0);
  prog.setAttributeValue(CoordonneeTextureId, 1.0, 0.0);
  prog.setAttributeValue(SommetId, +1.0, -0.4, 1.0);
  prog.setAttributeValue(CoordonneeTextureId, 1.0, 1.0);
  prog.setAttributeValue(SommetId, +1.0, 0.4, 1.0);



  glEnd();
}

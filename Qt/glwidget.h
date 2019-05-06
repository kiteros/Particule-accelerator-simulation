#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <QOpenGLWidget>        // Classe pour faire une fenêtre OpenGL
#include <QTime>            // Classe pour gérer le temps
#include "vue_opengl.h"
#include "accelerateur.h"

class GLWidget : public QOpenGLWidget
{
    public:

        GLWidget(QWidget* parent = nullptr)
            : QOpenGLWidget(parent), acc(&vue),ele(nullptr)
        {}

        void affiche_accelerateur(Accelerateur* acc);
        void set_ele(Element* e) { ele = e;}
        void add(Particle* p){}

        VueOpenGL* get_GL_vu(){return &vue;}
        Accelerateur* get_acc() {return &acc;}

        virtual ~GLWidget() {}
        virtual void resizeGL(int width, int height) override;

private:

  virtual void initializeGL() override;
  virtual void paintGL() override;
  virtual void keyPressEvent(QKeyEvent* event) override;
  virtual void timerEvent(QTimerEvent* event) override;

  void pause();

  VueOpenGL vue;
  QTime chronometre;

  int timerId;

  Accelerateur acc;
  Element* ele;

};

#endif // GLWIDGET_H

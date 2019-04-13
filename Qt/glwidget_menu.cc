#include <QKeyEvent>
#include <QTimerEvent>
#include <QMatrix4x4>
#include "glwidget_menu.h"
#include "glwidget.h"

// ======================================================================
void GLWidgetMenu::initializeGL()
{
  vue.init();
  timerId = startTimer(20);
}

// ======================================================================
void GLWidgetMenu::resizeGL(int width, int height)
{
  /* On commance par dire sur quelle partie de la 
   * fenêtre OpenGL doit dessiner.
   * Ici on lui demande de dessiner sur toute la fenêtre.
   */
  glViewport(0, 0, width, height);

  /* Puis on modifie la matrice de projection du shader.
   * Pour ce faire on crée une matrice identité (constructeur 
   * par défaut), on la multiplie par la droite par une matrice
   * de perspective.
   * Plus de détail sur cette matrice
   *     http://www.songho.ca/opengl/gl_projectionmatrix.html
   * Puis on upload la matrice sur le shader à l'aide de la
   * méthode de la classe VueOpenGL
   */
  QMatrix4x4 matrice;
  matrice.perspective(70.0, qreal(width) / qreal(height ? height : 1.0), 1e-3, 1e5);
  vue.setProjection(matrice);
}

// ======================================================================
void GLWidgetMenu::paintGL()
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  vue.dessine();
}


// ======================================================================
void GLWidgetMenu::keyPressEvent(QKeyEvent* event)
{
  constexpr double petit_angle(5.0); // en degrés
  constexpr double petit_pas(1.0);

  switch (event->key()) {


  };

  update(); // redessine
}

void GLWidgetMenu::mousePressEvent(QMouseEvent* event)
{
  lastMousePosition = event->pos();
  if(lastMousePosition.x() >= 207 && lastMousePosition.x() <= 435
          && lastMousePosition.y() >= 195 && lastMousePosition.y() <= 286){
      std::cout << "in" << endl;
      //Lancer le nouveau GLWidget


      std::cout << "it should start" << endl;

  }else{
      std::cout << "out" << endl;
  }

}

void GLWidgetMenu::mouseMoveEvent(QMouseEvent* event)
{

}

// ======================================================================
void GLWidgetMenu::timerEvent(QTimerEvent* event)
{
  Q_UNUSED(event);

  double dt = chronometre.restart() / 1000.0;

  update();
}

// ======================================================================
void GLWidgetMenu::pause()
{
  if (timerId == 0) {
	// dans ce cas le timer ne tourne pas alors on le lance
	timerId = startTimer(20);
	chronometre.restart();
  } else {
	// le timer tourne alors on l'arrête
	killTimer(timerId);
	timerId = 0;
  }
}

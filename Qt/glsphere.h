#ifndef GLSPHERE_H
#define GLSPHERE_H

#include <QGLBuffer>
#include <QOpenGLShaderProgram>

#include "particle.h"

class GLSphere
{
public:
 GLSphere(Particle* p)
   : vbo(QGLBuffer::VertexBuffer), ibo(QGLBuffer::IndexBuffer), particle(p)
 {}

  void initialize(GLuint slices = 25, GLuint stacks = 25);

  void draw(QOpenGLShaderProgram& program, int attributeLocation);

  void bind();
  void release();

  Particle* get_particle(){return particle;}

private:
  QGLBuffer vbo, ibo;
  GLuint vbo_sz;
  GLuint ibo_sz[3];

  Particle* particle;
};

#endif // GLSPHERE_H

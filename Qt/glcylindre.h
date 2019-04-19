#ifndef GLCYLINDRE_H
#define GLCYLINDRE_H
#include <QGLBuffer>
#include <QOpenGLShaderProgram>
#include "elements.h"
class Glcylindre
{
public:
 Glcylindre(Element* ele)
   : vbo(QGLBuffer::VertexBuffer), ibo(QGLBuffer::IndexBuffer),element(ele)
 {}

  void initialize(GLuint slices = 10, GLuint stacks = 15);

  void draw(QOpenGLShaderProgram& program, int attributeLocation);

  void bind();
  void release();
  Element* get_element(){return element;}
private:
  QGLBuffer vbo, ibo;
  GLuint vbo_sz;
  GLuint ibo_sz[3];
  Element* element;
};
#endif // GLCYLINDRE_H

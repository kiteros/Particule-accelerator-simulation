#include "glcylindre.h"
#include <cmath>
double get_angle_with_y(Vecteur3D direction){
    double produit_y = (Vecteur3D(0,1,0)^direction)*Vecteur3D(0,0,1);

    std::cout<<"direction: "<<(Vecteur3D(0,1,0)^Vecteur3D(-1,0,0))*Vecteur3D(0,0,1)<<endl;
    double produit_x = (Vecteur3D(1,0,0)^direction )*Vecteur3D(0,0,1);
    double theta = 0;
    if ( produit_y > 0 ) {
        if(produit_x > 0)
        {theta = asin(produit_y);
            std::cout<<"py: "<<(produit_y)<<endl;
        std::cout<<"px>0 asin: "<<asin(produit_y)<<endl;}
        else
        {theta = M_PI - asin(produit_y);
            std::cout<<"px<=0 asin: "<<asin(produit_y)<<endl;
        }
    } else {
        if(produit_x > 0)
            theta = 2*M_PI - asin(abs(produit_y));
        else
            theta = M_PI + asin(abs(produit_y));
    }
    return theta;
}

void Glcylindre::initialize(GLuint slices, GLuint stacks)
{
  QVector<GLfloat> positions;

  QVector<GLuint> indices0;
  QVector<GLuint> indices1;
  QVector<GLuint> indices2;

  GLuint size(slices * stacks +2 );

  positions.reserve(3 * size);
  /*const double alpha(M_PI  / ( double(stacks-1)));
  const double beta(2.0*M_PI / double(slices));

  positions << 0.0 << 0.0 << 1.0;

  for (GLuint i(0); i <stacks; ++i) {
    for (GLuint j(0); j < slices; ++j) {
      float r_y = 1 - cos(i*alpha);
      float r_z = 1 - sin(i*alpha);
      float r_x = 0.0;
      float y = 0.3*sin(j*beta) ;
      float x = 0.3*cos(j*beta) ;
      float z = 0.0 ;
      float y_1 = y*cos(i*alpha) - z*sin(i*alpha);
      float z_1 = y * sin(i*alpha) + z*cos(i*alpha);
      float x_1 = x;
      float x_2 = x_1 + r_x;
      float y_2 = y_1 + r_y;
      float z_2 = z_1 + r_z;
      positions << x_2 << y_2 << z_2;
    }
  }

  positions << 0.0 << 2.0 << 1.0;*/



  if(element->get_courbure() != 0){
      Vecteur3D Cc = static_cast<Element_courbe*>(element)->get_centre_circle();
      double angle = abs(element->getLongeur()*element->get_courbure());
      const double alpha(angle / ( double(stacks-1)));
      const double beta(2.0*M_PI / double(slices));
      double rayon_ele = element->get_rayon();
      Vecteur3D X_in = element->get_in() - Cc;
      Vecteur3D X_out = element->get_out() - Cc;
      Vecteur3D start = Vecteur3D();
      bool start_with_in = false;
      if((X_in^X_out).get_z()>0) {
          start = X_in;
          start_with_in = true;
      } else {
          start = X_out;
          start_with_in = false;
      }
      if(start_with_in)
          positions << element->get_in().get_x() << element->get_in().get_y() << element->get_in().get_z();
      else
          positions << element->get_out().get_x() << element->get_out().get_y() << element->get_out().get_z();
      std::cout << "start: "<<~start<<endl;
      double angle_start = get_angle_with_y(~start);
      std::cout << "angle_start: "<<angle_start<<endl;
      double x_s = start.get_x();
      double y_s = start.get_y();
      double z_s = 0.0;
      for (GLuint i(0); i <stacks; ++i) {
        for (GLuint j(0); j < slices; ++j) {
          double theta = angle_start + i*alpha;
          //std::cout << "theta" << theta <<endl;
          float x_0 = x_s*cos(i*alpha) - y_s*sin(i*alpha);
          float y_0 = x_s*sin(i*alpha) + y_s*cos(i*alpha);
          float z_0 = z_s;

          float x_2 = x_0 + Cc.get_x();
          float y_2 = y_0 + Cc.get_y();
          float z_2 = z_0 + Cc.get_z();

          float z = rayon_ele*sin(j*beta) ;
          float y = rayon_ele*cos(j*beta) ;
          float x = 0.0 ;

          float z_1 = z;
          float x_1 = x*cos(theta) - y*sin(theta);
          float y_1 = x*sin(theta) + y*cos(theta);

          float x_3 = x_1 + x_2;
          float y_3 = y_1 + y_2;
          float z_3 = z_1 + z_2;

          positions << x_3 << y_3 << z_3;
        }
      }

      if(!start_with_in)
          positions << element->get_in().get_x() << element->get_in().get_y() << element->get_in().get_z();
       else
          positions << element->get_out().get_x() << element->get_out().get_y() << element->get_out().get_z();
  } else {
      positions << element->get_in().get_x() << element->get_in().get_y() << element->get_in().get_z();
       const double beta(2.0*M_PI / double(slices));
       double rayon_ele = element->get_rayon();
       double longeur = element->getLongeur();
       //std::cout << "longeur est" <<  (element->get_out()-element->get_in()).norme() <<endl;
       double d_s = longeur / (stacks -1);
       Vecteur3D direction =  ~(element->get_out()-element->get_in());
       std::cout << "direction est"<<direction <<endl;
       double theta = get_angle_with_y(direction);
       for (GLuint i(0); i <stacks; ++i) {
         for (GLuint j(0); j < slices; ++j) {
             Vecteur3D p = element->get_in() + i*direction*d_s;
             float z = rayon_ele*sin(j*beta) ;
             float y = rayon_ele*cos(j*beta) ;
             float x = 0.0 ;
             float z_1 = z;
             float x_1 = x*cos(theta+M_PI/2) - y*sin(theta+M_PI/2);
             float y_1 = x*sin(theta+M_PI/2) + y*cos(theta+M_PI/2);
             float x_2 = x_1 + p.get_x();
             float y_2 = y_1 + p.get_y();
             float z_2 = z_1 + p.get_z();
             positions << x_2 << y_2 << z_2;
         }
       }
       positions << element->get_out().get_x() << element->get_out().get_y() << element->get_out().get_z();
  }



  indices0.reserve(slices+2);
  for (GLuint i(0); i <= slices; ++i)
    indices0 << i;
  indices0 << 1;

  indices1.reserve((stacks-1) * 4 * slices);
  for (GLuint i(0); i < stacks-1; ++i) {
    for (GLuint j(0); j < slices; ++j) {
      indices1 << 1+i*slices+j;
      indices1 << 1+(i+1)*slices+j;
      indices1 << 1+(i+1)*slices+(j+1)%slices;
      indices1 << 1+i*slices+(j+1)%slices;
    }
  }

  indices2.reserve(slices+2);
  for (GLuint i(1); i <= slices+1; ++i)
    indices2 << size-i;
  indices2 << size-2;

  vbo_sz = 3 * size * sizeof(GLfloat);
  vbo.create();
  vbo.bind();
  vbo.allocate(positions.constData(), vbo_sz);
  vbo.release();

  ibo_sz[0] = indices0.size() * sizeof(GLuint);
  ibo_sz[1] = indices1.size() * sizeof(GLuint);
  ibo_sz[2] = indices2.size() * sizeof(GLuint);
  ibo.create();
  ibo.bind();
  ibo.allocate(ibo_sz[0] + ibo_sz[1] + ibo_sz[2]);
  ibo.write(0                    , indices0.constData(), ibo_sz[0]);
  ibo.write(ibo_sz[0]            , indices1.constData(), ibo_sz[1]);
  ibo.write(ibo_sz[0] + ibo_sz[1], indices2.constData(), ibo_sz[2]);
  ibo.release();
}

void Glcylindre::draw(QOpenGLShaderProgram& program, int attributeLocation)
{
  bind();

  program.setAttributeBuffer(attributeLocation, GL_FLOAT, 0, 3);
  program.enableAttributeArray(attributeLocation);

#define BUFFER_OFFSET(a) ((char*)nullptr + (a))

  glDrawElements(GL_TRIANGLE_FAN, ibo_sz[0] / sizeof(GLuint), GL_UNSIGNED_INT, BUFFER_OFFSET( 0                     ));
  glDrawElements(GL_QUADS       , ibo_sz[1] / sizeof(GLuint), GL_UNSIGNED_INT, BUFFER_OFFSET( ibo_sz[0]             ));
  glDrawElements(GL_TRIANGLE_FAN, ibo_sz[2] / sizeof(GLuint), GL_UNSIGNED_INT, BUFFER_OFFSET( ibo_sz[0] + ibo_sz[1] ));

  program.disableAttributeArray(attributeLocation);

  release();
}

void Glcylindre::bind()
{
  vbo.bind();
  ibo.bind();
}

void Glcylindre::release()
{
  ibo.release();
  vbo.release();
}

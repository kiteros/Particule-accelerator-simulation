#ifndef SUPPORTADESSIN_H
#define SUPPORTADESSIN_H

class Accelerateur;
class Element;

class SupportADessin
{
 public:
  virtual void dessine(Accelerateur const&) = 0;
  virtual void dessine(Element const&) = 0;
  virtual ~SupportADessin() = default;

  // A priori, on ne souhaite pas copier les SupportADessin
  private:
    //SupportADessin(SupportADessin const&) = delete;
    //SupportADessin& void operator=(SupportADessin const&) = delete ;
};

#endif // SUPPORTADESSIN_H

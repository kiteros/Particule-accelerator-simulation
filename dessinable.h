#ifndef DESSINABLE_H
#define DESSINABLE_H
#include "accelerateur.h"

class SupportADessin
{
 public:
    virtual void dessine(Accelerateur const&) = 0;
    virtual void dessine(Element const&) = 0;
    virtual void dessine(Accelerateur const&) = 0;
    virtual void dessine(Accelerateur const&) = 0;
    virtual void dessine(Accelerateur const&) = 0;
  // ... toute autre chose que vous voudriez dessiner...

  /* (AVANCÉ) A ajouter si l'UN de vos SupportADessin
   * nécessite son propre destructeur.
   */
  virtual ~SupportADessin() = default;

  // A priori, on ne souhaite pas copier les SupportADessin
  private:
    //SupportADessin(SupportADessin const&) = delete;
    //SupportADessin& void operator=(SupportADessin const&) = delete ;
};

class Dessinable
{
protected:
    SupportADessin * support_dessin;
public:
    Dessinable(SupportADessin*);
    virtual void dessine() = 0;

};

#endif // DESSINABLE_H

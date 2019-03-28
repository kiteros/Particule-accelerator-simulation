#ifndef DESSINABLE_H
#define DESSINABLE_H
#include "supportadessin.h"

class Dessinable
{
protected:
    SupportADessin * support;
public:
    Dessinable(SupportADessin*);
    virtual void dessine() = 0;
    virtual ~Dessinable() = default;
};



#endif // DESSINABLE_H

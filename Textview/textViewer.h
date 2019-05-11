#ifndef TEXTVIEWER_H
#define TEXTVIEWER_H
#include "supportadessin.h"
#include <iostream>

class TextViewer:public SupportADessin
{
public:
     TextViewer(std::ofstream& flot)
        : flot(flot)
      {}
      virtual ~TextViewer() override {}
      virtual void dessine(Faisceau const& a_dessiner) override;
      virtual void dessine(Element * a_dessiner) override;
      virtual void dessine(Accelerateur const& a_dessiner) override;
      virtual void dessine() override;
     private:
      std::ofstream& flot;

};

#endif // TEXTVIEWER_H

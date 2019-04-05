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
      virtual void dessine(Element const& a_dessiner) override;
      virtual void dessine(Accelerateur const& a_dessiner) override;
     private:
      std::ofstream& flot;

};

#endif // TEXTVIEWER_H

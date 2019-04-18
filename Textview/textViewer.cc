#include "textViewer.h"
#include "elements.h"
#include"accelerateur.h"

void TextViewer::dessine(Element * e)
{
    e->affiche(flot);
    return;
}

void TextViewer::dessine(Accelerateur const& a){
    a.affiche(flot); //la fonction ici doit etre une fonction virtuelle.
    return;
}

void TextViewer::dessine(){

    return;
}

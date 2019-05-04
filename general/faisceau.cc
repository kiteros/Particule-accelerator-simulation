#include "faisceau.h"
#include "accelerateur.h"
#include "elements.h"
#include  <math.h>
#include "constantes.h"
#include "vecteur3D.h"


Faisceau::Faisceau(int nombre_particules, int lambda, double charge, double mass,double vitesse,SupportADessin* support,Accelerateur* acc):
Dessinable (support),nombre_particules(nombre_particules),lambda(lambda)
{
    particules = vector<Particle*>();
    int N = nombre_particules/lambda;
    double pas = acc->getLongeur()/N;
    double rest = 0.5;
    int i = 0;
    Element* ele = acc->getElements().front();
    while(i < N){
        double longeur = ele->getLongeur();
            double longeur_accu = rest;
            while((longeur - longeur_accu) >= 0 && i<N){
                Vecteur3D position = ele->convertir_depuis_Abscisse_curviligne(longeur_accu);
                Vecteur3D V_1 = ele->get_vecteur_r(position)* vitesse;
                Vecteur3D V_2(V_1.get_y(),-V_1.get_x(),V_1.get_z());
                Particle* p = new Particle(lambda*mass,lambda*charge,V_1.rotation(constantes::e3, -M_PI/2),position);
                p->set_element_inside(ele);
                particules.push_back(p);
                longeur_accu = longeur_accu + pas;
                i = i + 1;
                std::cout <<"iiiiiiiiiiiiiiiiiii"<< N << endl;
                std::cout <<"kkkkkkkkkkkkkkkkkkk"<< i << endl;
            }
            rest = fabs(longeur - longeur_accu);
        ele = ele->get_element_suivant();
    }

    //Update_somme_attributs();
    std::cout <<"ddddeeeeeebbbbbbbbb"<< particules.size() << endl;

}

void Faisceau::bouger(double dt){
    for(auto p:particules){
        Element* current_element = p->get_element_inside();
        current_element->update_force(p,dt);
        //Update la position des particules
        p->move(dt);

        while(current_element->particle_out(*p)){
            p->set_element_inside(current_element->get_element_suivant());
            current_element = p ->get_element_inside();
        }

        //Check si elles touchent le bord et les supprimer en concécences
        if(current_element->touch_border(*p)){
            remove_particle(p);
            continue;
        }
    }

    std::cout << particules.size() << endl;
    std::cout << *particules[0] << endl;

    Update_somme_attributs();

}

void Faisceau::remove_particle(Particle * p){
    unsigned long size = particules.size();
    for (unsigned long i=0; i< size; i++) {
        if(particules[i] == p) {
            particules.erase(particules.begin() + i);
         }
    }
}


//set values to emittance, A11, A12, A22,and energie_moyenne.
void Faisceau::Update_somme_attributs(){
    double somme_r_2 = 0, somme_Vr_2=0, somme_r_Vr=0;
    double somme_z_2 = 0, somme_Vz_2=0, somme_z_Vz=0;
    int nb = 0;
    double somme_energie = 0;
    for(auto par:particules){
        Vecteur3D u;
        Element* ele = par->get_element_inside();
        u = ele->get_vecteur_r(par->getPosition());
        double r = par->getPosition()*u;
        double z = par->getPosition().get_z();
        double Vr = par->getSpeed()*u;
        double Vz = par->getSpeed().get_z();

        somme_r_2 = somme_r_2 + r*r;
        somme_Vr_2 = somme_Vr_2 + Vr*Vr;
        somme_r_Vr = somme_r_Vr + r*Vr;

        somme_z_2 = somme_z_2 + z*z;
        somme_Vz_2 = somme_Vz_2 + Vz*Vz;
        somme_z_Vz = somme_z_Vz + z*Vz;

        nb++;

        somme_energie = somme_energie + par->energy();

    }

    emittance_r = (somme_r_2/nb)*(somme_Vr_2/nb) - (somme_r_Vr/nb)*(somme_r_Vr/nb);
    emittance_z = (somme_z_2/nb)*(somme_Vz_2/nb) - (somme_z_Vz/nb)*(somme_z_Vz/nb);
    A11R = (somme_Vr_2/nb)/emittance_r;
    A12R = -(somme_r_Vr/nb)/emittance_r;
    A22R = (somme_r_2/nb)/emittance_r;

    A11Z = (somme_Vz_2/nb)/emittance_z;
    A12Z = -(somme_z_Vz/nb)/emittance_z;
    A22Z = (somme_z_2/nb)/emittance_z;

    energie_moyenne = somme_energie / nb;
}

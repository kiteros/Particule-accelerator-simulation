#include "constantes.h"
#include "vecteur3D.h"
#include <iostream>
#include <fstream>

using namespace std;

constantes::constantes(){}

const double constantes::light_speed = 299792458.0;
Vecteur3D constantes::e1 = Vecteur3D(1.0,0.0,0.0);
Vecteur3D constantes::e2 = Vecteur3D(0.0,1.0,0.0);
Vecteur3D constantes::e3 = Vecteur3D(0.0,0.0,1.0);
double constantes::time_step = 0.5;
double constantes::void_permitivity = 8.85e-12;

void constantes::load_file(){

    ofstream myfile ("example.txt");
      if (myfile.is_open())
      {
        myfile << "This is a line.\n";
        myfile << "This is another line.\n";
        myfile.close();
        cout << "its supposed to work" << endl;
      }
      else cout << "Unable to open file";
      /*
    string line;
      ifstream myfile ("params.txt");
      if (myfile.is_open())
      {
        while ( getline (myfile,line) )
        {
          cout << line << '\n';
        }
        myfile.close();
      }

      else cout << "Unable to open file";*/
}

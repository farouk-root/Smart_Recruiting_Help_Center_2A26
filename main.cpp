#include <iostream>
#include "app.h"
using namespace std;

int main()
{

    app() eco;
    eco.ajouter(Employe);
    eco.ajouter(Employe);
    eco.chercher_Employe(VCIN)->afficher();
    eco.afficher_Employe();
    cout<<"app"<<endl;
    eco.afficher_Employe();
    eco.supprimer_Employe('µµµµµµ');
    eco.ajouter(Employe);
    cout<<"app "<<endl;

    return 0;
}



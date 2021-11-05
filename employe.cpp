#include <employe.h>

employe::employe(int ID , string nom , int experience  , string email)
{
    this -> ID = ID ; 
    this -> nom = nom ; 
    this -> experience = experience ; 
    this -> email = email ; 
}

employe::~employe()
{
}

void employe ::afficher ()
{
    cout << "ID = " << ID << endl ; 
    cout << "nom = " << nom << endl ; 
    cout << "experience = " << experience << endl ; 
    cout << "email = "<< email << endl ; 

}
#include <iostream>
#include <string>
#include "Personne.h"
#include "Etudiant.h"
#include "Note.h"
#include "Cours.h"
#include "Enseignant.h"
#include "Classe.h"
using namespace std;
int main()
{
    Etudiant etu("a","b","c","d","e","f");
    Note no("examen", 15.77);
    cout << no.get_type_note() << "\t" << no.get_note() << endl;
    no.set_note(22.77);
    no.set_type_note("pas examen");
    cout << no.get_type_note()<<"\t" << no.get_note() << endl;
    Classe cl("e", "e", 2.3);
    cout <<"get coeff:   " << cl.get_coefficient() << endl;
    
    
    return 0;
}

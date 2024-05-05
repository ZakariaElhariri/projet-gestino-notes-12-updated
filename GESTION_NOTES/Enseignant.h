#pragma once
#include "Personne.h"
#include "Cours.h"
#include <vector>
class Enseignant :
    public Personne
{
    string id_enseignant;
    string specialite;
    //[Enseignant-Cours(1 a *)]
    vector<Cours*> cours;
public:
    //constructors:
    //by default
    Enseignant();
    //by parameter
    Enseignant(string n, string t, string c, string a, string i, string s);
    //by copy
    Enseignant(Enseignant& copy);

    //deconstructor:
    ~Enseignant();

    //getters:
    string get_id_enseignant();
    string get_specialite();

    //setters:
    void set_id_enseignant(string p);
    void set_specialite(string p);


    void ajouter_cours(Cours* cours);

};


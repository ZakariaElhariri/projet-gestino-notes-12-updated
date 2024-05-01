#include "Classe.h"


Classe::Classe() {}
Classe::Classe( string id, string no,float co):id_classe(id),nom_classe(no), coefficient(co){}
Classe::~Classe(){}


//Getters
string Classe::get_id_classe() { return id_classe; }
string Classe::get_nom_classe() { return nom_classe; }
float Classe::get_coefficient() { return coefficient; }

//setters
void Classe::set_id_classe(string p) { id_classe = p; }
void Classe::set_nom_classe(string p) { nom_classe = p; }
void Classe::set_coefficient(float p) { coefficient = p; }

void Classe::ajouter_etudiant(Etudiant* e) { etudiants.push_back(e); }



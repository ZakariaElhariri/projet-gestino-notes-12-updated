#include "Classe.h"

Classe::Classe() {}
Classe::Classe( string id, string no,int ni):id_classe(id),nom_classe(no), niveau(ni){}
Classe::Classe(Classe& copy) { 
	id_classe = copy.id_classe;
	nom_classe = copy.nom_classe;
	niveau = copy.niveau;
}
Classe::~Classe(){}


//Getters
string Classe::get_id_classe() { return id_classe; }
string Classe::get_nom_classe() { return nom_classe; }
int Classe::get_niveau() { return niveau; }

//setters
void Classe::set_id_classe(string p) { id_classe = p; }
void Classe::set_nom_classe(string p) { nom_classe = p; }
void Classe::set_niveau(int p) { niveau = p; }

void Classe::ajouter_etudiant(Etudiant* e) { 
	//qd on ajoute un etudiant a une classe , on donne le nom de la dernière dans le champ classe_associe de etudiant
	e->set_classe_associe(this);
	etudiants.push_back(e); 
}



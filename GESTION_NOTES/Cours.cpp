#include "Cours.h"

Cours::Cours(){}
Cours::Cours(string i, string n, float c):id_cours(i),nom_cours(n),coefficient(c){}
Cours::Cours(Cours& copy) {
	id_cours = copy.id_cours;
	nom_cours = copy.nom_cours;
	coefficient = copy.coefficient;
}
Cours::~Cours() {}

//getters
string Cours::get_id_cours() { return id_cours; }
string Cours::get_nom_cours() { return nom_cours; }
float Cours::get_coefficient() { return coefficient; }

//setters:
void Cours::set_id_cours(string p) { id_cours = p; }
void Cours::set_nom_cours(string p) { nom_cours = p; }
void Cours::set_coefficient(float p) { coefficient = p; }


void Cours::ajouter_notes(Note* n) { 
	//qd on ajoute la note au cours associe, on ajoute son nom dans le champ 'cours_associe' de note 
	n->set_cours_associe(this);
	notes.push_back(n);
}
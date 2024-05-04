#include "Enseignant.h"
using namespace std;

Enseignant::Enseignant(){}
Enseignant::Enseignant(string n, string t, string c, string a, string i, string s):Personne(n,t,c,a),id_enseignant(i),specialite(s){}
Enseignant::~Enseignant(){}

/*
string Enseignant::Personne::get_nom() { return nom; }
string Enseignant::Personne::get_telephone() { return telephone; }
string Enseignant::Personne::get_cin() { return cin; }
string Enseignant::Personne::get_adresse() { return adresse; }
*/
string Enseignant::get_id_enseignant() { return id_enseignant; }
string Enseignant::get_specialite() { return specialite; }

/*
void Enseignant::Personne::set_nom(string p) { nom = p; }
void Enseignant::Personne::set_telephone(string p) { telephone = p; }
void Enseignant::Personne::set_cin(string p) { cin = p; }
void Enseignant::Personne::set_adresse(string p) { adresse = p; }
*/
void Enseignant::set_id_enseignant(string p) {  id_enseignant= p; }
void Enseignant::set_specialite(string p) { specialite = p; }

void Enseignant::ajouter_cours(Cours* c) { cours.push_back(c); }

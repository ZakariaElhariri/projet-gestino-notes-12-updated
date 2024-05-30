#include "Classe.h"
#include <algorithm>

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
int Classe::get_nombre_etudiants() { return etudiants.size(); }
vector<Etudiant*> Classe::get_etudiants() { return etudiants; }

//setters
void Classe::set_id_classe(string p) { id_classe = p; }
void Classe::set_nom_classe(string p) { nom_classe = p; }
void Classe::set_niveau(int p) { niveau = p; }

void Classe::ajouter_etudiant(Etudiant* e) { 
	//qd on ajoute un etudiant a une classe , on donne le nom de la dernière dans le champ classe_associe de etudiant
	e->set_classe_associe(this);
	etudiants.push_back(e); 
}
void Classe::supprimer_etudiant(string mat) {
    for (auto e = etudiants.begin(); e != etudiants.end(); ) {
        if ((*e)->get_matricule() == mat) {
            delete* e; //supprimer memo
            e = etudiants.erase(e); // suprimer vecteur
        }
        else {
            ++e; //jump to enxt element
        }
    }
}

void Classe::get_my_classements() {
	
	vector<Etudiant*> sorted_students;

	for (auto& etu : etudiants) {
		//copier tt les etudiants ici
		sorted_students.push_back(etu);
	}

	// utiliser la methode predefinie sort (fonction sort)
	sort(sorted_students.begin(), sorted_students.end(), [](Etudiant* a, Etudiant* b) {
		return a->moyenne() > b->moyenne();
		});
	// maintenant le vecteur sorted_students est trié.

	// maintenant on ajoute le classement

	int classement = 1;
	for (auto etu : sorted_students) {
		cout << "classemnt de l'etudiant avec matricule : " << etu->get_matricule() << " et le nom " << etu->get_nom() << "est  ---->   " << classement << endl;
		// et on l'affiche et on l'increment pour l'etudiant suivant
		classement++;
	}

}



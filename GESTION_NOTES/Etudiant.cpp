#include "Etudiant.h"
#include <algorithm>
#include <vector>
using namespace std;
template <typename T>
void display_smtgh(T p,string name)
{
	cout << name <<":  " << p << "\t";
}

Etudiant::Etudiant(){}
Etudiant::Etudiant(string n, string t, string c, string a, string mat, int an):Personne(n,t,c,a),matricule(mat),annee_entree(an){}
Etudiant::Etudiant(Etudiant& copy):Personne(copy) {
	matricule = copy.matricule;
	annee_entree = copy.annee_entree;
}
Etudiant::~Etudiant() {}

/*
string Etudiant::Personne::get_nom() { return nom; }
string Etudiant::Personne::get_telephone() { return telephone; }
string Etudiant::Personne::get_cin() { return cin; }
string Etudiant::Personne::get_adresse() { return adresse; }
*/
string Etudiant::get_matricule() { return matricule; }
int Etudiant::get_annee_entree() { return annee_entree; }
Classe* Etudiant::get_classe_associe() { return classe_associe; }
void Etudiant::get_notes() {
	float moy = 0;
	for (Note* n : notes) {
		auto matiere = (n->get_cours_associe())->get_nom_cours();
		auto coefficient = (n->get_cours_associe())->get_coefficient();
		auto type_note = n->get_type_note();
		auto note = n->get_note();
		cout << "Matiere\tCoefficient\tType note\tNote" << endl;
		display_smtgh(matiere,"Matiere");
		display_smtgh(coefficient, "Coefficient");
		display_smtgh(type_note, "Type Note");
		display_smtgh(note, "Note");
		moy = moy + note;
		cout<<endl;
		
	}
	cout << "\t\t\t\tMoyenne :   " << moy << endl;
}
/*
void Etudiant::Personne::set_nom(string p) { nom = p; }
void Etudiant::Personne::set_telephone(string p) { telephone = p; }
void Etudiant::Personne::set_cin(string p) { cin = p; }
void Etudiant::Personne::set_adresse(string p) { adresse = p; }
*/
void Etudiant::set_matricule(string p) { matricule = p; }
void Etudiant::set_annee_entree(int p) { annee_entree = p; }


void Etudiant::bulletin() {
	Classe* cl = get_classe_associe();
	cout << "Nom de la classe:  " << cl->get_nom_classe() << "\t\tNiveau:  " << cl->get_niveau() << endl;
	cout << "Matricule etudiant:  " << get_matricule() << endl;
	cout << "Nom etudiant:  " << get_nom() << endl;
	cout << "Notes" << endl;
	cout << "MATIERE | COEFFICIENT | TYPE NOTE | NOTE" << endl;
	for (auto n : notes) {
		cout << n->get_cours_associe()->get_nom_cours()<< "|" <<n->get_cours_associe()->get_coefficient()<< "|" << n->get_type_note() << "|" << n->get_note() << endl;
	}
	cout << "\t\t\t\t\t\t   -   Moyenne :  " << this->moyenne() << endl;

}

void Etudiant::ajouter_note(Note* n) { notes.push_back(n); }
void Etudiant::set_classe_associe(Classe* c) { classe_associe = c; }

//function tri
void Etudiant::tri_decroissant_notes() {
	// tri par la fonction sort dans la libraire algorithm
	sort(notes.begin(), notes.end(), [](Note* a, Note* b) {
		return a->get_note() > b->get_note(); 
		});
}
void Etudiant::ajouter_1_5() {
	for (auto n : notes) {
		float s = n->get_note();
		n->set_note(s + 1.5);
	}
}
float Etudiant::moyenne() {
	float moy=0;
	float cpt = 0;
	for (auto n : notes) {
		cpt = cpt + 1;
		moy = moy+n->get_note();
	}
	return moy / cpt;
}

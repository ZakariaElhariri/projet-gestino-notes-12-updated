#pragma once
#include "Personne.h"
#include <vector>
#include "Note.h"
#include "Classe.h"
using namespace std;
class Etudiant :
    public Personne
{
    string matricule;
    int annee_entree;
	//[Etudiant - Note(1 a*)]
	vector<Note*> notes;
	//[Classe-Etudiant(1 a *)]
	Classe* classe_associe;
public:
	//constructors:
	//by default
	Etudiant();
	//by parameters
	Etudiant(string n, string t, string c, string a,string mat, int an);
	//by copy
	Etudiant(Etudiant& copy);
	//deconstructor:
	~Etudiant();
	//getters:
	string get_matricule();
	int get_annee_entree();
	Classe* get_classe_associe();
	void get_notes();
	//setters:
	void set_matricule(string p);
	void set_annee_entree(int p);
	void set_classe_associe(Classe* c);
	void ajouter_note(Note* n);
    void bulletin();

	void tri_decroissant_notes();
	void ajouter_1_5();
	float moyenne();
};


#pragma once
#include "Personne.h"
#include <vector>
#include "Note.h"
class Etudiant :
    public Personne
{
    string matricule;
    string annee_entree;
	vector<Note*> notes;
public:
	//constructors:
	//by default
	Etudiant();
	//by parameters
	Etudiant(string n, string t, string c, string a,string mat, string an);

	

	//deconstructor:
	~Etudiant();



	//getters:
	string get_matricule();
	string get_annee_entree();
	
	
	//setters:
	void set_matricule(string p);
	void set_annee_entree(string p);



	void ajouter_note(Note* n);
	





    void bulletin();
};


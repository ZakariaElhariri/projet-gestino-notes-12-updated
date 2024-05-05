#pragma once
#include<iostream>
#include<string>
#include "Etudiant.h"
#include <vector>
using namespace std;
class Classe
{
	string id_classe;
	string nom_classe;
	int niveau;
	//[Classe-Etudiant(1 a *)]
	vector<Etudiant*> etudiants;
public:
	//constructors:
	//by default
	Classe();
	// by parameter
	Classe( string id, string no,int ni);
	// by copy
	Classe(Classe& copy);

	
	//deconstructors:
	~Classe();

	
	//getters:
	string get_id_classe();
	string get_nom_classe();
	int get_niveau();

	//setters:
	void set_id_classe(string p);
	void set_nom_classe(string p);
	void set_niveau(int p);


	void ajouter_etudiant(Etudiant* e);


};	


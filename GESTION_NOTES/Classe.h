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
	float coefficient;
	vector<Etudiant*> etudiants;
public:
	//constructors:
	//by default
	Classe();
	// by parameter
	Classe( string id, string no,float co);
	
	
	//deconstructors:
	~Classe();

	
	//getters:
	string get_id_classe();
	string get_nom_classe();
	float get_coefficient();

	//setters:
	void set_id_classe(string p);
	void set_nom_classe(string p);
	void set_coefficient(float p);

	void ajouter_etudiant(Etudiant* e);


};	


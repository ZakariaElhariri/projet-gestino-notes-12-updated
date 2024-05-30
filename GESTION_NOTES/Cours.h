#pragma once
#include<iostream>
#include<string>
#include<vector>
#include "Note.h"
#include "Enseignant.h"
using namespace std;

 class Cours
{
	 string id_cours;
	 string nom_cours;
	 float coefficient;
	 //[Cours-Note(1 a *)]
	 vector<Note*> notes;
	 Enseignant* enseignant;
public:
	//constructors::
	//by default
	Cours();
	//by parameter
	Cours(string i, string n, float c);
	//by copy
	Cours(Cours& copy);
	//deconstructors:
	~Cours();
	//getters:
	string get_id_cours();
	string get_nom_cours();
	float get_coefficient();
	Enseignant* get_enseignant_associe();
	vector<Note*> get_notes();
	//setters:
	void set_id_cours(string p);
	void set_nom_cours(string p);
	void set_coefficient(float p); 
	void ajouter_notes(Note* n);
	void set_enseignant_associe(Enseignant* e);
};


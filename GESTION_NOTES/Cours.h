#pragma once
#include<iostream>
#include<string>
#include<vector>
#include "Note.h"
using namespace std;

 class Cours
{
	 string id_cours;
	 string nom_cours;
	 float coefficient;
	 vector<Note*> notes;
public:
	
	//constructors::
	//by default
	Cours();

	//by parameter
	Cours(string i, string n, float c);

	//deconstructors:
	~Cours();


	//getters:
	string get_id_cours();
	string get_nom_cours();
	float get_coefficient();

	//setters:
	void set_id_cours(string p);
	void set_nom_cours(string p);
	void set_coefficient(float p); 

	void ajouter_notes(Note* n);
};


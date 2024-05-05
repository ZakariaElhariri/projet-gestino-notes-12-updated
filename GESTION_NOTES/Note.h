#pragma once
#include<iostream>
#include<string>
#include "Cours.h"
using namespace std;

class Note
{
	string type_note;
	float note;
	//[Cours-Note(1 a *)]
	Cours* cours_associe;
public:

	//constructors:
	//by default
	Note();
	 
	//by parameter
	Note(string t, float n);

	//by copy
	Note(Note& copy);


	//deconstructors
	~Note();

	//getters
	string get_type_note();
	float get_note();
	Cours* get_cours_associe();

	//setters
	void set_type_note(string t);
	void set_note(float n);
	void set_cours_associe(Cours* c);
};


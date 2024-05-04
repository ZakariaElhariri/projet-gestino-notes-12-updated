#pragma once
#include <string>
#include <iostream>
using namespace std;
class Personne
{
	string nom;
	string telephone;
	string cin;
	string adresse;

public:

	//constructors:
	//by default
	Personne();
	//by parameters
	Personne(string n, string t, string c, string a);
	/*
	{
		nom = n;
		telephone = t;
		cin = c;
		adresse = a;
	}
	*/

	//deconstructor:
	~Personne();



	//getters:
	virtual string get_nom();
	string get_telephone();
	string get_cin();
	string get_adresse();

	//setters:
	void set_nom(string p);
	void set_telephone(string p);
	void set_cin(string p);
	void set_adresse(string p);

};


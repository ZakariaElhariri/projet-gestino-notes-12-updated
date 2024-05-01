#pragma once
#include<iostream>
#include<string>
using namespace std;

class Note
{
	string type_note;
	float note;
public:

	//constructors:
	//by default
	Note();
	 
	//by parameter
	Note(string t, float n);

	//deconstructors
	~Note();

	//getters
	string get_type_note();
	float get_note();

	//setters
	void set_type_note(string t);
	void set_note(float n);
};


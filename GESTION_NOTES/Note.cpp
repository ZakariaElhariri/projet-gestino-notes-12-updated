#include "Note.h"

Note::Note(){}
Note:: Note(string t, float n) :type_note(t), note(n) {}
Note::Note(Note& copy) {
	type_note = copy.type_note;
	note = copy.note;
}
Note::~Note(){}

//getters
string Note:: get_type_note() { return type_note; }
float Note::get_note() { return note; }
Cours* Note::get_cours_associe() { return cours_associe; }

//setters
void Note::set_type_note(string t) { type_note = t; }
void Note::set_note(float n) { note = n; } 
void Note::set_cours_associe(Cours* c) { cours_associe = c; }

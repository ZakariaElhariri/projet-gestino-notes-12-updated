#include "Note.h"

Note::Note(){}
Note:: Note(string t, float n) :type_note(t), note(n) {}
Note::~Note(){}

//getters
string Note:: get_type_note() { return type_note; }
float Note::get_note() { return note; }

//setters
void Note::set_type_note(string t) { type_note = t; }
void Note::set_note(float n) { note = n; } 

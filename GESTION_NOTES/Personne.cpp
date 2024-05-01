#include "Personne.h"

using namespace std;

Personne::Personne(){}
Personne::Personne(string n, string t, string c, string a) : nom(n),telephone(t),cin(c),adresse(a){}
Personne::~Personne(){}

string Personne:: get_nom() { return nom; }
string Personne:: get_telephone() { return telephone; }
string Personne:: get_cin() { return cin; }
string Personne:: get_adresse() { return adresse; }

//setters:
void Personne::set_nom(string p) { nom = p; }
void Personne::set_telephone(string p) { telephone = p; }
void Personne::set_cin(string p) { cin = p; }
void Personne::set_adresse(string p) { adresse = p; }

// TRAVAIL DES ETUDIANTS DE LA -3EME ANNEE IIR  -G1 -ORANGERS
// ENCADRE PAR
// Professeur Hanaa El Fazazi
// REALISE PAR 
// ZAKARIA ELHARIRI
// Ce project est réalisé pour la matière de OOP in c++ (object oriented programming in c++) / POO en c++ (programmation orientée object en c++)
// Le code suivant est le code du Source.cpp, ou il y'a la fonction main qui va appeler, utiliser, et manipuler tout les classes et méthodes qui'ont étées créer dans les fichiers :
// "Classe1.h" avec les declarations et prototypes
// "Classe1.cpp" avec les methodes et fonctions et les surcharges
// Chaque Classe contient:
// 1. CONSTRUCTEUR par défaut/paramètre/copie  
// 2. DECONSTRUCTEUR
// 3. Setters
// 4. Getters
// 5. Methodes demandées
// 6. Les Methodes pour faire une liaison entre les classes (1 a *) par exemple

// TOUTES LES IMPORTATIONS NECESSAIRES pour avoir les classes crées (objets) et les librairies dont on aura besoin
#include <iostream>
#include <vector>
#include <string>
#include "Personne.h"
#include "Etudiant.h"
#include "Note.h"
#include "Cours.h"
#include "Enseignant.h"
#include "Classe.h"
#include <deque>
#include <list>
#include <map>
#include <algorithm>

using namespace std;

int main() {
    //----------------------------------------------------------------------------------------------------------------------------------------------
    //--------------------------------------------------------INITIALISATION DES CLASSES------------------------------------------------------------
    //----------------------------------------------------------------------------------------------------------------------------------------------
    //cette partie est pour tester les initialisations, après cette partie il y'a les FONCTIONNALITES
    // deux etudiants
    Etudiant etu("ZAKARIA", "06ETU", "BWETU", "CASAETU", "MATZAKETU", 2021);
    Etudiant etu2("ZAKARIA2", "06ETU2", "BWETU2", "CASAETU2", "MATZAKETU2", 2021);
    // un enseignant
    Enseignant ens("THAMI", "06PROF", "BWPROF", "CASAPROF", "IDTHAMIPROF", "MATH");
    // deux classes
    Classe cla("IDG1", "G1", 1);
    Classe cla2("IDG2", "G2", 2);
    // deux cours
    Cours cou1("IDMATH", "MATH", 7);
    Cours cou2("IDSCIENCE", "SIENCE", 5);

    // ----------NOTES-----------
    // trois notes
    Note no("examen", 20);
    Note no2("examen", 11);
    Note no3("examen", 13);

    // ------ETUDIANTS---------
    // Etudiant1 a 3 notes  [Etudiant-Note(1 a *)]
    etu.ajouter_note(&no);
    etu.ajouter_note(&no2);
    etu.ajouter_note(&no3);
    // Etudiant2 a 3 notes
    etu2.ajouter_note(&no3);
    etu2.ajouter_note(&no);
    etu2.ajouter_note(&no2);

    // ------ENSEIGNANTS--------
    // enseignant 'ens' a un cours 'cou' [Enseignant-Cours(1 a *)]
    ens.ajouter_cours(&cou1);

    // -------CLASSES--------
    // classe 1 contient etu [Classe-Etudiant(1 a *)]
    cla.ajouter_etudiant(&etu);
    // classe 2 contient etu2
    cla2.ajouter_etudiant(&etu2);

    // -------COURS-----------
    // cours 1 avec 2 notes [Cours-Note(1 a *)]
    cou1.ajouter_notes(&no2);
    cou1.ajouter_notes(&no);
    // cours 2 avec 2 notes
    cou2.ajouter_notes(&no3);
    cou2.ajouter_notes(&Note("controle", 18));

    //----------------------------------------------------------------------------------------------------------------------------------------------
    //-----------------------------------------------------LES FONCTIONALITES DU PROG---------------------------------------------------------------
    //----------------------------------------------------------------------------------------------------------------------------------------------
    deque<Classe*>           classes;
    list<Cours*>               cours;
    map<string, Etudiant*> etudiants;
    while (1) {
        int choice;
        cout << "choisir une fonctionalité : \n1.GESTION CLASSE\n2.GESTION COURS\n3.GESTION ETUDIANT\n0.QUITTER PROGRAMME " << endl;
        cin >> choice;
        if (choice == 0) break;
        else {
            if (choice == 1) {
                //GESTION CLASSE
                int choice2;
                cout << "choisissez une option de GESTION CLASSE:\n1.ajouter une classe\n2.afficher le nombre d'etudiant des classe\n3.ajouter/modifier/supprimer etudiant par matricule" << endl;
                cin >> choice2;
                if (choice2 == 1) {
                    string id_classe, nom;int niveau;
                    cout << "donner id_classe - nom -niveau" << endl;
                    cin >> id_classe;
                    cin >> nom;
                    cin >> niveau;
                    classes.emplace_front( new Classe(id_classe, nom, niveau) );
                }
                else if (choice2 == 2) {
                    cout << "le nombre d'étudiants dans chaque classe" << endl;
                    for (auto c : classes) {
                        cout << "nom classe : " << c->get_nom_classe() << "  Il y'a " << c->get_nombre_etudiants() << "  etudiants" << endl;
                    }
                }
                else if (choice2 == 3) {
                    int crud;
                    cout << "1.ajouter\n2.modifier\n3.supprimer" << endl;
                    cin >> crud;
                    if (crud == 1) {
                        string n, t, cc, a, m, mc;
                        int an;
                        cout << "nom - telephone - CIN - adresse -matricule - annee d'entree de l'etudiant" << endl;
                        cin >> n >> t >> cc >> a >> m >> an;
                        cout << "\n donner ID de la classe ou vous voulez ajouter cet etudiant" << endl;
                        cin >> mc;
                        for (auto c : classes) {
                            if (c->get_id_classe() == mc) {
                                c->ajouter_etudiant(new Etudiant(n, t, cc, a, m, an));
                            }
                        }
                    }
                    else if (crud == 2) {
                        string n, t, c, a, m;
                        int an;
                        cout << "donner les nouvelles valeurs a modifier avec matricule comme suit : nom - telephone - CIN - adresse -matricule - annee d'entree de l'etudiant" << endl;
                        cin >> n >> t >> c >> a >> m >> an;
                        for (auto cc : classes) {
                            for (auto e : cc->get_etudiants()) {
                                if (e->get_matricule() == m) {
                                    e->set_nom(n);
                                    e->set_telephone(t);
                                    e->set_cin(c);
                                    e->set_adresse(a);
                                    e->set_annee_entree(an);
                                    cout << "etudiant modifie, matricule : " << e->get_matricule() << endl;
                                }
                            }
                        }
                    }
                    else if (crud == 3) {
                        string m, mc;
                        cout << "donner le matricule de l'etudiant a supprimer" << endl;
                        cin >> m;
                        cout << "\n donner ID de la classe de l'etudiant" << endl;
                        cin >> mc;
                        for (auto c : classes) {
                            if (c->get_id_classe() == mc) {
                                c->supprimer_etudiant(m);
                            }
                        }
                    }
                }
            }
            else if (choice == 2) {
                int choice2;
                
                //GESTION COURS

                cout << "choisissez une option de GESTION COURS:\n1.remplir cours\n2.trier liste cours\n3.ajouter/modifier/supprimer note cours avec id" << endl;
                cin >> choice2;
                if (choice2 == 1) {
                    string id_cours, nom_cours;int coefficient;
                    cout << "ramplir les cours -> donner : id_cours - nom_cours - coefficient" << endl;
                    cin >> id_cours;
                    cin >> nom_cours;
                    cin >> coefficient;
                    classes.push_back(new Classe(id_cours, nom_cours, coefficient));


                }
                else if (choice2 == 2) {
                    cout << "on va trier les cours par leur coefficient" << endl;
                    //iterate over each one
                    for (auto i = cours.begin(); i != cours.end(); ++i) {
                        for (auto j = next(i); j != cours.end(); ++j) {
                            if ((*i)->get_coefficient() > (*j)->get_coefficient()) {
                                Cours* exchange = *i;
                                *i = *j;
                                *j = exchange;
                            }
                        }
                    }
                }
                else if (choice2 == 3) {
                    int crud = 4;
                    cout << "1.ajouter\n2.modifier\n3.supprimer" << endl;
                    cin >> crud;
                    //trouver le cours puis la note
                    string id_cours;
                    
                    cout << "donner l'id du cours" << endl;
                    cin >> id_cours;
                    
                    for (auto c : cours) {
                        if(c->get_id_cours()==id_cours){
                        for (auto n : c->get_notes()) {
                            

                                if (crud == 1) {
                                    float p;
                                    string etu_associe;
                                    cout << "donner la note et la matricule de l'etudiant associe";
                                    cin >> p;
                                    cin >> etu_associe;
                                    for (auto i = etudiants.begin(); i != etudiants.end(); ++i) {
                                        if (i->first == etu_associe) {
                                            

                                            string type_note;
                                            cout << "la note est 'examen' ou la note est 'controle'" << endl;
                                            cin >> type_note;

                                            i->second->ajouter_note(new Note(type_note,p));

                                            break;
                                        }
                                    }

                                }
                                else if (crud == 2) {
                                    float p;
                                    cout << "donner la nouvelle note a modifier" << endl;
                                    cin >> p;
                                    n->set_note(p);
                                }
                                else if (crud == 3) {
                                    string type_note;
                                    cout << "de ce cours la , tu veux supprimer la note 'examen' ou la note 'controle'" << endl;
                                    cin >> type_note;
                                    if (n->get_type_note() == type_note) {
                                        delete n;
                                    }
                                }
                            
                        }
                        }
                    }
                    
                }



            }

            else if (choice == 3) {
                int choice2=-1;
                while(choice2<1 || choice2>8){
                string matricule;
                cout << "choisissez une option de GESTION ETUDIANT:\n1.ajouter un etudiant\n2.ajouter une note d'un etudiant\n3.trier la liste notes decroissant\n4.ajouter 1.5 aux notes <9.5\n5.supprimer etudiant\n6.afficher bulletin etudiant\n7.nombre etudiants moyenne <9\n8.moyenne etudiant, classement"<<endl;
                cin >> choice2;
                switch (choice2) {
                case 1:
                {
                    string nom, telephone, cin_etu, adresse, matricle;
                    int annee_entree,a;
                    cout << "donner les données pour ajouter un etudiant: nom, telephone, cin, adresse, matricle,annee_entree" << endl;
                    cin >> nom;
                    cin >> telephone;
                    //car cin est reserve ajout de 'etu' a cause d e'lerreur 
                    cin >> cin_etu;
                    cin >> adresse;
                    cin >> matricule;
                    cin >> annee_entree;

                    //Etudiant* e = new Etudiant(nom,telephone,cin,adresse,matricule);

                    etudiants[matricule] = new Etudiant(nom, telephone, cin_etu, adresse, matricule, annee_entree);

                    break;
                }
                case 2:
                {
                    string type_note, id_cours_associe,id_etudiant_associe;
                    float note;
                    cout << "ajouter une note donner: type note(examen/controle)-note-id_cours_associe-id_etudiant_associe" << endl;
                    cin >> type_note;
                    cin >> note;
                    cin >> id_cours_associe;

                    //creer note avec les données données par utilisateur
                    Note* my_note = new Note(type_note, note);

                    //l'ajouter au cours associe
                    for (auto c : cours) {
                        if (c->get_id_cours() == id_cours_associe) {
                            c->ajouter_notes(my_note);
                        }
                    }
                    //l'ajouter a l'etudiant associe dans la map<matricule,etudiant*> etudiatns;
                    etudiants[id_etudiant_associe]->ajouter_note(my_note);

                    break;}


                case 3:
                {
                    string id_etudiant;
                    cout << "donner id_etudiant pour lequel vous souhaitez faire le tri:id_etudiant" << endl;
                    cin >> id_etudiant;
                    //tri effectue par fonction interne de la classe Etudiant
                    etudiants[id_etudiant]->tri_decroissant_notes();

                    
                    
                    break;}

                case 4:
                {
                    
                    for (auto et = etudiants.begin(); et != etudiants.end(); ++et) {
                        et->second->ajouter_1_5();
                    }
                    
                    break; }
                case 5:
                {
                    string id_etudiant;
                    cout << "donner id_etudiant que vous voulez supprimer" << endl;
                    cin >> id_etudiant;
                    auto et= etudiants.find(id_etudiant);
                    if (et != etudiants.end()) {
                        etudiants.erase(et);
                        delete et->second;
                    }
                    // la supression de l'etudiant direct n'est pas possible on passe par l'iterateur alors.
                    break; }
                case 6:
                {
                    for (auto etu = etudiants.begin(); etu != etudiants.end(); ++etu) {
                        etu->second->bulletin();
                        //afficher les bulletins de tt les etudiants dans cette boucle
                    }

                    break; }
                case 7:
                {
                    int cpt=0;
                    for (auto etu = etudiants.begin(); etu != etudiants.end(); ++etu) {
                        if (etu->second->moyenne() < 9) { cpt++; }
                        //afficher les  etudiants avec moyenne <9
                    }
                    cout << "le nombre des etudiants avec moyenne < 9 est :   " << cpt << endl;

                    break; }
                case 8:
                {
                    cout << "le classement des etudiants dans toutes les classes!" << endl;
                    for (auto cl : classes) {
                        cout << "id de la classe " << cl->get_id_classe() << "nom classe " << cl->get_nom_classe() << "level de la classe " << cl->get_niveau() << endl;
                        cout << "nombre etudiants" << cl->get_nombre_etudiants() << endl;
                        cout << "~~CLASSEMENT  DES UDIANTS: \n";
                        cl->get_my_classements();

                        cout << "\n\n";
                    }

                    break; }
                default:
                    cout << "pas un bon choix" << endl;
                    
                }
            }
            }
            else {
                cout<<"vous n'avez pas fait un bon choix!" << endl;
                continue; //iterate again and again if choice is wrong
                //==controle de saisie 
            }
        }
    }

    // avant quitter le programme , on va nettoyer la memoire allouée car les données ne sont pas saved dans un fichier elles sont seulement crées lors de l'execution 'RUN'
    for (auto c : classes) {
        delete c;
    }
    for (auto c : cours) {
        delete c;
    }
    etudiants.clear();

    return 0;
}


//TRAVAIL DES ETUDIANTS DE LA -3EME ANNEE IIR  -G1 -ORANGERS
//ENCADRE PAR
//Professeur Hanaa El Fazazi
//REALISE PAR 
//ZAKARIA ELHARIRI
//MOHAMED BOUGTAB
//Ce project est réalisé pour la matière de OOP in c++ (object oriented programming in c++) / POO en c++ (programmation orientée object en ++)
//Le code suivant est le code du Source.cpp, ou il y'a la fonction main qui va appeler, utiliser, et manipuler tout les classes et méthodes qui'ont étées créer dans les fichiers :
//"Classe1.h" avec les declarations et prototypes
//"Classe1.cpp" avec les methodes et fonctions et les surcharges
//Chaque Classe contient:
//1.CONSTRUCTEUR par défaut/paramètre/copie  
//2.DECONSTRUCTEUR
//3.Setters
//4.Getters
//5.Methodes demandées
//6.Les Methodes pour faire une liaison entre les classes (1 a *) par exemple


//TOUTES LES IMPORTATIONS NECESSAIRES pour avoir les classes crées (objets) et les librairies dont on aura besoin
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

using namespace std;
int main()
{


    //----------------------------------------------------------------------------------------------------------------------------------------------
    //--------------------------------------------------------INITIALISATION DES CLASSES------------------------------------------------------------
    //----------------------------------------------------------------------------------------------------------------------------------------------




   //deux etudiants
    Etudiant etu("ZAKARIA","06ETU","BWETU","CASAETU","MATZAKETU",2021);
    Etudiant etu2("ZAKARIA2", "06ETU2", "BWETU2", "CASAETU2", "MATZAKETU2", 2021);
   //un enseignant
    Enseignant ens("THAMI", "06PROF","BWPROF","CASAPROF","IDTHAMIPROF","MATH");
   //deux classe
    Classe cla("IDG1","G1",1);
    Classe cla2("IDG2", "G2", 2);
   //deux cours
    Cours cou1("IDMATH","MATH",7);
    Cours cou2("IDSCIENCE", "SIENCE", 5);

   //----------NOTES-----------
   //trois notes
    Note no("examen",20);
    Note no2("examen", 11);
    Note no3("examen", 13);
    
    //------ETUDIANTS---------
    //Etudiant1 a 3 notes  [Etudiant-Note(1 a *)]
    etu.ajouter_note(&no);
    etu.ajouter_note(&no2);
    etu.ajouter_note(&no3);
    //Etudiant2 a 3 notes
    etu2.ajouter_note(&no3);
    etu2.ajouter_note(&no);
    etu2.ajouter_note(&no2);
    
    


    //------ENSEIGNANTS--------
    //enseignant 'ens' a un cours 'cou' [Enseignant-Cours(1 a *)]
    ens.ajouter_cours(&cou1);




    //-------CLASSES--------
    //classe 1 contient etu [Classe-Etudiant(1 a *)]
    cla.ajouter_etudiant(&etu);
    //classe 2 contient etu2
    cla2.ajouter_etudiant(&etu2);




    //-------COURS-----------
    //cours 1 avec 2 notes [Cours-Note(1 a *)]
    cou1.ajouter_notes(&no2);
    cou1.ajouter_notes(&no);
    //cours 2 avec 2 notes
    cou2.ajouter_notes(&no3);
    cou2.ajouter_notes(&Note("controle", 18));



   //----------------------------------------------------------------------------------------------------------------------------------------------
   //-----------------------------------------------------LES FONCTIONALITES DU PROG---------------------------------------------------------------
   //----------------------------------------------------------------------------------------------------------------------------------------------
    


    //FONCTIONNALITE 1 : GESTION CLASSE

    deque<Classe> classes;

    //FONCTIONNALITE 2 : GESTION COURS

    list<Cours> cours;

    //FONCTIONNALITE 3 : GESTION ETUDIANT

    map<string,Etudiant> etudiants; //key type : string = matricule




    //etu.bulletin();

    
   


    
    return 0;
}

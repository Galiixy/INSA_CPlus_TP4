/*************************************************************************
                           Xxx  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $ANNEE$ par $AUTEUR$
*************************************************************************/

//---------- Réalisation de la classe <Appli> (fichier Appli.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include<stdio.h>
#include<string.h>
#include <map>

#include "Appli.h"

using namespace std;



//------------------------------------------------------------- Constantes
const int nbOptions = 4; 
map <string, string> tabOption; // dans l'ordre sans option, -e, -t, -g

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

 int main (int argc, char* argv[])
// Algorithme :
{
     int cpt;
     string nomFichier;
     if (argc == 1) {
         cout << "Aucun parametres valide, veuillez rentrer un nom de fichier au minimum pour faire fonctionner l'application"<<endl<<endl;
         cout << "Pour les options : " << endl << " 1 - '-e', '-g nomfichier.dot', '-t heure' " << endl;
	 cout << "Relancer " << argv[0] <<" avec les bons parametres ! " <<endl;
	return 1;
     }
     for (cpt = 1; cpt < argc; cpt++) {
         if (cpt + 1 == argc) { 
             //le dernier parametre est toujours 
             // le nom du fichier
	     cout << "nom du fichier :" << argv[cpt] <<endl;
             nomFichier = argv[cpt];
         }
         else if (strcmp(argv[cpt], "-e")==0) {
             tabOption["e"];
	     cout << "ajout de l'option -e"<<endl;
         }
         else if (strcmp(argv[cpt], "-t")==0) {
             tabOption["t"];
	     cout << "ajout de l'option -t"<<endl;
         }
         else if (strcmp(argv[cpt], "-g")==0) {
             tabOption["g"];
	     cout << "ajout de l'option -g"<<endl;
         }
         else if (strcmp(argv[cpt - 1], "-t")==0) {
             tabOption["t"] = argv[cpt];
	     cout << "ajout de parametre -t"<<endl;
         }
         else if (strcmp(argv[cpt - 1], "-g")==0) {
             tabOption["g"] = argv[cpt];
	     cout << "ajout de parametre -g"<<endl;
         }
     }
     
     return 0;
} //----- Fin de Méthode


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

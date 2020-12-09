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

     if (argc == 0) {
         cout << "Aucun parametres, veuillez rentrer un nom de fichier au minimum"<<endl;
         cout << "Pour les options : " << endl << " 1 - '-e', '-g nomfichier.dot', '-t heure' " << endl;;
     }
     for (cpt = 1; cpt < argc; cpt++) {
         if (cpt + 1 == argc) { 
             //le dernier parametre est toujours 
             // le nom du fichier
             nomFichier = argv[cpt];
         }
         else if (strcmp(argv[cpt], "-e")) {
             tabOption["e"];
         }
         else if (strcmp(argv[cpt], "-t")) {
             tabOption["t"];
         }
         else if (strcmp(argv[cpt], "-g")) {
             tabOption["g"];
         }
         else if (strcmp(argv[cpt - 1], "-t")) {
             tabOption["t"] = argv[cpt];
         }
         else if (strcmp(argv[cpt - 1], "-g")) {
             tabOption["g"] = argv[cpt];
         }
     }
     

} //----- Fin de Méthode


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

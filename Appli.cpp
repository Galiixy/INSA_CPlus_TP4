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
#include<stdio.h>
#include<string>
#include <map>

//------------------------------------------------------ Include personnel
#include "Flux.h"
#include "CollectionLog.h"



//------------------------------------------------------------- Constantes
const int nbOptions = 4; 
map <string, string> mapOption; // dans l'ordre sans option, -e, -t, -g

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
bool valideOption(Log &log){
    map<string, string>::iterator it = mapOption.find("e");
    if(it != mapOption.end()){
        if(log.GetExtension().compare("jpg")==0){
            return false;
        }
        else if (log.GetExtension().compare("css")==0){
            return false;
        }
        else if(log.GetExtension().compare("js")==0){
            return false;
        }
    }
    it = mapOption.find("t");
    if(it != mapOption.end()){
        if(mapOption["t"].compare(log.GetHeure())==0){
            return false;
        }
    }
    return true;
}

 int main (int argc, char* argv[])
// Algorithme :
{
     int cpt;
     string nomFichier;

     /* verification du bon nombre d'argument en entree */ 
     if (argc == 1) {
       cout << "Aucun parametres valide, veuillez rentrer un nom de fichier au minimum pour faire fonctionner l'application"<<endl<<endl;
       cout << "Pour les options : " << endl << " '-e', '-g nomfichier.dot', '-t heure' " << endl;
	   cout << "Relancer " << argv[0] <<" avec les bons parametres ! " <<endl;
	   return 1;
     }

     /* remplissage du tableau d'option */ 
     for (cpt = 1; cpt < argc; cpt++) {
             if (cpt + 1 == argc) { 
                //le dernier parametre est toujours le nom du fichier (sous linux)
                cout << "nom du fichier :" << argv[cpt] <<endl;
                nomFichier = argv[cpt];
             }
             else if (strcmp(argv[cpt], "-e")==0) {
                mapOption["e"];
                cout << "ajout de l'option -e"<<endl;
             }
             else if (strcmp(argv[cpt], "-t")==0) {
                mapOption["t"];
                cout << "ajout de l'option -t"<<endl;
             }
             else if (strcmp(argv[cpt], "-g")==0) {
                 mapOption["g"];
             cout << "ajout de l'option -g"<<endl;
             }
             else if (strcmp(argv[cpt - 1], "-t")==0) {
                 mapOption["t"] = argv[cpt];
             cout << "ajout de parametre -t"<<endl;
             }
             else if (strcmp(argv[cpt - 1], "-g")==0) {
                 mapOption["g"] = argv[cpt];
             cout << "ajout de parametre -g"<<endl;
             }
         }

     /* recuperation des LOGS */ 
     CollectionLog* collec = new CollectionLog();

     Flux monFlux(argv[argc-1]);
     
     while(!monFlux.isEndFile()){
        Log log = monFlux.readLog();

        if(valideOption(log)){
            cout << "ajout LOG "<<log.GetDocumentCible()<< " vers "<< log.GetDocumentReferenceur() << endl;
            cout <<"Date : " <<log.GetHeure()<< " Extension : "<<log.GetExtension()<<endl;
            collec->Ajouter(log.GetDocumentCible(), log.GetDocumentReferenceur());
        }
    }
    //collec->AfficherDecroissant();
    delete collec;
    return 0;
} //----- Fin de Méthode


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

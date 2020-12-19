/*************************************************************************
                           Xxx  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $ANNEE$ par $AUTEUR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <Flux> (fichier Flux.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <fstream>

#include <string.h>

//------------------------------------------------------ Include personnel
#include "Flux.h"


//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
bool Flux::isEndFile(){
	if(f_in){
		if(f_in.eof()){
			return true;
		}
		else{
			return false;
		}
	}
	else{
		return true;
	}
}

Log Flux::readLog ()
// Algorithme :
//
{
	/* variables */ 
	string ip;
	string date;
	string requete;
	int status =0;
	long int tailleReponse =0;
	string referenceur;
	string idClientNav;
	string separateur(1,'"');

	/* Recuperation de la ligne */
	string ligne; 
	getline(f_in, ligne);

	/* Recuperation des elements */
	ip = getNextElement(ligne, " ");

	getNextElement(ligne, "[");
	date = getNextElement(ligne, "]");

	getNextElement(ligne, separateur);
	requete = getNextElement(ligne,separateur);

	getNextElement(ligne, " ");
	status = stoi(getNextElement(ligne," "));

	tailleReponse = stoi(getNextElement(ligne," "));

	getNextElement(ligne, separateur);
	referenceur = getNextElement(ligne,separateur);

	getNextElement(ligne, separateur);
	idClientNav = getNextElement(ligne,separateur);

	return Log(ip,date,requete,status,tailleReponse,referenceur,idClientNav);
}//----- Fin de LireFlux


//------------------------------------------------- Surcharge d'opérateurs


//-------------------------------------------- Constructeurs - destructeur
Flux::Flux(string P_nomFichier)
// Algorithme :
{
	#ifdef MAP
	    cout << "Appel au constructeur parametres de <Flux>" << endl;
	#endif
	nomFichier = P_nomFichier;
	ifstream monFlux(P_nomFichier);
	f_in.open(P_nomFichier);

	if(monFlux){
		cout <<"Ouverture du fichier"<<endl;
	}
	else 
		cerr <<"Impossible d'ouvrir le fichier"<<endl;
} //----- Fin de Flux

Flux::~Flux ( ){

}

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
string Flux::getNextElement(string & ligne,string separateur)
// Algorithme :
// retourne le prochain element jusquau separateur
// raccourci la ligne a partir du separateur jusqu'a la fin
{
	int position = ligne.find(separateur); //position separateur
	string element = ligne.substr(0,position); // element to return
	ligne = ligne.substr(position+1); //raccourci jusqua fin

	return element;
}//----- Fin de getNextElement
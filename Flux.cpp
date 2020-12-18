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
#include <string.h>

//------------------------------------------------------ Include personnel
#include "Flux.h"


//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
Log Flux::LireFlux ()
// Algorithme :
//
{
	if(monFlux){
		string ligne; 
		getline(f_in, ligne);

		stringstream ss(ligne);
		string caractere;

		while(ss.get(caractere)){
			cout << caractere;
		}
	}
	cout <<endl;

	return null;
}//----- Fin de LireFlux

bool Flux::FinFichier()
// Algorithme :
//
{


}//----- Fin de LireFlux

//------------------------------------------------- Surcharge d'opérateurs
Flux & Flux::operator <<( const Flux & unFlux)
// Algorithme :
//
{
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
Flux::Flux(string P_nomFichier, ifstream P_in)
// Algorithme :
{
	#ifdef MAP
	    cout << "Appel au constructeur parametres de <Flux>" << endl;
	#endif
	nomFichier = P_nomFichier;
	ifstream monFlux(P_nomFichier);
	f_in = monFlux;

	if(monFlux){
		cout <<"Ouverture du fichier";
	}
	else 
		cerr <<"Impossible d'ouvrir le fichier"<<endl;

	
} //----- Fin de Flux


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

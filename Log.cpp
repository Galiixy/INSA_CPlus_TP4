/*************************************************************************
                           Log  -  description
                             -------------------
    début                : 02/12/2020
    copyright            : (C) 2020 par Emmannuel et Gaelle
*************************************************************************/

//---------- Réalisation de la classe <Log> (fichier Log.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <sstream>
#include <cstring>

//------------------------------------------------------ Include personnel
#include "Log.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
string Log::GetDocumentCible ( )
// Algorithme :
//
{
	
	string vecteur;
	stringstream ss(requete);
	getline(ss,vecteur,'/');
	getline(ss,vecteur,' ');
	return vecteur;
} //----- Fin de GetDocumentArrivee

string Log::GetDocumentReferenceur( )
// Algorithme :
//
{
	string vecteur;
	stringstream ss(referenceur);
	getline(ss,vecteur,' ');
	getline(ss,vecteur,' ');
	return vecteur;
} //----- Fin de GetDocumentDepart

string Log::GetTypeDocumentCible ( )
// Algorithme :
//
{
	string vecteur;
	stringstream ss(requete);
	getline(ss,vecteur,'.');
	getline(ss,vecteur,' ');
	return vecteur;
} //----- Fin de GetTypeDocumentArrivee


//------------------------------------------------- Surcharge d'opérateurs
Log & Log::operator = ( const Log& unLog)
// Algorithme :
//
{
    ip = unLog.ip;
    date = unLog.date;
    requete = unLog.requete;
    status = unLog.status;
    tailleReponse = unLog.tailleReponse;
    referenceur = unLog.referenceur;
    idClientNav = unLog.idClientNav;
    return *this;
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
Log::Log( const Log& unLog)
// Algorithme :
//
{
	#ifdef MAP
	    cout << "Appel au constructeur de copie de <Log>" << endl;
	#endif
} //----- Fin de Log (constructeur de copie)


Log::Log( )
// Algorithme :
//
{
	#ifdef MAP
	    cout << "Appel au constructeur vide de <Log>" << endl;
	#endif
} //----- Fin de Log

Log::Log(string cible, string referenceur) : requete(cible), referenceur(referenceur)
// Algorithme :
//
{
	#ifdef MAP
	    cout << "Appel au constructeur vide de <Log>" << endl;
	#endif
} //----- Fin de Log

Log::Log(string ip, string date, string requete, int status, long int tailleReponse,
        string referenceur, string idClientNav) : ip(ip), date(date), requete(requete),
		status(status), tailleReponse(tailleReponse), referenceur(referenceur),
		idClientNav(idClientNav)
// Algorithme :
//
{
	#ifdef MAP
	    cout << "Appel au constructeur surchargé de <Log>" << endl;
	#endif
} //----- Fin de Log


Log::~Log( )
// Algorithme :
//
{
	#ifdef MAP
	    cout << "Appel au destructeur de <Log>" << endl;
	#endif
} //----- Fin de ~Log


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

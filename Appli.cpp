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
#include "Appli.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Xxx::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode


//------------------------------------------------- Surcharge d'opérateurs
Appli& Appli::operator = ( const Appli& unAppli)
// Algorithme :
//
{
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
Appli::Appli( const Appli& unAppli)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Appli>" << endl;
#endif
} //----- Fin de Xxx (constructeur de copie)


Appli::Appli( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Appli>" << endl;
#endif
} //----- Fin de Xxx


Appli::~Appli( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Appli>" << endl;
#endif
} //----- Fin de ~Appli


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

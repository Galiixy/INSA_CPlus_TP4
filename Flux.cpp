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

//------------------------------------------------------ Include personnel
#include "Flux.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Xxx::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode


//------------------------------------------------- Surcharge d'opérateurs
Flux & Flux::operator = ( const Flux & unFlux)
// Algorithme :
//
{
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
Flux::Flux( const Flux & unFlux)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Flux>" << endl;
#endif
} //----- Fin de Flux (constructeur de copie)


Flux::Flux( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Flux>" << endl;
#endif
} //----- Fin de Flux


Flux::~Flux( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Flux>" << endl;
#endif
} //----- Fin de ~Flux


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

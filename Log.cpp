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

//------------------------------------------------------ Include personnel
#include "Log.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Xxx::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode


//------------------------------------------------- Surcharge d'opérateurs
Log & Log::operator = ( const Log& unLog)
// Algorithme :
//
{
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
Log::Log( const Log& unLog)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Log>" << endl;
#endif
} //----- Fin de Xxx (constructeur de copie)


Log::Log( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Log>" << endl;
#endif
} //----- Fin de Xxx


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

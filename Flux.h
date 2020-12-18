/*************************************************************************
                           Xxx  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $ANNEE$ par $AUTEUR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Flux> (fichier Flux.h) ----------------
#if ! defined ( FLUX_H )
#define FLUX_H

//--------------------------------------------------- Interfaces utilisées
#include <iostream>
#include <string>
#include "Log.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Flux>
//
//
//------------------------------------------------------------------------

class Flux
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    Log LireFlux ();
    // Mode d'emploi :
    //  Retourne un objet log d'une ligne complete
    // Contrat :
    // A condition que ca ne soit pas la fin du fichier

    bool FinFichier();
    // Mode d'emploi : 
    // Retourne vrai si c'est la fin du fichier


//------------------------------------------------- Surcharge d'opérateurs
    Flux & operator << ( const Flux & unFlux);
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur

    Flux (string P_nomFichier, ifstream P_in);
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Flux ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
    string nomFichier;
    ifstream f_in;
};

//-------------------------------- Autres définitions dépendantes de <Xxx>

#endif // FLUX_H


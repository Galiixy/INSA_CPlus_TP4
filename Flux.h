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
using namespace std;
#include <iostream>
#include <fstream>
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
    Log readLog ();
    // Mode d'emploi :
    // Retourne un objet log d'une ligne complete
    // Contrat :
    // A condition que ca ne soit pas la fin du fichier

    bool isEndFile();
    // Mode d'emploi : 
    // Retourne vrai si fin du fichier ou fichier impossible a lire


//------------------------------------------------- Surcharge d'opérateurs


//-------------------------------------------- Constructeurs - destructeur
     
    Flux (const string P_nomFichier);
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
    string getNextElement( string & ligne,string separateur);
    // Mode d'emploi :
    // Retourne le prochain element de la ligne avant le separateur

//----------------------------------------------------- Attributs protégés
    string nomFichier;
    ifstream f_in;
};

//-------------------------------- Autres définitions dépendantes de <Xxx>

#endif // FLUX_H


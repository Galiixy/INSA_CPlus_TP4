/*************************************************************************
                           Log  -  description
                             -------------------
    début                : 02/12/2020
    copyright            : (C) 2020 par Emmanuel et Gaelle
*************************************************************************/

//---------- Interface de la classe <Log> (fichier Log.h) ----------------
#if ! defined ( LOG_H )
#define LOG_H

//--------------------------------------------------- Interfaces utilisées
#include <string>

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Log>
//
//
//------------------------------------------------------------------------

class Log
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    void Afficher ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    string GetDocumentCible ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    string GetDocumentReferenceur ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    string GetTypeDocumentCible ( );
    // Mode d'emploi :
    //
    // Contrat :
    //


//------------------------------------------------- Surcharge d'opérateurs
    Log & operator = ( const Log & unLog);
    // Mode d'emploi : Surcharge de l'opérateur d'affectation.
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    Log(const Log & unLog);
    // Mode d'emploi : Constructeur de copie de la classe.
    //
    // Contrat :
    //

    Log( );
    // Mode d'emploi : Constructeur vide de la classe.
    //
    // Contrat :
    //

    Log(string cible, string referenceur);
    // Mode d'emploi : Constructeur vide de la classe.
    //
    // Contrat :
    //

    Log(string ip, string date, string requete, int status, long int tailleReponse,
        string referenceur, string idClientNav);
    // Mode d'emploi : Constructeur surchargé de la classe.
    //
    // Contrat :
    //

    virtual ~Log();
    // Mode d'emploi : Destructeur de la classe.
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
    string ip;
    string date;
    string requete;
    int status;
    long int tailleReponse;
    string referenceur;
    string idClientNav;

};

//-------------------------------- Autres définitions dépendantes de <Log>

#endif // LOG_H
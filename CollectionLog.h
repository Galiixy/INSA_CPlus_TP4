/*************************************************************************
                           Xxx  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $ANNEE$ par $AUTEUR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <CollectionLog> (fichier CollectionLog.h) ----------------
#if ! defined ( COLLECTIONLOG_H )
#define COLLECTIONLOG_H

//--------------------------------------------------- Interfaces utilisées
#include <unordered_map>
#include <utility>
#include <string>
#include <cstring>

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <CollectionLog>
//
//
//------------------------------------------------------------------------

class CollectionLog
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    void Ajouter(string DocumentCible, string DocumentReferenceur);
    // Mode d'emploi : permet d'ajouter à la map un document référenceur
    //                 (s'il n'existe pas déjà) et un document cible
    //                 (s'il n'existe pas déjà, sinon on incrémente).

	void Afficher();
	// Mode d'emploi : méthode utilisée pour les tests afin de vérifier
	//				   le bon fonctionnement de la classe.
	
	void AfficherDecroissant();
	// Mode d'emploi :
	//

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur

    CollectionLog ();
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~CollectionLog ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
    unordered_map<string, pair<unordered_map<string,int>,int>> collection;
    // A un document cible, on associe une liste de documents référenceurs.
};

//-------------------------------- Autres définitions dépendantes de <CollectionLog>

#endif // COLLECTIONLOG_H


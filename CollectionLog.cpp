/*************************************************************************
                           Xxx  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $ANNEE$ par $AUTEUR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <CollectionLog> (fichier CollectionLog.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <fstream>

//------------------------------------------------------ Include personnel
#include "CollectionLog.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
void CollectionLog::Ajouter(string DocumentCible, string DocumentReferenceur)
// Algorithme :
//
{
    if(collection.find(DocumentCible) == collection.end()){
        // Si le document cible n'est pas encore présent dans la structure,
        // on l'ajoute et on indique qu'il a été ciblé une fois.
        collection[DocumentCible].first[DocumentReferenceur] = 1;
        collection[DocumentCible].second = 1;
    }
    else{
        if (collection[DocumentCible].first.find(DocumentReferenceur)
        == collection[DocumentCible].first.end()){
            // Si le document cible est déjà présent mais que c'est un nouveau
            // référenceur, on ajoute le référenceur et on incrémente le nombre
            // de hit.
            collection[DocumentCible].first[DocumentReferenceur] = 1;
            collection[DocumentCible].second++;
        }
        else{
            // Si le document référenceur est déjà existant, on incrémente.
            collection[DocumentCible].first[DocumentReferenceur]++;
            collection[DocumentCible].second++;
        }
    }
} //----- Fin de Méthode

void CollectionLog::Afficher()
// Algorithme :
//
{
    unordered_map<string, pair<unordered_map<string,int>,int>>::iterator it1;
    unordered_map<string,int>::iterator it2;
    for (it1 = collection.begin(); it1 != collection.end(); it1++){
		cout << "Document cible : " << it1->first << " et son nombre d'apparition : " << it1->second.second << endl;
		//cout << endl;
		for (it2 = it1->second.first.begin(); it2 != it1->second.first.end(); it2++){
			cout << "	Un référenceur : " << it2->first << " et son nombre d'apparition pour ce document : " << it2->second << endl;
			cout << endl;
		}
	}
} //----- Fin de Méthode

void CollectionLog::AfficherDecroissant(){
	long unsigned int i;
	long unsigned int n = 10;
	if (collection.size()<n){
		n = collection.size();
	}
	for (i = 0; i < n; i++){
		unordered_map<string, pair<unordered_map<string,int>,int>>::iterator it;
		string cible_max;
		int max = 0;
		for (it = collection.begin(); it != collection.end(); it++){
			if (it->second.second >= max){
				max = it->second.second;
				cible_max = it->first;
			}
		}
		cout << cible_max << " (" << max << " hits)" << endl;
		collection.erase(cible_max);
	}
}

void CollectionLog::ConceptionDot(string nomFichier){
    ifstream verification(nomFichier);
    // On vérifie si le fichier existe déjà.
    if (verification){
        cout << "ERREUR : Le fichier existe déjà." << endl;
        verification.close();
    }
    else{
        ofstream flux (nomFichier.c_str(), ios::app);
        if (!flux){
            cout << "ERREUR : Impossible d'ouvrir le fichier" << endl; // Si problème de droit ou espace disque saturé.
            flux.close();
        }
        else if (collection.size() == 0){
            cout << "Le graphe est vide." << endl;
            flux.close();
        }
        else{
            int cpt = 0;
            unordered_map<string, int> documents; // permet de stocker les documents déjà inscrit dans le fichier.
            unordered_map<string, pair<unordered_map<string,int>,int>>::iterator it1;
            unordered_map<string,int>::iterator it2;

            flux << "digraph {" << endl;
            // On commence par ajouter les noeuds pour chaque document cible et référenceur.
            for (it1 = collection.begin(); it1 != collection.end(); it1++){ // On parcourt les cibles.
                if (documents.count(it1->first)==0){ // On vérifie que le document n'a pas déjà été inscrit dans le fichier.
                    flux << "node" << cpt << "[label=\"" << it1->first << "\"];" << endl; // on créé le noeud pour le document cible.
                    documents[it1->first] = cpt; // on ajoute le document cible à la liste des documents inscrit dans le fichier.
                    cpt++;
                }
                for (it2 = it1->second.first.begin(); it2 != it1->second.first.end(); it2++){ // On parcourt les référenceurs de la cible.
                    if (documents.count(it2->first)==0){ // On vérifie que le référenceur n'a pas déjà été inscrit dans le fichier.
                        flux << "node" << cpt << "[label=\"" << it2->first << "\"];" << endl; // on créé le noeud pour le référenceur.
                        documents[it2->first] = cpt; // on ajoute le référenceur à la liste des documents inscrit dans le fichier. On lui attribue son numéro de noeud.
                        cpt++;
                    }
                }
            }
            // On ajoute les arcs entre chaque document cible et référenceurs.
            for (it1 = collection.begin(); it1 != collection.end(); it1++){ // On parcourt les cibles.
                for (it2 = it1->second.first.begin(); it2 != it1->second.first.end(); it2++){ // On parcourt les référenceurs de la cible.
                    flux << "node" << documents[it2->first] << " -> " << "node" << documents[it1->first] << " [label=\"" << it2->second << "\"];" << endl;
                }
            }
            flux << "}";;
            flux.close();
        }
    }
}

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur

CollectionLog::CollectionLog( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <CollectionLog>" << endl;
#endif
    
} //----- Fin de CollectionLog


CollectionLog::~CollectionLog( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <CollectionLog>" << endl;
#endif
} //----- Fin de ~CollectionLog


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

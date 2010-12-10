/*************************************************************************
 Parseur - Analyse un fichier pour y trouver des identificateurs C++
 -------------------
 début                : 19 nov. 2010
 copyright            : (C) 2010 par ssignoud et tpatel
 *************************************************************************/

// Comme autorisé (après demande) par les professeurs en séance de TP,
// ces fichiers sources utilisent la norme d'écriture Doxygen/Javadoc en
// lieu et place du « Guide de Style INSA » original.
// Ses conseils et ses principes de formatages (retours à la ligne et
// informations algorithmiques complémentaires) sont cependant conservés.

//===[ Réalisation de la classe <Parseur> (fichier Parseur.cpp) ]===

//================================================================ INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <string>
#include <cctype>

//------------------------------------------------------ Include personnel
#include "Parseur.h"

//================================================================= PUBLIC

/**
 * @algorithm Cet algorithme est disponible dans le dossier de
 * Spécification.
 */
pair<string, int>* Parseur::NextIdent()
{
    char c;
    bool estDansIdentif = false;
    string buffer = "";
    int nbreCar = 0;
    
    // Tant qu'il reste quelque chose à lire dans le fichier
    while(*fichier) {
        fichier->get(c);
        if(c == '\n') {
            // Mise à jour du numéro de ligne à chaque retour chariot
            currentLine++;
        }
        if((isalnum(c) || c == '_') && estDansIdentif) {
            nbreCar++;
            if(nbreCar > 256) {
                // Cas où l'identifiant est trop grand : il est ignoré
                buffer = "";
                estDansIdentif = false;
                nbreCar = 0;
            } else {
                // Tout va bien : on ajoute le caractère au buffer
                buffer += c;
            }
        } else if ( (!isalnum(c) && c != '_') && estDansIdentif) {
            // On vient de terminer un identifiant : on le retourne
            estDansIdentif = false;
            return new pair<string, int>(buffer, currentLine);
        } else if((isalpha(c) || c == '_') && !estDansIdentif) {
            // On découvre un nouveau caractère de début : on démarre
            // l'enregistrement de le buffer
            buffer = c;
            estDansIdentif = true;
            nbreCar = 1;
        }
    }
    // Plus rien à lire : le fichier est terminé. On retourne une
    // chaîne vide pour indiquer cet état de fait
    return new pair<string, int>("", -1);
} //----- Fin de NextIdent

//------------------------------------------------- Surcharge d'opérateurs

// Aucune : ifstream ne supporte pas la copie.

//-------------------------------------------- Constructeurs - destructeur

Parseur::Parseur(string fileName) :
    currentLine(1)
{
#ifdef MAP
    cout << "Appel au constructeur de <Parseur>" << endl;
#endif
    fichier = new ifstream(fileName.c_str());
} //----- Fin de Parseur

Parseur::~Parseur()
{
#ifdef MAP
    cout << "Appel au destructeur de <Parseur>" << endl;
#endif
    fichier->close();
    delete fichier;
} //----- Fin de ~Parseur


//================================================================== PRIVE

//----------------------------------------------------- Méthodes protégées

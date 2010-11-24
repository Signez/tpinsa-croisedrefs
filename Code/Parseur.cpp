/*************************************************************************
 Parseur  -  description
 -------------------
 début                : 19 nov. 2010
 copyright            : (C) 2010 par ssignoud
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

//------------------------------------------------------------- Constantes

//================================================================= PUBLIC

pair<string, int>* Parseur::NextIdent()
{
    char c;
    bool estDansIdentif = false;
    string buffer = "";
    int nbreCar = 0;
    while(fichier) {
        fichier.get(c);
        if(c == '\n') {
            currentLine++;
        } else if((isalnum(c) || c == '_') && estDansIdentif) {
            nbreCar++;
            if(nbreCar > 256) {
                buffer = "";
                estDansIdentif = false;
                nbreCar = 0;
            } else {
                buffer += c;
            }
        } else if ( (!isalnum(c) && c != '_') && estDansIdentif) {
            estDansIdentif = false;
            return new pair<string, int>(buffer, currentLine);
        } else if((isalpha(c) || c == '_') && !estDansIdentif) {
            buffer = "";
            estDansIdentif = true;
            nbreCar = 0;
        }
    }
    return NULL;
} //----- Fin de NextIdent

//------------------------------------------------- Surcharge d'opérateurs

/**
 * @algorithm
 */
Parseur & Parseur::operator =(const Parseur & unParseur)
{
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur

/**
 * @algorithm
 */
Parseur::Parseur(const Parseur & unParseur)
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Parseur>" << endl;
#endif
} //----- Fin de Parseur (constructeur de copie)


/**
 * @algorithm
 */
Parseur::Parseur()
{
#ifdef MAP
    cout << "Appel au constructeur de <Parseur>" << endl;
#endif
} //----- Fin de Parseur

Parseur::~Parseur()
{
#ifdef MAP
    cout << "Appel au destructeur de <Parseur>" << endl;
#endif
} //----- Fin de ~Parseur


//================================================================== PRIVE

//----------------------------------------------------- Méthodes protégées

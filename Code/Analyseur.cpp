/*************************************************************************
 Analyseur - Recherche les références contenues dans les fichiers.
 -------------------
 début                : 19 nov. 2010
 copyright            : (C) 2010 par ssignoud
 *************************************************************************/

// Comme autorisé (après demande) par les professeurs en séance de TP,
// ces fichiers sources utilisent la norme d'écriture Doxygen/Javadoc en
// lieu et place du « Guide de Style INSA » original.
// Ses conseils et ses principes de formatages (retours à la ligne et
// informations algorithmiques complémentaires) sont cependant conservés.

// ====[ Réalisation de la classe <Analyseur> (fichier Analyseur.cpp) ]===

//================================================================ INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Analyseur.h"

//------------------------------------------------------------- Constantes

//================================================================= PUBLIC


//------------------------------------------------- Surcharge d'opérateurs

/**
 * @algorithm
 */
Analyseur & Analyseur::operator =(const Analyseur & unAnalyseur)
{
    return *this;
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur

/**
 * @algorithm
 */
Analyseur::Analyseur(const Analyseur & unAnalyseur)
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Analyseur>" << endl;
#endif
} //----- Fin de Analyseur (constructeur de copie)


/**
 * @algorithm
 */
Analyseur::Analyseur()
{
#ifdef MAP
    cout << "Appel au constructeur de <Analyseur>" << endl;
#endif
} //----- Fin de Analyseur


/**
 * @algorithm
 */
Analyseur::~Analyseur()
{
#ifdef MAP
    cout << "Appel au destructeur de <Analyseur>" << endl;
#endif
} //----- Fin de ~Analyseur


//================================================================== PRIVE

//----------------------------------------------------- Méthodes protégées
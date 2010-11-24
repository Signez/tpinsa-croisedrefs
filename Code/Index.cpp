/*************************************************************************
 Index - Stocke des références vers des identifiants, fichiers et lignes
 -------------------
 début                : 19 nov. 2010
 copyright            : (C) 2010 par ssignoud et patel
 *************************************************************************/

// Comme autorisé (après demande) par les professeurs en séance de TP,
// ces fichiers sources utilisent la norme d'écriture Doxygen/Javadoc en
// lieu et place du « Guide de Style INSA » original.
// Ses conseils et ses principes de formatages (retours à la ligne et
// informations algorithmiques complémentaires) sont cependant conservés.

// =======[ Réalisation de la classe <Index> (fichier Index.cpp) ]========

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ INCLUDE

// ------------------------------------------------------- Include système

using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Index.h"

//------------------------------------------------------------- Constantes

// ================================================================ PUBLIC

//------------------------------------------------- Surcharge d'opérateurs

Index & Index::operator =(const Index & unIndex)
{
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur

Index::Index(const Index & unIndex)
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Index>" << endl;
#endif
} //----- Fin de Index (constructeur de copie)


Index::Index()
{
#ifdef MAP
    cout << "Appel au constructeur de <Index>" << endl;
#endif
} //----- Fin de Index


Index::~Index()
{
#ifdef MAP
    cout << "Appel au destructeur de <Index>" << endl;
#endif
} //----- Fin de ~Index


// ================================================================= PRIVE

//----------------------------------------------------- Méthodes protégées

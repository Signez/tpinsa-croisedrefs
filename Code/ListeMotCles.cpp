/*************************************************************************
 ListeMotCles - Stocke la liste des éléments.
 -------------------
 début                : 19 nov. 2010
 copyright            : (C) 2010 par ssignoud
 *************************************************************************/

// Comme autorisé (après demande) par les professeurs en séance de TP,
// ces fichiers sources utilisent la norme d'écriture Doxygen/Javadoc en
// lieu et place du « Guide de Style INSA » original.
// Ses conseils et ses principes de formatages (retours à la ligne et
// informations algorithmiques complémentaires) sont cependant conservés.

//=[ Réalisation de la classe <ListeMotCles> (fichier ListeMotCles.cpp) ]=

//================================================================ INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "ListeMotCles.h"

//------------------------------------------------------------- Constantes

//================================================================= PUBLIC


//------------------------------------------------- Surcharge d'opérateurs

/**
 * @algorithm
 */
ListeMotCles & ListeMotCles::operator =(const ListeMotCles & uneListeMotCles)
{
    ref = uneListeMotCles.ref;
    return *this;
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur

/**
 * @algorithm
 */
ListeMotCles::ListeMotCles(const ListeMotCles & uneListeMotCles)
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <ListeMotCles>" << endl;
#endif
    ref = uneListeMotCles.ref;
} //----- Fin de ListeMotCles (constructeur de copie)


/**
 * @algorithm
 */
ListeMotCles::ListeMotCles()
{
#ifdef MAP
    cout << "Appel au constructeur de <ListeMotCles>" << endl;
#endif
} //----- Fin de ListeMotCles


/**
 * @algorithm
 */
ListeMotCles::~ListeMotCles()
{
#ifdef MAP
    cout << "Appel au destructeur de <ListeMotCles>" << endl;
#endif
} //----- Fin de ~ListeMotCles


//================================================================== PRIVE

//----------------------------------------------------- Méthodes protégées

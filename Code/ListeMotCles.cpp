/*************************************************************************
 ListeMotCles - Stocke la liste des éléments.
 -------------------
 début                : 19 nov. 2010
 copyright            : (C) 2010 par ssignoud et tpatel
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
#include <string>

//------------------------------------------------------ Include personnel
#include "ListeMotCles.h"

//================================================================= PUBLIC

bool ListeMotCles::AddMotCle(string unMotCle)
{
    return ref.insert(unMotCle).second;
} //----- Fin de AddMotCle

bool ListeMotCles::IsMotCle(std::string unMotCle) const
{
    return ref.find(unMotCle) != ref.end();
} //----- Fin de IsMotCle

bool ListeMotCles::IsVide() const
{
    return ref.empty();
} //----- Fin de IsVide


//------------------------------------------------- Surcharge d'opérateurs

ListeMotCles & ListeMotCles::operator =(const ListeMotCles & uneListeMotCles)
{
    ref = uneListeMotCles.ref;
    return *this;
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur

ListeMotCles::ListeMotCles(const ListeMotCles & uneListeMotCles)
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <ListeMotCles>" << endl;
#endif
    ref = uneListeMotCles.ref;
} //----- Fin de ListeMotCles (constructeur de copie)

ListeMotCles::ListeMotCles()
{
#ifdef MAP
    cout << "Appel au constructeur de <ListeMotCles>" << endl;
#endif
    ref = set<string>();
} //----- Fin de ListeMotCles

ListeMotCles::~ListeMotCles()
{
#ifdef MAP
    cout << "Appel au destructeur de <ListeMotCles>" << endl;
#endif
} //----- Fin de ~ListeMotCles


//================================================================== PRIVE

//----------------------------------------------------- Méthodes protégées

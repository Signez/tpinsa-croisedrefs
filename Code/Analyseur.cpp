/*************************************************************************
 Analyseur - Recherche les références contenues dans les fichiers.
 -------------------
 début                : 19 nov. 2010
 copyright            : (C) 2010 par ssignoud et tpatel
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
#include <fstream>

//------------------------------------------------------ Include personnel
#include "Analyseur.h"
#include "ListeMotCles.h"
#include "Index.h"
#include "Parseur.h"

//================================================================= PUBLIC

/**
 * @algorithm Pour tous les fichiers, un Parseur est créé. On boucle
 * tant que ce parseur renvoie un identificateur, et on teste si cet
 * identificateur est un identifiant (ou mot clé). Si c'est le cas
 * ou si ça n'est pas le cas (selon le booléen motsExclus), on l'ajoute
 * à un Index créé en début de méthode. Une fois ces boucles terminées,
 * on renvoie l'index fraîchement rempli.
 */
Index * Analyseur::Run() {
    Index * index = new Index();
    // Pour tous les fichiers...
    for(vector<string>::iterator currFichier = nomsFichiers.begin() ; 
          currFichier != nomsFichiers.end(); ++currFichier)
    {
        Parseur fichpars(*currFichier);
        std::pair<std::string, int> * ident = fichpars.NextIdent();
        while(ident->first != ""){
          bool isMotCle = motscles.IsMotCle(ident->first);
          if((!motsExclus && isMotCle) || (motsExclus && !isMotCle)) {
            index->AddLine(ident->first, ident->second, *currFichier);
          }
          ident = fichpars.NextIdent();
        }
    }
    return index;
}

//------------------------------------------------- Surcharge d'opérateurs

Analyseur & Analyseur::operator =(const Analyseur & unAnalyseur)
{
    motscles = unAnalyseur.motscles;
    nomsFichiers = unAnalyseur.nomsFichiers;
    motsExclus = unAnalyseur.motsExclus;
	return *this;
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur

Analyseur::Analyseur(ListeMotCles listeMotCles, vector<string> fichiers, bool exclusion)
    : motscles(listeMotCles), nomsFichiers(fichiers), motsExclus(exclusion)
{
} //---- Fin de Analyseur (constructeur)

Analyseur::Analyseur(const Analyseur & unAnalyseur)
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Analyseur>" << endl;
#endif
    motscles = unAnalyseur.motscles;
    nomsFichiers = unAnalyseur.nomsFichiers;
    motsExclus = unAnalyseur.motsExclus;
} //----- Fin de Analyseur (constructeur de copie)

Analyseur::~Analyseur()
{
#ifdef MAP
    cout << "Appel au destructeur de <Analyseur>" << endl;
#endif
} //----- Fin de ~Analyseur


//================================================================== PRIVE

//----------------------------------------------------- Méthodes protégées

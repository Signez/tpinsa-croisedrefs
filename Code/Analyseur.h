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

// ======[ Interface de la classe <Analyseur> (fichier Analyseur.h) ]======

#if ! defined ( ANALYSEUR_H_ )
#define ANALYSEUR_H_

#include <set>
#include <string>
#include <vector>

#include "Index.h"

class Analyseur {

    public :
        //------------------------------------------------- Surcharge d'opérateurs

        // Aucune surcharge d'opérateur d'affectation. L'objet contient
        // un ifstream, qui ne gère pas la copie ; de plus, l'affectation
        // d'un parseur à un autre n'a pas de sens dans l'application.

        //-------------------------------------------- Constructeurs - destructeur

        // Aucun constructeur de copie. L'objet contient un ifstream, qui ne
        // gère pas la copie ; de plus, la construction d'un parseur à partir
        // d'un autre n'a pas de sens dans l'application.
        
        Analyseur(std::set<std::string> listeMotCles, std::vector<std::string> fichiers, bool exclusion);
        Index Run();
};

#endif // ANALYSEUR_H_

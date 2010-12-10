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

// ======[ Interface de la classe <Analyseur> (fichier Analyseur.h) ]======

#if ! defined ( ANALYSEUR_H_ )
#define ANALYSEUR_H_

//--------------------------------------------------- Interfaces utilisées
#include <set>
#include <string>
#include <vector>

#include "ListeMotCles.h"
#include "Index.h"

/**
 * Recherche les références contenues dans les fichiers.
 *
 * Cette classe effectue le travail demandé par Main, avec les fichiers
 * dont les noms sont donnés lors de sa construction. Il effectue ce
 * travail en faisant appel à la classe Parseur, et ajoute les occurences
 * trouvées à un Index.
 */
class Analyseur
{

    public :

        //----------------------------------------------------- Méthodes publiques

        /**
         * Lance l'analyseur.
         *
         * @return Un index prêt à être utilisé.
         */
        Index * Run();

        //------------------------------------------------- Surcharge d'opérateurs

        /**
         * Affecte les données d'unAnalyseur à l'analyseur.
         * @param unAnalyseur Analyseur d'où proviendront les données affectées
         * à l'analyseur.
         * @return L'analyseur, avec les données d'unAnalyseur.
         */
        Analyseur & operator =(const Analyseur & unAnalyseur);

        //-------------------------------------------- Constructeurs - destructeur

        /**
         * Construit un Analyseur.
         *
         * @param listeMotCles Liste de mots clés à rechercher (ou à ne pas rechercher)
         * dans les fichiers.
         * @param fichiers Vecteurs de noms de fichiers dans lesquels la recherche
         * doit se faire.
         * @param exclusion Booléen indiquant si les mots indiqués sont exclus de la
         * recherche (true) ou au contraire sont les seuls à être recherchés (false).
         */
        Analyseur(ListeMotCles listeMotCles, std::vector<std::string> fichiers, bool exclusion);

        /**
         * Construit un Analyseur à partir des données d'un autre (constructeur
         * par copie).
         * @param unAnalyseur Analyseur à partir duquel les données vont être copiées.
         */
        Analyseur(const Analyseur & unAnalyseur);

        /**
         * Détruit l'analyseur.
         */
        virtual ~Analyseur();

    protected:
        /**
         * Contient les mots clés à rechercher, renseignés lors de la construction
         * de l'objet.
         */
        ListeMotCles motscles;

        /**
         * Noms des fichiers qui doivent être analysés.
         */
        std::vector<std::string> nomsFichiers;

        /**
         * Indique si les mots clés inclus dans motscles sont à exclure, ou au
         * contraire s'ils sont les seuls à être retournés.
         */
        bool motsExclus;

};

#endif // ANALYSEUR_H_

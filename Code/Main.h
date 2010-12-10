/*************************************************************************
 Main - Gère les arguments et les éléments du programme
 -------------------
 début                : 19 nov. 2010
 copyright            : (C) 2010 par ssignoud et patel
 *************************************************************************/

// Comme autorisé (après demande) par les professeurs en séance de TP,
// ces fichiers sources utilisent la norme d'écriture Doxygen/Javadoc en
// lieu et place du « Guide de Style INSA » original.
// Ses conseils et ses principes de formatages (retours à la ligne et
// informations algorithmiques complémentaires) sont cependant conservés.

// ==========[ Interface de la classe <Main> (fichier Main.h) ]============

#if ! defined ( MAIN_H_ )
#define MAIN_H_

//--------------------------------------------------- Interfaces utilisées
#include "Analyseur.h"

/**
 * Gère les arguments et les éléments du programme.
 *
 * La méthode principale de cette classe (Run) analyse les arguments et
 * formate la sortie. Ce formatage n'est pas délégué à une autre classe,
 * car il est trop spécifique à l'utilitaire pour être réutilisé, tout
 * en prenant très peu de lignes de code grâce au report de la complexité
 * du parcours de l'index dans la classe Index.
 */
class Main
{
    //================================================================= PUBLIC
    public:
        //------------------------------------------------- Méthodes publiques
        /**
         * Démarre le programme, analyse les arguments passés par argc et argv,
         * effectue la recherche et affiche les résultats, ou les erreurs
         * le cas échéant.
         * @param argc Le nombre d'arguments de la ligne de commande.
         * @param argv Les arguments de la ligne de commande.
         * @return Le statut de l'application ; 0 si tout s'est bien passé
         * ou 1 si une erreur fatale s'est produite.
         */
        static int Run(int argc, const char* argv[]);

    //================================================================== PRIVÉ
    protected:
        //------------------------------------------------- Méthodes protégées
        /**
         * Affiche sur la sortie d'erreur standard une chaîne d'explication
         * de l'usage du programme, à-la-UNIX.
         *
         * @param nomprogramme Le nom du programme (typiquement argv[0]).
         */
        static void printUsage(const char* nomprogramme);
    
    
    
};

#endif // MAIN_H_

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

//========[ Interface de la classe <Parseur> (fichier Parseur.h) ]========

#if ! defined ( PARSEUR_H_ )
#define PARSEUR_H_

//--------------------------------------------------- Interfaces utilisées
#include <fstream>
#include <string>
//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types 

/**
 *
 */
class Parseur
{
        //================================================================= PUBLIC

    public:
        //----------------------------------------------------- Méthodes publiques

        /**
         * Cherche le prochain identifiant présent dans le fichier et le retourne
         * ainsi que sa position.
         *
         * @return Une paire composée de l'identifiant (chaîne) et d'un numéro
         * de ligne (positif non nul). Si aucun autre identifiant ne peut être
         * trouvé dans le fichier, retourne une paire contenant une chaîne vide
         * comme premier élément.
         */
        std::pair<std::string, int>* NextIdent();

        //------------------------------------------------- Surcharge d'opérateurs

        /**
         * Assigne le contenu de unParseur au parseur.
         */
        Parseur & operator =(const Parseur & unParseur);

        //-------------------------------------------- Constructeurs - destructeur

        /**
         * Construit un nouveau parseur par copie d'après unParseur.
         */
        Parseur(const Parseur & unParseur);

        /**
         * Construit un parseur chargeant le fichier au nom fileName.
         */
        Parseur(std::string fileName);

        /**
         * Détruit le parseur.
         */
        virtual ~Parseur();

        //================================================================== PRIVÉ

    protected:
        //----------------------------------------------------- Méthodes protégées

        //----------------------------------------------------- Attributs protégés

        /**
         * Numéro de la ligne actuellement analysée.
         */
        int currentLine;

        /**
         * Flux de lecture positionné sur le fichier.
         */
        std::ifstream* fichier;

};

//--------------------------- Autres définitions dépendantes de <Parseur>

#endif // PARSEUR_H_

/*************************************************************************
 Index - Stocke des références vers des identifiants, fichiers et lignes
 -------------------
 début                : 19 nov. 2010
 copyright            : (C) 2010 par ssignoud
 *************************************************************************/

// Comme autorisé (après demande) par les professeurs en séance de TP,
// ces fichiers sources utilisent la norme d'écriture Doxygen/Javadoc en
// lieu et place du « Guide de Style INSA » original.
// Ses conseils et ses principes de formatages (retours à la ligne et
// informations algorithmiques complémentaires) sont cependant conservés.

// ==========[ Interface de la classe <Index> (fichier Index.h) ]=========


#if ! defined ( INDEX_H_ )
#define INDEX_H_


// --- Inclusion des types de la STL
#include <string>
#include <map>
#include <list>

/**
 * Stocke des références vers des identifiants, contenus dans des fichiers
 * et des lignes.
 *
 * Pour utiliser efficacement cette classe, il est recommandé d'utiliser
 * une boucle testant si un nouvel identifiant, fichier ou ligne existe.
 * Les méthodes HasNextIdent et NextIdent vous permettront, par exemple,
 * de parcourir rapidement et clairement la liste des identifiants contenu
 * dans l'index.
 * Pour redémarrer le parcours du contenu de l'index, on utilisera Reset.
 */
class Index
{
        //================================================================= PUBLIC

    public:
    
        typedef std::pair< std::string, std::list<int>* > fichierLignes;
        typedef std::map< std::string, std::list<fichierLignes>* > identFichiers;
        
        //----------------------------------------------------- Méthodes publiques

        /**
         * Ajoute une référence à identifiant, placé à la ligne lineNum dans
         * le fichier nomFichier.
         *
         * Cette opération remet à zéro les méthodes de parcours de l'index.
         *
         * Contrat : nomFichier doit être le même fichier que la référence qui
         * vient d'être ajoutée, ou un nom de fichier qui n'a pas déjà été référencé
         * dans l'index pour l'identificateur indiqué.
         *
         * @param identifiant L'identifiant à référencer (chaîne non vide).
         * @param lineNum La ligne concernée (entier naturel non nul).
         * @param nomFichier Le fichier concerné (chaîne non vide).
         * @return Si l'opération se déroule sans encombres, true ; sinon, false.
         */
        bool AddLine(std::string identifiant, int lineNum, std::string nomFichier);

        /**
         * Indique si un autre identifiant existe dans l'index.
         *
         * @return S'il existe un autre identifiant, retourne true ; sinon, false.
         */
        bool HasNextIdent();

        /**
         * Indique si un autre fichier associé à l'identifiant courant existe dans l'index.
         *
         * @return S'il existe un autre fichier, retourne true ; sinon, false.
         */
        bool HasNextFile();

        /**
         * Indique s'il existe une autre ligne associée à l'identifiant courant dans l'index.
         *
         * @return S'il existe une autre ligne, retourne true ; sinon, false.
         */
        bool HasNextLine();

        /**
         * Récupère la prochaine ligne associée à l'identifiant en cours.
         *
         * @return La prochaine ligne, ou -1 si plus aucun autre ligne ne contient
         * l'identifiant.
         */
        int NextLine();

        /**
         * Récupère le prochain fichier où se situe l'identifiant en cours.
         *
         * @return Le prochain fichier, ou une chaîne vide si plus aucun autre fichier ne contient
         * l'identifiant.
         */
        std::string NextFile();

        /**
         * Récupère le prochain identifiant contenu dans l'index des références.
         *
         * @return Le prochain identifiant, ou une chaîne vide si la fin de l'index est atteinte.
         */
        std::string NextIdent();

        //------------------------------------------------- Surcharge d'opérateurs

        /**
         * Assigne le contenu d'unIndex dans l'index.
         *
         * @param unIndex L'index dont le contenu est copié.
         */
        Index & operator =(const Index & unIndex);

        //-------------------------------------------- Constructeurs - destructeur


        /**
         * Construit un nouvel Index à partir des données d'unIndex (constructeur
         * de copie).
         *
         * @param unIndex L'index dont le contenu est copié.
         */
        Index(const Index & unIndex);

        /**
         * Construit un nouvel Index vide.
         */
        Index();

        /**
         * Dértuit l'index.
         */
        virtual ~Index();

        //================================================================== PRIVÉ

    protected:
        //----------------------------------------------------- Méthodes protégées

        void resetIterators();

        //----------------------------------------------------- Attributs protégés
        /**
         * Contient les données de l'index.
         *
         * Représentation rapide (syntaxe YAML) :
         *   world:
         *     - (fichier1.cpp, [1, 2, 8, 12])
         *     - (fichier2.cpp, [3, 4, 5, 12])
         *     - (fichier3.cpp, [15, 16, 23, 42])
         *   test:
         *     - (fichier1.cpp, [4, 8])
         *     - (fichier5.cpp, [2])
         */
        identFichiers refs;
        
        /**
         * Indique si les itérateurs internes sont valides ou non.
         * 
         * Typiquement, dès qu'une insertion est effectuée, les itérateurs
         * ne sont plus utilisables. AddLine mets alors areItValid à false
         * et les méthodes utilisant les itérateurs testent si areItValid 
         * est vrai ; sinon, la méthode resetIterators est appelée.
         */
        bool areItValid;
        
        /**
         * Contient l'itérateur utilisé pour parcourir les identifiants.
         */
        identFichiers::iterator itIdent;
        
        /**
         * Itérateur pointant sur l'identifiant courant.
         */
        identFichiers::iterator curIdent;
        
        /**
         * Contient l'itérateur actuel sur les fichiers.
         */
        std::list<fichierLignes>::iterator itFichier;
        
        /**
         * Itérateur pointant sur le fichier courant.
         */
        std::list<fichierLignes>::iterator curFichier;
        
        /**
         * Contient l'itérateur actuel sur les lignes.
         */
        std::list<int>::iterator itLigne;
        
        /**
         * Itérateur pointant sur la ligne courante.
         */
        std::list<int>::iterator curLigne;
};

//--------------------------- Autres définitions dépendantes de <Index>

#endif // INDEX_H_

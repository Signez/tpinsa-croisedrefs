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

// ===[ Interface de la classe <ListeMotCles> (fichier ListeMotCles.h) ]===

#if ! defined ( LISTEMOTCLES_H_ )
#define LISTEMOTCLES_H_

/**
 * Stocke la liste des éléments et rends aisé le fait de tester si un
 * mot est présent dans cette liste ou non.
 */
class ListeMotCles
{
        //================================================================= PUBLIC

    public:
        //----------------------------------------------------- Méthodes publiques

        /**
         * Ajoute un mot clé à la liste.
         *
         * @return Si le mot clé existe déjà ou n'a pas pu être inséré, false ;
         * sinon, true.
         */
        bool AddMotCle(string unMotCle);

        /**
         * Vérifie si un mot clé est déjà dans la liste.
         *
         * @return Si le mot clé est dans la liste, true ; sinon, false.
         */
        bool IsMotCle(string unMotCle) const;

        //------------------------------------------------- Surcharge d'opérateurs

        /**
         * Remplace la liste des mots clés par celle d'uneAutreListe.
         */
        ListeMotCles & operator =(const ListeMotCles & uneAutreListe);

        //-------------------------------------------- Constructeurs - destructeur

        /**
         * Crée une nouvelle liste de mot clés, contenant la liste de mots clés
         * d'uneAutreListe de mots clés.
         */
        ListeMotCles(const ListeMotCles & uneAutreListe);

        /**
         * Construit une nouvelle liste de mots clés.
         */
        ListeMotCles();

        /**
         * Détruit la liste de mots clés.
         */
        virtual ~ListeMotCles();

        //================================================================== PRIVÉ

    protected:
        //----------------------------------------------------- Méthodes protégées

        //----------------------------------------------------- Attributs protégés

        /**
         * Contient la liste des mots clés.
         */
        std::set<string> ref;
};

//--------------------------- Autres définitions dépendantes de <ListeMotCles>

#endif // LISTEMOTCLES_H_

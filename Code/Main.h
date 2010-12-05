/*************************************************************************
 Main - Gère le programme
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

#include "Analyseur.h"

class Main
{
    protected:
        Analyseur* unAnalyseur;
        void printUsage(const char* nomprogramme);
    
    public:
        Main(int argc, const char* argv[]);
    
};

#endif // MAIN_H_

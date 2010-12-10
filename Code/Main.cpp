/*************************************************************************
 Main  -  Gère les arguments et les éléments du programme
 -------------------
 début                : 19 nov. 2010
 copyright            : (C) 2010 par ssignoud et tpatel
 *************************************************************************/

// Comme autorisé (après demande) par les professeurs en séance de TP,
// ces fichiers sources utilisent la norme d'écriture Doxygen/Javadoc en
// lieu et place du « Guide de Style INSA » original.
// Ses conseils et ses principes de formatages (retours à la ligne et
// informations algorithmiques complémentaires) sont cependant conservés.

// Vous recherchez le point d'entrée du programme ?
// Il a été séparé de ce fichier et se trouve dans LeMain.cpp, pour plus
// de clareté, bien que son contenu n'aie pas grand intérêt.

// ========[ Réalisation de la classe <Main> (fichier Main.cpp) ]========

//================================================================ INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <string>
#include <set>
#include <fstream>
#include <iostream>
#include <vector>

//------------------------------------------------------ Include personnel

#include "Main.h"
#include "Parseur.h"

//================================================================= PUBLIC

/**
 * @algorithm La gestion des arguments et des erreurs se fait au fur et à mesure de
 * l'analyse de la ligne de commande, qui se fait séquentiellement.
 * L'affiche ne pose pas de problème en soit, en utilisant les méthodes pratiques
 * proposées par la classe Index.
 */
int Main::Run(int argc, const char* argv[])
{
    // Contient le paramètre actuellement analysé
    int paramCounter = 1;

    // Doit-on exclure ou non les mots clés indiqués ?
    bool exclusion = true;

    if(argc - 1 == 0)
    {
        // Aucune action demandée ? Rappelons le mode d'emploi...
        printUsage(argv[0]);
        return 1;
    }

    //Contient l'argument courant
    string tmpArg = argv[paramCounter];

    if(tmpArg	== "-e")
    {
        exclusion = false;
        paramCounter++;
    }

    if(argc-paramCounter == 0)
    {
        cerr << "E: Aucun fichier à analyser." << endl;
        printUsage(argv[0]);
        return 2;
    }
    
    //Contient la liste des mots clés
    ListeMotCles listeMotCles; 
    
    //Contient l'argument courant
    tmpArg = argv[paramCounter];

    if(tmpArg == "-k") 
    {
        paramCounter++;
        if(argc-paramCounter == 0)
        {
            cerr << "E: Aucun fichier de mot clé à analyser." << endl;
            printUsage(argv[0]);
            return 3;
        }
        
        // Contient l'argument courant
        tmpArg = argv[paramCounter];

        // On teste si le fichier existe...
        ifstream* fMotCles = new ifstream(tmpArg.c_str());
        if(!fMotCles)
        {
            cerr << "E: Le fichier de mots clés n'est pas accessible ou n'existe pas." << endl;
            return 4;
        }
        delete fMotCles; // On le supprime : il n'a été créé que tester son accessiblité

        // Le fichier avec le nom tmpArg existe, donc on peut créer un parseur pour ce fichier...

        Parseur parseur(tmpArg);

        // ...et l'utiliser
        string motcle = parseur.NextIdent()->first;
        while(motcle != "")
        {
            listeMotCles.AddMotCle(motcle);
            motcle = parseur.NextIdent()->first;
        }

        if(listeMotCles.IsVide())
        {
            cerr << "E: Le fichier de mots clés n'est pas valide." << endl;
            return 5;
        }
        
        paramCounter++;
        
    }
    else
    {
        // Création de la liste des mot clés du C++ par défaut
        // Cette liste est incorporée pour augmenter la portabilité de l'application
        // (pas besoin de fichiers annexes).
        const int NB_MOTCLES = 63;
        string mots[NB_MOTCLES] = {"asm", "auto", "bool", "break", "case", "catch", "char", 
                                   "class", "const", "const_cast", "continue", "default",
                                   "delete", "do", "double", "dynamic_cast", "else", "enum",
                                   "explicit", "export", "extern", "false", "float", "for",
                                   "friend", "goto", "if", "inline", "int", "long", "mutable",
                                   "namespace", "new", "operator", "private", "protected",
                                   "public", "register", "reinterpret_cast", "return",
                                   "short", "signed", "sizeof", "static", "static_cast",
                                   "struct", "switch", "template", "this", "throw", "true",
                                   "try", "typedef", "typeid", "typename", "union", "unsigned",
                                   "using", "virtual", "void", "volatile", "wchar_t", "while"};
        for(int i=0; i<NB_MOTCLES; i++)
        {
            listeMotCles.AddMotCle(mots[i]);
        }
    }
      
    if(argc - paramCounter == 0)
    {
        cerr << "E: La liste des fichiers à analyser est vide.";
        return 10;
    }
    
    vector<string> listFichiers(argc - paramCounter);
    
    for(int i = paramCounter; i < (int) argc; i++)
    {
        // On vérifie si les fichiers existent bien, dès maintenant
        ifstream unFichier;
        unFichier.open(argv[i]);
        if(!unFichier) {
            cerr << "E: Le fichier " << argv[i]
                 << " est inconnu ou inaccessible en lecture." << endl;
            return 11;
        }
        listFichiers[i - paramCounter] = argv[i];
    }
    
    
    Analyseur unAnalyseur(listeMotCles, listFichiers, exclusion);

    //Lancement de l'analyse des fichiers
    Index * lindex = unAnalyseur.Run();

    // Si la recherche n'a retourné absolument aucun résultat...
    if(!lindex->HasNextIdent()){
        cerr << "W: La recherche des mots clés n'a donné aucun résultat." << endl;
        return 0; // Ce n'est pas une erreur : code d'erreur nul
    }
    
    // Affichage du résultat de la recherche, en moins de quinze lignes ;
    // toute la complexité du parcours de l'arbre/la map est située du
    // côté de l'Index et est masquée à l'utilisateur de l'objet
    while(lindex->HasNextIdent())
    {
        cout << lindex->NextIdent();

        while(lindex->HasNextFile())
        {
            cout << "\t" << lindex->NextFile();

            while(lindex->HasNextLine())
            {
                cout << " " << lindex->NextLine();
            }
        }
        cout << endl;
    }

    return 0;
}

//================================================================== PRIVE

//----------------------------------------------------- Méthodes protégées

void Main::printUsage(const char * nomprogramme)
{
    cerr << "Usage: " << nomprogramme << " [-e] [-k <keyword file>] file1 [file2 ...]" << endl;
}

#include <string>
#include <set>
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

#include "Main.h"
#include "Parseur.h"

/**
 
 */
int Main::Run(int argc, const char* argv[])
{
    // Contient le paramètre actuellement analysé
    int paramCounter = 0;

    // Nom du fichier contenant les mots-clés (si indiqués)
    string fichierMotCles = "";

    // Doit-on exclure ou non les mots clés indiqués ?
    bool exclusion = true;

    if(argc - 1 == 0)
    {
        // Aucune action demandée ? Rappelons le mode d'emploi...
        printUsage(argv[0]);
        return 0;
    }

    string preArg = argv[1];

    if(preArg.compare("-e")) {
        exclusion = false;
        paramCounter++;
        if(argc == 1) {
            cerr << "E: Aucun fichier à analyser." << endl;
            printUsage(argv[0]);
            return 0;
        }
    }
    
    ListeMotCles listeMotCles;
    
    //sizeof(argv[paramCounter])/sizeof(char) donne la taille de la chaine de caractère courante
    if(sizeof(argv[paramCounter])/sizeof(char) > 2 && argv[paramCounter][0] == '-' && argv[paramCounter][1] == 'k')
    {
        string arg = argv[paramCounter];
        fichierMotCles = arg.substr(2, arg.length()-2);
        paramCounter++;
        ifstream* fMotCles = new ifstream(fichierMotCles.c_str());
        if(fMotCles->bad()) {
            //TODO: ERREUR
            cout << "erreur non supportée";
        }

        Parseur parseur(fichierMotCles); //On utilise la chaine de caractère qui indique le flux déjà testé

        string motcle = parseur.NextIdent()->first;
        while(motcle != "")
        {
            listeMotCles.AddMotCle(motcle);
            motcle = parseur.NextIdent()->first;
        }

        if(listeMotCles.IsVide()) {
            //TODO: ERREUR
            cout << "erreur non supportée";
        }
        
    }
    else
    {
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
        set<string>* listeMotCles = new set<string>();
        for(int i=0; i<NB_MOTCLES; i++)
        {
            listeMotCles->insert(mots[i]);
        }
    }
    
    if(argc - paramCounter <=0)
    {
            //TODO: ERREUR
            cout << "erreur non supportée";
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
            return 0;
        }
        listFichiers[i - paramCounter] = argv[i];
    }
    
    Analyseur unAnalyseur(listeMotCles, listFichiers, exclusion);

    Index * lindex = unAnalyseur.Run();
    
    while(lindex->HasNextIdent()){
      cout << lindex->NextIdent();
        
      while(lindex->HasNextFile()){
        cout << "\t" << lindex->NextFile();
        
        while(lindex->HasNextLine()){
          cout << " " << lindex->NextLine();
        }
        
        cout << endl;
      }
    }

    return 0;
}

void Main::printUsage(const char * nomprogramme)
{
    cerr << "Usage: " << nomprogramme << " [-e] [-k <keyword file>] file1 [file2 ...]" << endl;
}

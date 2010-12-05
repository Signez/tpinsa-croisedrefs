#include <string>
#include <set>
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

#include "Main.h"

Main::Main(int argc, const char* argv[])
{
    int paramCounter = 0;
    string fichierMotCles = "";
    bool exclusion = true;
    if(argc == 0) {
        //TODO: ERREUR
        cout << "erreur non supportée";
    }
    if(strcmp(argv[0], "-e") == 0) {
        exclusion = false;
        paramCounter++;
        if(argc == 1) {
            //TODO: ERREUR
            cout << "erreur non supportée";
        }
    }
    
    set<string>* listeMotCles;
    
    //sizeof(argv[paramCounter])/sizeof(char) donne la taille de la chaine de caractère courante
    if(sizeof(argv[paramCounter])/sizeof(char) > 2 && argv[paramCounter][0] == '-' && argv[paramCounter][1] == 'k')
    {
        string arg(argv[paramCounter]);
        fichierMotCles = arg.substr(2, arg.length()-2);
        paramCounter++;
        ifstream* fMotCles = new ifstream(fichierMotCles.c_str());
        if(fMotCles->bad()) {
            //TODO: ERREUR
            cout << "erreur non supportée";
        }
        Parseur parseur(fichierMotCles); //On ne se sert pas du flux ?
        //listeMotCles = Parseur.parser(fMotCles);
        if(listeMotCles->empty()) {
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
    
    if(argc-paramCounter <=0)
    {
            //TODO: ERREUR
            cout << "erreur non supportée";
    }
    
    string listFichiers[] = new string[argc-paramCounter];
    
    for(int i=0; i<argc-paramCounter; i++)
    {
        listFichiers[i] = argv[paramCounter+i];
    }
    
    unAnalyseur = new Analyseur(listeMotCles, listFichiers, exclusion);

}

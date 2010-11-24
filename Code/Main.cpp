#include <string>
#include <cstring>
#include <set>

int main( int argc, const char* argv[] )
{
    int paramCounter = 0;
    string fichierMotCles = "";
    bool exclusion = true;
    if(argc == 0) {
        //TODO: ERREUR
    }
    if(strcmp(argv[0], "-e") == 0) {
        exlusion = false;
        paramCounter++;
        if(argc == 1) {
            //TODO: ERREUR
        }
    }
    
    set* listeMotCles = new set<string>();
    
    if(argv[paramCounter][0] == '-' && argv[paramCounter][1] == 'k') //TODO : tester si la argv[paramCounter] a bien une longueur >=2
    {
        fichierMotCles
    }
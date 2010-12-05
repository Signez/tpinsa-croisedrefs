
#if ! defined ( ANALYSEUR_H_ )
#define ANALYSEUR_H_

#include <set>
#include <string>

#include "Index.h"

class Analyseur {

    public :
        Analyseur(set<string> listeMotCles, string fichiers[], bool exclusion);
        Index Run();
        
}

#endif // ANALYSEUR_H_

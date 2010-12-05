
#if ! defined ( ANALYSEUR_H_ )
#define ANALYSEUR_H_

#include <set>
#include <string>
#include <vector>

#include "Index.h"

class Analyseur {

    public :
        Analyseur(std::set<std::string> listeMotCles, std::vector<std::string> fichiers, bool exclusion);
        Index Run();
        
};

#endif // ANALYSEUR_H_

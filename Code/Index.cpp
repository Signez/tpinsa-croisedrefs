/*************************************************************************
 Index - Stocke des références vers des identifiants, fichiers et lignes
 -------------------
 début                : 19 nov. 2010
 copyright            : (C) 2010 par ssignoud et patel
 *************************************************************************/

// Comme autorisé (après demande) par les professeurs en séance de TP,
// ces fichiers sources utilisent la norme d'écriture Doxygen/Javadoc en
// lieu et place du « Guide de Style INSA » original.
// Ses conseils et ses principes de formatages (retours à la ligne et
// informations algorithmiques complémentaires) sont cependant conservés.

// =======[ Réalisation de la classe <Index> (fichier Index.cpp) ]========

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ INCLUDE

// ------------------------------------------------------- Include système

using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Index.h"

//------------------------------------------------------------- Constantes

// ================================================================ PUBLIC

bool Index::AddLine(std::string identifiant, int lineNum, std::string nomFichier)
{
    // Les structures internes sont modifiées. On invalide les itérateurs
    // de lecture pour éviter des erreurs légitimes et forcer leur 
    // réinitialisation.
    areItValid = false;
    
    identFichiers::iterator it;
    it = refs.find(identifiant);
    if (it == refs.end())
    {
        list<int>* lignes = new list<int>();
        lignes->push_back(lineNum);
        
        list<fichierLignes>* liste = new list<fichierLignes>();
        liste->push_back(make_pair(nomFichier, lignes));
        return refs.insert(make_pair(identifiant, liste)).second;
    }
    else if ( (it->second->back().first) != nomFichier)
    {
        list<int>* lignes = new list<int>();
        lignes->push_back(lineNum);
        
        it->second->push_back(make_pair(nomFichier, lignes));
        return true;
    }
    else if( (it->second->back().second->back()) != lineNum)
    //On parse linéairement les fichiers, il suffit donc de vérifier que la dernière
    //ligne mémorisée (pour cet identifiant dans ce fichier) n'est pas celle que
    //l'on veut ajouter
    {
        it->second->back().second->push_back(lineNum);
        return true;
    }
    return false;
} //----- Fin de AddLine

bool Index::HasNextIdent()
{
  if(!areItValid) resetIterators();
  return itIdent != refs.end();
}

bool Index::HasNextFile()
{
  if(!areItValid) resetIterators();
  return itFichier != curIdent->second->end();
}

bool Index::HasNextLine()
{
  if(!areItValid) resetIterators();
  return itLigne != curFichier->second->end();
}

string Index::NextIdent()
{
  string retour = itIdent->first;
  curIdent = itIdent;
  ++itIdent;
  curFichier = curIdent->second->begin();
  itFichier = curFichier;
  return retour;
}

string Index::NextFile()
{
  string retour = itFichier->first;
  curFichier = itFichier;
  ++itFichier;
  curLigne = curFichier->second->begin();
  itLigne = curLigne;
  return retour;
}

int Index::NextLine()
{
  int retour = *itLigne;
  curLigne = itLigne;
  ++itLigne;
  return retour;
}


//------------------------------------------------- Surcharge d'opérateurs

Index & Index::operator =(const Index & unIndex)
{
  refs = unIndex.refs;
  resetIterators();
  return *this;
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur

Index::Index(const Index & unIndex)
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Index>" << endl;
#endif
  refs = unIndex.refs;
  resetIterators();
} //----- Fin de Index (constructeur de copie)


Index::Index()
{
#ifdef MAP
    cout << "Appel au constructeur de <Index>" << endl;
#endif
} //----- Fin de Index


Index::~Index()
{
#ifdef MAP
    cout << "Appel au destructeur de <Index>" << endl;
#endif
} //----- Fin de ~Index


// ================================================================= PRIVE

//----------------------------------------------------- Méthodes protégées

void Index::resetIterators()
{
  itIdent = refs.begin();
  itFichier = refs.begin()->second->begin();
  itLigne = refs.begin()->second->begin()->second->begin();
  curIdent = refs.begin();
  curFichier = refs.begin()->second->begin();
  curLigne = refs.begin()->second->begin()->second->begin();
  areItValid = true;
}

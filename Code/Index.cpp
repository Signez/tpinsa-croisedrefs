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
    cout << "Ajout d'une ligne " << lineNum 
         << " pour l'identifiant " << identifiant << " (fichier " 
         << nomFichier << ")" << endl;
    if (it == refs.end())
    {
        list<int>* lignes = new list<int>();
        lignes->push_back(lineNum);
        
        list<fichierLignes>* liste = new list<fichierLignes>();
        liste->push_back(make_pair(nomFichier, lignes));
        cout << "Ping..." << endl;
        return refs.insert(make_pair(identifiant, liste)).second;
    }
    else if ( (it->second->back().first) != nomFichier)
    {
        list<int>* lignes = new list<int>();
        lignes->push_back(lineNum);
        
        it->second->push_back(make_pair(nomFichier, lignes));
        cout << "Pang..." << endl;
        return true;
    }
    else if( (it->second->back().second->back()) != lineNum)
    //On parse linéairement les fichiers, il suffit donc de vérifier que la dernière
    //ligne mémorisée (pour cet identifiant dans ce fichier) n'est pas celle que
    //l'on veut ajouter
    {
        it->second->back().second->push_back(lineNum);
        cout << "Pong..." << endl;
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
  return itFichier != itIdent->second->end();
}

bool Index::HasNextLine()
{
  if(!areItValid) resetIterators();
  return itLigne != itFichier->second->end();
}

string Index::NextIdent()
{
  itIdent++;
  return itIdent->first;
}

string Index::NextFile()
{
  itFichier++;
  return itFichier->first;
}

int Index::NextLine()
{
  itLigne++;
  return *itLigne;
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
  itFichier = itIdent->second->begin();
  itLigne = itFichier->second->begin();
  areItValid = true;
}

//
// Created by lucas on 20/01/2021.
//

using namespace std;

#include <iostream>
#include <string>
#include <map>

#include "Log.h"
#include "Graphe.h"

Graphe::Graphe()
{

}

void Graphe::Ajouter(Log *log)
{
    sommet2sommet.emplace(log->referer, log->destURL);

    map<string , int>::iterator it;
    it = sommet2hit.find(log->destURL);
    if (it != sommet2hit.end())
        sommet2hit[log->destURL]++;
    else
        sommet2hit.emplace(log->destURL, 1);
}

void Graphe::ToString()
{
    for (map<string, string>::iterator it = sommet2sommet.begin(); it != sommet2sommet.end(); ++it)
    {
        cout << it->first << " => " << it->second << " : " << sommet2hit[it->second] << " hits" << endl;
    }
}

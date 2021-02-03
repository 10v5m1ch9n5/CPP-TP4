//
// Created by lucas on 20/01/2021.
//

using namespace std;

#include <string>
#include <map>

#include "Log.h"
#include "Graphe.h"

Graphe::Graphe()
{

}

void Graphe::Ajouter(Log *log)
{
    pair<string,string> nouv(log->referer, log->destURL);

    page2int.emplace(log->referer, page2int.size());
    page2int.emplace(log->destURL, page2int.size());

    map<pair<string,string>,int>::iterator it;
    it = graphe.find(nouv);
    if (it != graphe.end())
        graphe[nouv]++;
    else
        graphe.emplace(nouv, 1);
}

void Graphe::ToString(ofstream & fs)
{
    fs << "digraph {" << endl;

    for (map<string, int>::iterator it = page2int.begin(); it != page2int.end(); ++it)
    {
        fs << "node" << it->second << " [label=\"" << it->first << "\"];" << endl;
    }

    for (map < pair < string, string >, int > ::iterator it = graphe.begin(); it != graphe.end();
    ++it)
    {
        fs << "node" << page2int[it->first.first] << " -> node" << page2int[it->first.second] << " [label=\""
             << it->second << "\"];" << endl;
    }

    fs << "}" << endl;
}

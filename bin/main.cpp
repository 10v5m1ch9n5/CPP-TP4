//
// Created by lucas on 13/01/2021.
//
using namespace std;

#include <cstring>
#include <iostream>
#include <fstream>
#include <stdlib.h>

#include "Log.h"
#include "Graphe.h"
#include "HitCounter.h"

int main(int argc, char** argv)
{
    Graphe g;
    bool graphe, htmlSeulement, temps;
    char* nomGraphe;
    int heure = -1;
    char* nomFichier = new char [25];

    int iOption = 1;
    while (iOption < argc-1)
    {
#ifdef DEBUG
        cout << "Traitement de " << argv[iOption] << endl;
#endif
        if (strcmp(argv[iOption], "-g") == 0)
        {
            nomGraphe = new char [strlen(argv[++iOption])];
            strcpy(nomGraphe, argv[iOption]);
            graphe = true;
        }
        if (strcmp(argv[iOption], "-e") == 0)
        {
            htmlSeulement = true;
        }
        if (strcmp(argv[iOption], "-t") == 0)
        {
            heure = atoi(argv[++iOption]);
        }
        iOption++;
    }
    strncpy(nomFichier, argv[iOption++], 25);
    string filename(nomFichier);
    delete[] nomFichier;

    // Log parsing
    ifstream logfile(filename);
    if (!logfile.is_open())
    {
        cerr << "Impossible d'ouvrir le fichier !" << endl;
        return 1;
    }

    HitCounter hc;
    while (!logfile.eof())
    {
        Log* log = new Log(logfile);
#ifdef DEBUG_L
        log->ToString(1);
        cout << "--------------------------------------" << endl;
#endif
        if (log->destURL.length() > 0)
        {
            if (graphe)
            {
                g.Ajouter(log);
                cout << "Ajout de " << log->referer << "=>" << log->destURL << endl;
            }
            hc.Incrementer(log->destURL);
        }
#ifdef DEBUG_G
        g.ToString();
#endif
        delete log;
    }

    if (graphe)
        g.ToString();
    hc.ToString();

    return 0;
#ifdef DEBUG
    cout << "Nom Fichier : " << nomFichier << endl;
    cout << "nomGraphe : " << nomGraphe << endl;
    cout << "html seulement : " << htmlSeulement << endl;
    cout << "heure : " << heure << endl;
#endif
}

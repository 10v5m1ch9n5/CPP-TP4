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
    bool graphe = false, htmlSeulement = false, temps = false;
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
            cout << "Warning : only hits between " << heure << "h and " << heure+1 << "h have been taken into account" << endl;
            temps = true;
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
            if (htmlSeulement && !log->isHTML)
                continue;
            if (temps && heure != log->heure)
                continue;
            if (graphe)
                g.Ajouter(log);

            hc.Incrementer(log->destURL);
        }
#ifdef DEBUG_G
        g.ToString();
#endif
        delete log;
    }

    if (graphe)
    {
        ofstream graphvz(nomGraphe);
        g.ToString(graphvz);
        cout << "Dot-file " << nomGraphe << " generated" << endl;
        graphvz.close();
    }
    hc.ToString();

    return 0;
#ifdef DEBUG
    cout << "Nom Fichier : " << nomFichier << endl;
    cout << "nomGraphe : " << nomGraphe << endl;
    cout << "html seulement : " << htmlSeulement << endl;
    cout << "heure : " << heure << endl;
#endif
}

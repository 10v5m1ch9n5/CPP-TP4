//
// Created by lucas on 13/01/2021.
//
using namespace std;

#include <cstring>
#include <iostream>
#include <fstream>
#include <stdlib.h>

#include "Log.h"

int main(int argc, char** argv)
{
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

    // Log parsing
    string filename(nomFichier);
    ifstream logfile(filename);
    if (!logfile.is_open())
    {
        cerr << "Impossible d'ouvrir le fichier !" << endl;
        return 1;
    }

    while (!logfile.eof())
    {
        Log* log = new Log(logfile);
        log->ToString(1);
        cout << "--------------------------------------" << endl;
        delete log;
    }

    return 0;
#ifdef DEBUG
    cout << "Nom Fichier : " << nomFichier << endl;
    cout << "nomGraphe : " << nomGraphe << endl;
    cout << "html seulement : " << htmlSeulement << endl;
    cout << "heure : " << heure << endl;
#endif
}

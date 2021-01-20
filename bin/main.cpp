//
// Created by lucas on 13/01/2021.
//
#include <cstring>
#include <iostream>
#include <stdlib.h>
using namespace std;

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
#ifdef DEBUG
    cout << "Nom Fichier : " << nomFichier << endl;
    cout << "nomGraphe : " << nomGraphe << endl;
    cout << "html seulement : " << htmlSeulement << endl;
    cout << "heure : " << heure << endl;
#endif
}

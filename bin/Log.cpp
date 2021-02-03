//
// Created by lucas on 20/01/2021.
//

#include <fstream>
#include <iostream>
#include <cstring>
#include <regex>
using namespace std;

#include "Log.h"

Log::Log(std::ifstream &fs)
{
    getline(fs, ip, ' ');
    getline(fs, userLogName, ' ');
    getline(fs, authenticatedUser, '[');
    getline(fs, dateHeure, ']');
    fs.ignore(1);
    getline(fs, typeRequete, ' ');
    getline(fs, destURL, ' ');
    getline(fs, versionHTTP, ' ');
    getline(fs, returnCode, ' ');
    getline(fs, qteDonnees, ' ');
    getline(fs, referer, ' ');
    getline(fs, userAgent, '\n');

    if (fs.eof())
        return;

    heure = stoi(dateHeure.substr(12, 2));

    // Enlever les guillemets
    referer.erase(referer.begin());
    referer.erase(referer.end()-1);
    // Enlever le domaine si la page est locale
    if (referer.substr(0, 31) == "http://intranet-if.insa-lyon.fr")
        referer.erase(0, 31);

    isHTML = regex_match(destURL, regex(".*\\.html"));
    // cout << destURL << " : " << isHTML << endl;
}

void Log::ToString(int verbose)
{
    cout << "BEGIN TOSTRING" << endl;
    switch (verbose)
    {
        case 0:
            cout << "HEURE=" << heure << endl;
            cout << "SOURCE=" << referer << endl;
            cout << "DEST=" << destURL << endl;
            break;
        case 1:
            cout << "Addresse IP : " << ip << endl;
            cout << "User Log Name : " << userLogName << endl;
            cout << "Authenticated User : " << authenticatedUser << endl;
            cout << "Horodatage : " << dateHeure << endl;
            cout << "Requete HTTP : " << typeRequete << " " << destURL << " " << versionHTTP << endl;
            cout << "Statut de la requete : " << returnCode << endl;
            cout << "Quantite de donnees : " << qteDonnees << endl;
            cout << "Referer : " << referer << endl;
            cout << "User Agent : " << userAgent << endl;
            break;
    }
    cout << "END TOSTRING" << endl;
}
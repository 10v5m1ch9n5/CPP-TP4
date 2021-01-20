//
// Created by lucas on 20/01/2021.
//

#ifndef CPP_TP4_LOG_H
#define CPP_TP4_LOG_H

#include <fstream>

class Log
{
private:
    std::string ip;
    std::string userLogName;
    std::string authenticatedUser;
    std::string dateHeure;
    std::string typeRequete;
    std::string destURL;
    std::string versionHTTP;
    std::string returnCode;
    std::string qteDonnees;
    std::string referer;
    std::string userAgent;
    int heure;

public:
    Log(std::ifstream & fs);
    void ToString(int verbose);
};


#endif //CPP_TP4_LOG_H

//
// Created by lucas on 20/01/2021.
//

#ifndef CPP_TP4_GRAPHE_H
#define CPP_TP4_GRAPHE_H

#include <map>
#include <string>
#include <fstream>
#include "Log.h"


class Graphe
{
private:
    std::map<std::pair<std::string,std::string>,int> graphe;
    std::map<std::string,int> page2int;
public:
    Graphe();
    void Ajouter(Log* log);
    void ToString(std::ofstream & fs);
};


#endif //CPP_TP4_GRAPHE_H

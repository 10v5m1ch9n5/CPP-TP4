//
// Created by lucas on 20/01/2021.
//

#ifndef CPP_TP4_GRAPHE_H
#define CPP_TP4_GRAPHE_H

#include <map>
#include <string>


class Graphe
{
private:
    std::map<std::string, std::string> sommet2sommet;
    std::map<std::string, int> sommet2hit;
public:
    Graphe();
    void Ajouter(Log* log);
    void Print();
    void ToString();
};


#endif //CPP_TP4_GRAPHE_H

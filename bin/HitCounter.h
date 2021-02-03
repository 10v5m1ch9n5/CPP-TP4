//
// Created by lucas on 03/02/2021.
//

#ifndef CPP_TP4_HITCOUNTER_H
#define CPP_TP4_HITCOUNTER_H

#include <map>

class HitCounter
{
private:
    std::map<std::string, int> hitmap;
public:
    HitCounter();
    ~HitCounter();
    void Incrementer(const std::string & str);
    void ToString();
};


#endif //CPP_TP4_HITCOUNTER_H

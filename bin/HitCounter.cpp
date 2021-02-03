//
// Created by lucas on 03/02/2021.
//

#include "HitCounter.h"
#include <iostream>

HitCounter::HitCounter()
{
#ifdef MAP
    std::cout << "Appel au constructeur de HitCounter" << std::endl;
#endif
}

HitCounter::~HitCounter()
{
#ifdef MAP
    std::cout << "Appel au destructeur de HitCounter" << std::endl;
#endif
}

void HitCounter::Incrementer(const std::string &str)
{
    if (hitmap.find(str) == hitmap.end())
    {
        hitmap.emplace(str, 1);
        return;
    }

    hitmap[str]++;
}

void HitCounter::ToString()
{
    std::multimap<int, std::string> mm;
    int i = 0;

    for (std::map<std::string,int>::iterator it = hitmap.begin(); it != hitmap.end(); ++it)
    {
        mm.insert({it->second, it->first});
    }

    for (std::multimap<int,std::string>::reverse_iterator rit = mm.rbegin(); rit != mm.rend(); ++rit)
    {
        std::cout << rit->second << " (" << rit->first << " hits)" << std::endl;
        if (i++ >= 10)
            break;
    }
}

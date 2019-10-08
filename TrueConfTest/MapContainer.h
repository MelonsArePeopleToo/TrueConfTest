//
// Created by sancho on 08.10.2019.
//

#ifndef TRUECONFTEST_MAPCONTAINER_H
#define TRUECONFTEST_MAPCONTAINER_H


#include <iostream>
#include <map>
#include <thread>
#include <mutex>
#include "Utils.h"


class MapContainer
{
    std::mutex lock;
public:
    void insert(int gen, int pos, std::map<int, int> &map);
    void deleteItems(std::map<int, int> &map, int num, int size);
    void print(std::map<int, int> &map);

};


#endif //TRUECONFTEST_MAPCONTAINER_H

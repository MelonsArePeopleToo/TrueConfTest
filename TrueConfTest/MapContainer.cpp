//
// Created by sancho on 08.10.2019.
//

#include "MapContainer.h"


void MapContainer::insert(int gen, int pos, std::map<int, int> &map)
{
    lock.lock();
    map.insert(std::pair<int, int>(pos, gen));
    lock.unlock();
}


void MapContainer::print(std::map<int, int> &map)
{
    lock.lock();
    std::cout << "Your map: " << std::endl;

    for(auto item = map.begin(); item != map.end(); item++)
    {
        std::cout << item->second << std::endl;
    }
    lock.unlock();
}


void MapContainer::deleteItems(std::map<int, int> &map, int num, int size)
{
    auto *util = new utils;

    for (int i = 0; i < num; i++)
    {
        int numDelItem = util->generator(0, size);

        for (int i = numDelItem; i < size; i++)
        {
            map.find(i)->second = map.find(i+1)->second;
        }
        size--;
    }
    for (auto item = map.begin(); item != map.end(); item++)
    {
        if (item->first >= size)
        map.erase(item);
    }

}

//
// Created by sancho on 07.10.2019.
//

#include "VectorContainer.h"
#include "MapContainer.h"
#include "Utils.h"
#include <thread>
#include <map>



#define GENMIN 1                                                 //     conditions:    //
#define GENMAX 9                                                 // range of generator //
#define DELMIN 0                                                 //                    //
#define DELMAX 15                                                //                    //

auto *util = new utils;

void threadForVec(std::vector<int> &vector, int num)
{
    auto *vectorContainer = new VectorContainer;
    {
        for (int i = 0; i < num; ++i)
        {
            int gen = utils::generator(GENMIN, GENMAX);
            vectorContainer->insert(gen, vector);
        }
        vectorContainer->print(vector);
    }

        int gen = utils::generator(DELMIN, DELMAX);              // num of items, that will be deleted
        std::cout << "num of items, that will be deleted from vector: "<< gen << std::endl;
        vectorContainer->deleteItems(vector, gen, num);
}

void threadForMap(std::map<int, int> &map, int num)
{
    auto *mapContainer = new MapContainer;
    {
        for (int i = 0; i < num; ++i)
        {
            int gen = utils::generator(GENMIN, GENMAX);
            mapContainer->insert(gen, i, map);
        }
        mapContainer->print(map);
    }
        int gen = utils::generator(DELMIN, DELMAX);
        std::cout << "num of items, that will be deleted from map: "<< gen << std::endl;
        mapContainer->deleteItems(map, gen, num);
}

int main()
{
    std::vector<int> vector = {};
    std::map<int, int> map = {};

    int num = 0;
    util->sizeOfContainers(num);

    std::thread threadVector(threadForVec, std::ref(vector), num);
    std::thread threadMap(threadForMap, std::ref(map), num);
    threadVector.join();
    threadMap.join();

    util->print(vector,map);
    util->synchronization(vector, map);

    std::cout<<"after synchro: " << std::endl;
    util->print(vector,map);

    return 0;
}
//
// Created by sancho on 07.10.2019.
//

#include "VectorContainer.h"
#include "MapContainer.h"
#include "Utils.h"
#include <thread>
#include <map>
#include <unistd.h>


#define GENMIN 1                                                 //     conditions:    //
#define GENMAX 9                                                 // range of generator //
#define DELMIN 0                                                 //                    //
#define DELMAX 15                                                //                    //

auto *util = new utils;

void threadForVec(std::vector<int> &vector, int num)
{
    auto *vectorContainer = new VectorContainer;
    {
        for (int i = 0; i < num; ++i) {
            int gen = utils::generator(GENMIN, GENMAX);
            vectorContainer->insert(gen, vector);
        }
        vectorContainer->print(vector);
    }
    sleep(1);                                             // an epic pause before next step :D
    {
        int gen = utils::generator(DELMIN, DELMAX);              // num of items, that will be deleted
        std::cout << gen <<" genVect" << std::endl;
        vectorContainer->deleteItems(vector, gen, num);
        vectorContainer->print(vector);
    }

}

void threadForMap(std::map<int, int> map, int num)
{
    auto *mapContainer = new MapContainer;
    {
        for (int i = 0; i < num; ++i) {
            int gen = utils::generator(GENMIN, GENMAX);
            mapContainer->insert(gen, i, map);
        }
        mapContainer->print(map);
    }
    sleep(1);
    {
        int gen = utils::generator(DELMIN, DELMAX);
        std::cout << gen <<" genMap" << std::endl;

        mapContainer->deleteItems(map, gen, num);
        mapContainer->print(map);
    }
}

int main()
{
    std::vector<int> vector;
    std::map<int, int> map;

    int num = 0;
    util->sizeOfContainers(num);

    std::thread threadVector(threadForVec, std::ref(vector), num);
    std::thread threadMap(threadForMap, std::ref(map), num);
    threadVector.join();
    threadMap.join();
    return 0;
}
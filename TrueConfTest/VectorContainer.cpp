//
// Created by sancho on 07.10.2019.
//

#include "VectorContainer.h"


void VectorContainer::insert(int gen, std::vector<int> &vector)
{
    lock.lock();
    vector.push_back(gen);
    lock.unlock();
}

void VectorContainer::print(std::vector<int> &vector)
{
    lock.lock();
    std::cout << "Your vector: " << std::endl;

    for(auto i : vector)
    {
        std::cout << i << std::endl;
    }
    lock.unlock();
}

void VectorContainer::deleteItems(std::vector<int> &vector, int num, int size)
{
    auto *util = new utils;
    for (int i = 0; i < num; i++)
    {
        int addrDelItem = util->generator(0, size);

        vector[addrDelItem] = 0;
        for (int i = addrDelItem; i < size; i++)
        {
            vector[i] = vector[i + 1];
        }
        vector.resize(size - 1);
        size--;
    }

}


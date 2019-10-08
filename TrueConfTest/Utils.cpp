//
// Created by sancho on 07.10.2019.
//

#include "Utils.h"


int utils::generator(int start, int end)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> uid(start, end);
    return uid(gen);
}

int utils::sizeOfContainers(int &size)
{
    std::cout << "Enter size of containers(> 15): ";
    std::cin >> size;

    if(size <= 15)
    {
        std::cout <<"something's wrong, try again..." << std::endl;
        return sizeOfContainers(size);
    }
    return size;

}

void utils::print(std::vector<int> vector, std::map<int, int> map)
{
    std::cout << "VECTOR: " << std::endl;
    for (auto i : vector)
    {
        std::cout << i << std::endl;
    }

    std::cout << "MAP: " << std::endl;
    for(auto & item : map)
    {
        std::cout << item.second << std::endl;
    }
}

void utils::synchronization(std::vector<int> &vector, std::map<int, int> &map)
{
    syncVectorSide(vector, map);
    syncMapSide(vector, map);

    for (int i = vector.size() - 1; i >= 0; i--)
    {
        if (vector[i] == 0)
        {
            vector.erase(vector.begin() + i);
        }
    }

    for (auto j = map.begin(); j != map.end(); j++)
    {
        for(auto k = map.begin(); k!=map.end(); k++)
        {
            {
                if (k->second == 0)
                {
                    map.erase(k);
                }
            }
        }
    }
}

void utils::syncVectorSide(std::vector<int> &vector, std::map<int, int> &map)
{
    for (int i = 0; i < vector.size(); i++)
    {
        int counter = map.size();
        for(auto j = map.begin(); j != map.end(); j++)
        {
            if(vector[i] != j->second)
            {
                counter--;
            }
        }
        if(counter == 0) vector[i] = 0;
    }
}

void utils::syncMapSide(std::vector<int> &vector, std::map<int, int> &map)
{
    for (auto j = map.begin(); j != map.end(); j++)
    {
        int counter = vector.size();
        for (int i = 0; i < vector.size(); i++)
        {
            if (vector[i] != j->second)
            {
                counter--;
            }
        }
        if (counter == 0) j->second = 0;
    }


}





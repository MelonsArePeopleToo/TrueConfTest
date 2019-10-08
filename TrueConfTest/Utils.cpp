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

    if(size <= 15){
        std::cout <<"something's wrong, try again..." << std::endl;
        return sizeOfContainers(size);
    }
    return size;

}




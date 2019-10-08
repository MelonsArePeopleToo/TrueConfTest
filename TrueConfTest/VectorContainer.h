//
// Created by sancho on 07.10.2019.
//

#ifndef TRUECONFTEST_VECTORCONTAINER_H
#define TRUECONFTEST_VECTORCONTAINER_H


#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
#include "Utils.h"



class VectorContainer
{
    std::mutex lock;
public:
    void insert(int gen, std::vector<int> &vector);
    void deleteItems(std::vector<int> &vector, int num, int size);
    void print(std::vector<int> &vector);
};


#endif //TRUECONFTEST_VECTORCONTAINER_H

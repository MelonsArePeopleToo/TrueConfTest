//
// Created by sancho on 07.10.2019.
//

#ifndef TRUECONFTEST_UTILS_H
#define TRUECONFTEST_UTILS_H


#include <random>
#include <iostream>
#include <vector>
#include <map>



class utils {
public:
    static int generator(int start, int end);
    int sizeOfContainers(int &size);
    void print(std::vector<int> vector, std::map<int, int> map);
    void synchronization(std::vector<int> vector, std::map<int, int> map);




};


#endif //TRUECONFTEST_UTILS_H

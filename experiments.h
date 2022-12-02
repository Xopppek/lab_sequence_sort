
#ifndef MAIN_CPP_EXPERIMENTS_H
#define MAIN_CPP_EXPERIMENTS_H

#include "dynamic_array.h"
#include "linked_list.h"

template <typename T>
class Experiments {
public:
    static void print(typename DynamicArray<T>::Iterator startIter, typename DynamicArray<T>::Iterator endIter) {
        auto it = startIter;
        while (it != endIter) {
            std::cout << *it << " ";
            it++;
        }
        std::cout << "it was array" << std::endl;
    };

    static void print(typename LinkedList<T>::Iterator startIter, typename LinkedList<T>::Iterator endIter) {
        auto it = startIter;
        while (it != endIter) {
            std::cout << *it << " ";
            it++;
        }
        std::cout << "it was list" << std::endl;
    };
};

#endif //MAIN_CPP_EXPERIMENTS_H

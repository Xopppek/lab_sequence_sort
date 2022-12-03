
#ifndef MAIN_CPP_EXPERIMENTS_H
#define MAIN_CPP_EXPERIMENTS_H

#include "dynamic_array.h"
#include "linked_list.h"
#include "iterator_types.h"

template <typename T>
class Experiments {
public:
    static void print(T startIter, T endIter) {
        auto it = startIter;
        while (it != endIter) {
            std::cout << *it << " ";
            it++;
        }
        //std::cout << "printed" << std::endl;
        if (it.type == IteratorTypes::arrayIterator){
            std::cout << "array 0" << std::endl;
        } else if (it.type == IteratorTypes::listIterator){
            std::cout << "list 0" << std::endl;
        }

    };

};

#endif //MAIN_CPP_EXPERIMENTS_H

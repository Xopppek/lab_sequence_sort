
#ifndef MAIN_CPP_SORTER_H
#define MAIN_CPP_SORTER_H


#include "dynamic_array.h"
#include "linked_list.h"

template <typename T>
class Sorter {
public:
    static void bubbleSort(typename DynamicArray<T>::Iterator start, typename DynamicArray<T>::Iterator end, bool comparator (T a, T b)){
        for (auto i = start; i != end; ++i) {
            for (auto j = start; j != i; ++j) {
                if (comparator(*i, *j)) {
                    T temp = *i;
                    *i = *j;
                    *j = temp;
                }
            }
        }
    }
};

#endif //MAIN_CPP_SORTER_H

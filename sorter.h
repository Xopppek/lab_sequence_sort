
#ifndef MAIN_CPP_SORTER_H
#define MAIN_CPP_SORTER_H


#include "dynamic_array.h"
#include "linked_list.h"

template <typename T, typename I>
class Sorter {
public:
    static void bubbleSort(I begin, I end, bool comparator (T, T)){
        for (auto i = begin; i != end; ++i) {
            for (auto j = begin; j != i; ++j) {
                if (comparator(*i, *j)) {
                    T temp = *i;
                    *i = *j;
                    *j = temp;
                }
            }
        }
    }

   /* static void bubbleSort(typename LinkedList<T>::Iterator begin, typename LinkedList<T>::Iterator end, bool comparator (T, T)){
        for (auto i = begin; i != end; ++i) {
            for (auto j = begin; j != i; ++j) {
                if (comparator(*i, *j)) {
                    T temp = *i;
                    *i = *j;
                    *j = temp;
                }
            }
        }
    }*/
};

#endif //MAIN_CPP_SORTER_H

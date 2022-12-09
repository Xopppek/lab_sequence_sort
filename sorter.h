
#ifndef MAIN_CPP_SORTER_H
#define MAIN_CPP_SORTER_H


#include "dynamic_array.h"
#include "linked_list.h"
#include "iterator_types.h"

template <typename T>
void swap(T& first, T& other){
    T temp = std::move(first);
    first = std::move(other);
    other = std::move(temp);
}

template <typename Iterator>
int distance(Iterator first, Iterator second){
    int res = 0;
    switch (first.type){
        case (IteratorTypes::arrayIterator):
            res = &*second - &*first;
            break;
        case (IteratorTypes::listIterator):
            while (first != second){
                res++;
                first++;
            }
            break;
    }
    return res;
}

template <typename T, typename I>
class Sorter {
public:
    static void BubbleSort(I begin, I end, bool comparator(const T&, const T&)){
        for (auto i = begin; i != end; ++i) {
            for (auto j = begin; j != i; ++j) {
                if (comparator(*j, *i)) {
                    swap(*i, *j);
                }
            }
        }
    }

    static void QuickSort(I begin, I end, bool comparator(const T&, const T&)){
        switch (begin.type){
            case (IteratorTypes::arrayIterator): {
                if (begin < end) {
                    end--;
                    qsort_array(begin, end, comparator);
                }
                break;
            }
            case (IteratorTypes::listIterator):
                break;
        }







        /*--end;
        if (begin < end)
            _qsort_(begin, end, comparator, *begin);*/
    }

private:
    static void qsort_array(I begin, I end, bool comparator(const T&, const T&)){
        auto pivot_iterator = begin;
        int length = distance(begin, end);
        pivot_iterator = begin;
        pivot_iterator += (length / 2);
        T pivot = *(pivot_iterator);
        I left = begin;
        I right = end;
        do {
            while(left < end && comparator(pivot, *left))
                ++left;
            while((right > begin) && comparator(*right, pivot))
                --right;
            if(left <= right){
                swap(*left, *right);
                ++left;
                --right;
            }
        } while(left <= right);
        if(right > begin)
            qsort_array(begin, right, comparator);
        if(end > left)
            qsort_array(left, end, comparator);

    }
};

#endif //MAIN_CPP_SORTER_H

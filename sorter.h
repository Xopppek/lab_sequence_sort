
#ifndef MAIN_CPP_SORTER_H
#define MAIN_CPP_SORTER_H


#include "dynamic_array.h"
#include "linked_list.h"
#include "iterator_types.h"

template <typename T, typename I>
class Sorter {
public:
    static void BubbleSort(I begin, I end, bool comparator (const T&, const T&)){
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

    static void QuickSort(I begin, I end, bool comparator (const T&, const T&)){
        --end;
        if (begin < end)
            _qsort_(begin, end, comparator, *begin);
    }

private:
    static void _qsort_(I begin, I end, bool comparator (const T&, const T&), const T& pivot){
        auto it = begin;
        int length = 0;
        while (it != end){
            it++;
            length++;
        }
        it = begin;
        it += (length / 2);
        T v = *(it);
        I f = begin;
        I l = end;
        do {
            while(f < end && comparator(*f, v))
                ++f;
            while((l > begin) && comparator(v, *l))
                --l;
            if(f <= l){
                std::swap(*f, *l);
                ++f;
                --l;
            }
        } while(f <= l);
        if(l > begin)
            _qsort_(begin, l, comparator, v);
        if(end > f)
            _qsort_(f, end, comparator, v);
    }
};

#endif //MAIN_CPP_SORTER_H

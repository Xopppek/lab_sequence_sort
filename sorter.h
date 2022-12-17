
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
        for (auto i = begin; i != end; ++i)
            for (auto j = begin; j != i; ++j)
                if (comparator(*j, *i))
                    swap(*i, *j);
    }

    static void QuickSort(I begin, I end, bool comparator(const T&, const T&)){
        if (distance(begin, end) <= 0) return;
        qsort(begin, end, comparator);
    }

    static void MergeSort(I begin, I end, bool comparator(const T&, const T&)){
        int size = distance(begin, end);
        if (size < 2) return;
        auto mid = begin;
        mid += size / 2;
        MergeSort(begin, mid, comparator);
        MergeSort(mid, end, comparator);
        merge(begin, mid, end, comparator);
    }

private:
    static void merge(I begin, I mid, I end, bool comparator(const T&, const T&)){
        LinkedList<T> buffer;
        auto left = begin;
        auto right = mid;
        while (left != mid and right != end) {
            if (comparator(*left, *right)) {
                buffer.Append(*right);
                right++;
            }
            else {
                buffer.Append(*left);
                left++;
            }
        }
        while (left != mid){
            buffer.Append(*left);
            left++;
        }
        while (right != end){
            buffer.Append(*right);
            right++;
        }

        auto take = buffer.begin();
        auto put = begin;
        while (take != buffer.end()){
            *put = std::move(*take);
            take++;
            put++;
        }
    }

    static void qsort(I begin, I end, bool comparator(const T&, const T&)){
        if (distance(begin, end) <= 0) return;
        auto pivot = partition(begin, end, comparator);
        qsort(begin, pivot, comparator);
        pivot++;
        qsort(pivot, end, comparator);
    }

    static I partition(I head, I tail, bool comparator(const T&, const T&)){
        auto pivot = head;
        auto prev = head;
        auto current = head;
        current++;
        while (current != tail){
            if (comparator(*pivot, *current)) {
                ++prev;
                swap(*prev, *current);
            }
            current++;
        }
        swap(*prev, *pivot);
        return prev;
    }
};

#endif //MAIN_CPP_SORTER_H

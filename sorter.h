
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

template <typename T>
class Sorter {
public:
    static void BubbleSort(typename DynamicArray<T>::Iterator begin,
                           typename DynamicArray<T>::Iterator end,
                           bool comparator(const T&, const T&)){
        for (auto i = begin; i != end; ++i)
            for (auto j = begin; j != i; ++j)
                if (comparator(*j, *i))
                    swap(*i, *j);
    }

    static void BubbleSort(typename LinkedList<T>::Iterator begin,
                           typename LinkedList<T>::Iterator end,
                           bool comparator(const T&, const T&)){
        for (auto i = begin; i != end; ++i)
            for (auto j = begin; j != i; ++j)
                if (comparator(*j, *i))
                    swap(*i, *j);
    }

    static void QuickSort(typename DynamicArray<T>::Iterator begin,
                          typename DynamicArray<T>::Iterator end,
                          bool comparator(const T&, const T&)){
        if (begin < end) {
            end--;
            qsort_array(begin, end, comparator);
        }
    }

    static void QuickSort(typename LinkedList<T>::Iterator begin,
                          typename LinkedList<T>::Iterator end,
                          bool comparator(const T&, const T&)){
        if (distance(begin, end) <= 0) return;
        qsort_list(begin, end, comparator);
    }

    static void MergeSort(typename DynamicArray<T>::Iterator begin,
                          typename DynamicArray<T>::Iterator end,
                          bool comparator(const T&, const T&)){
        int size = distance(begin, end);
        if (size < 2) return;
        auto mid = begin;
        mid += size / 2;
        MergeSort(begin, mid, comparator);
        MergeSort(mid, end, comparator);
        arrayMerge(begin, mid, end, comparator);
    }

private:
    static void arrayMerge(typename DynamicArray<T>::Iterator begin,
                           typename DynamicArray<T>::Iterator mid,
                           typename DynamicArray<T>::Iterator end,
                           bool comparator(const T&, const T&)){
        DynamicArray<T> buffer;
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

    static void qsort_list(typename LinkedList<T>::Iterator begin,
                           typename LinkedList<T>::Iterator end,
                           bool comparator(const T&, const T&)){
        if (distance(begin, end) <= 0) return;
        auto pivot = listPartition(begin, end, comparator);
        qsort_list(begin, pivot, comparator);
        qsort_list(++pivot, end, comparator);
    }

    static typename LinkedList<T>::Iterator listPartition(
            typename LinkedList<T>::Iterator head,
            typename LinkedList<T>::Iterator tail,
            bool comparator(const T&, const T&)){
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

    static void qsort_array(typename DynamicArray<T>::Iterator begin,
                            typename DynamicArray<T>::Iterator end,
                            bool comparator(const T&, const T&)){
        auto pivot_iterator = begin;
        int length = distance(begin, end);
        pivot_iterator = begin;
        pivot_iterator += (length / 2);
        T pivot = *(pivot_iterator);
        auto left = begin;
        auto right = end;
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

#include "dynamic_array.h"
#include "linked_list.h"
#include "dynamic_array_sequence.h"
#include "linked_list_sequence.h"
#include "experiments.h"
#include "sorter.h"
#include "chrono"
#include <iostream>

bool com(const int& a, const int& b){
    return a > b;
}

int main() {

    auto begin = std::chrono::steady_clock::now();
    auto end = std::chrono::steady_clock::now();
    auto elapsed_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);


    auto current_time = std::chrono::system_clock::now();
    srand(time(NULL));


    bool printEnabled = 0;
    int n = 10000;
    int hu[n];
    for (int i = 0; i < n; i++){
        hu[i] = std::rand();
        //std::cout << hu[i] << " ";
    }

    ArraySequence<int> arraySequence1(hu, n);
    ArraySequence<int> arraySequence2(hu, n);
    ArraySequence<int> arraySequence3(hu, n);

    begin = std::chrono::steady_clock::now();
    Sorter<int>::BubbleSort(arraySequence1.begin(), arraySequence1.end(), com);
    end = std::chrono::steady_clock::now();
    elapsed_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
    std::cout << "BubbleSort Array: " << elapsed_ms.count() << " ms\n";
    if (printEnabled)
        Experiments<typename DynamicArray<int>::Iterator>::print(arraySequence1.begin(), arraySequence1.end());

    begin = std::chrono::steady_clock::now();
    Sorter<int>::QuickSort(arraySequence2.begin(), arraySequence2.end(), com);
    end = std::chrono::steady_clock::now();
    elapsed_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
    std::cout << "QuickSort Array: " << elapsed_ms.count() << " ms\n";
    if (printEnabled)
        Experiments<typename DynamicArray<int>::Iterator>::print(arraySequence2.begin(), arraySequence2.end());

    begin = std::chrono::steady_clock::now();
    Sorter<int>::MergeSort(arraySequence3.begin(), arraySequence3.end(), com);
    end = std::chrono::steady_clock::now();
    elapsed_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
    std::cout << "MergeSort Array: " << elapsed_ms.count() << " ms\n";
    if (printEnabled)
        Experiments<typename DynamicArray<int>::Iterator>::print(arraySequence3.begin(), arraySequence3.end());

    LinkedListSequence<int> list1(hu, n);
    LinkedListSequence<int> list2(hu, n);
    LinkedListSequence<int> list3(hu, n);


    begin = std::chrono::steady_clock::now();
    Sorter<int>::BubbleSort(list1.begin(), list1.end(), com);
    end = std::chrono::steady_clock::now();
    elapsed_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
    std::cout << "BubbleSort List: " << elapsed_ms.count() << " ms\n";
    if (printEnabled)
        Experiments<typename LinkedList<int>::Iterator>::print(list1.begin(), list1.end());

    begin = std::chrono::steady_clock::now();
    Sorter<int>::QuickSort(list2.begin(), list2.end(), com);
    end = std::chrono::steady_clock::now();
    elapsed_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
    std::cout << "QuickSort List: " << elapsed_ms.count() << " ms\n";
    if (printEnabled)
        Experiments<typename LinkedList<int>::Iterator>::print(list2.begin(), list2.end());

    begin = std::chrono::steady_clock::now();
    Sorter<int>::MergeSort(list3.begin(), list3.end(), com);
    end = std::chrono::steady_clock::now();
    elapsed_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
    std::cout << "MergeSort List: " << elapsed_ms.count() << " ms\n";
    if (printEnabled)
        Experiments<typename LinkedList<int>::Iterator>::print(list3.begin(), list3.end());

    return 0;
}
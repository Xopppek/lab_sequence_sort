#include "dynamic_array.h"
#include "linked_list.h"
#include "dynamic_array_sequence.h"
#include "linked_list_sequence.h"
#include "experiments.h"
#include "sorter.h"
#include "chrono"
#include <iostream>


bool compare(const char& a, const char& b){
    return b < a;
}

bool com2(const char& a, const char& b){
    return a > b;
}

bool com(const int& a, const int& b){
    return a > b;
}

bool com1(const int& a, const int& b){
    return a < b;
}

int main() {
    /*int a[] = {1,4,3,2,5,6};
    ArraySequence<int> array(a, 6);
    LinkedListSequence<int> list(a, 6);

    array.Append(15);
    list.Append(15);

    array[0] = 200;
    list[0] = 200;

    for(int i = 0; i < array.GetLength(); i++)
        std::cout << array[i] << ' ';
    std::cout << "array" << std::endl;
    for(int i = 0; i < list.GetLength(); i++)
        std::cout << list[i] << ' ';
    std::cout << "list" << std::endl;

    array.Prepend(50);
    list.Prepend(50);

    for(int i = 0; i < array.GetLength(); i++)
        std::cout << array[i] << ' ';
    std::cout << "array" << std::endl;
    for(int i = 0; i < list.GetLength(); i++)
        std::cout << list[i] << ' ';
    std::cout << "list" << std::endl;

    array.InsertAt(200, 3);
    list.InsertAt(200, 3);

    for(int i = 0; i < array.GetLength(); i++)
        std::cout << array.Get(i) << ' ';
    std::cout << "array" << std::endl;
    for(int i = 0; i < list.GetLength(); i++)
        std::cout << list.Get(i) << ' ';
    std::cout << "list" << std::endl;

    ArraySequence<int> *subArray = array.GetSubSequence(2, 5);
    LinkedListSequence<int> *subList = list.GetSubSequence(2, 5);

    for (int i = 0; i < subArray->GetLength(); i++){
        std::cout << (*subArray)[i] << ' ';
    }
    std::cout << "array" << std::endl;
    for (int i = 0; i < subList->GetLength(); i++){
        std::cout << (*subList)[i] << ' ';
    }
    std::cout << "list" << std::endl;

    std::cout << std::endl;*/

    /*char b[] = {'a', 'b', 'c', 'd', 'e', 'f', 'j'};

    ArraySequence<char> charSequence(b, 7);
    auto it = charSequence.begin();
    auto it3 = charSequence.begin();
    it3 += 4;
    charSequence.Swap(it, it3);
    it++;
    it3--;
    charSequence.Swap(it, it3);
    while (it != charSequence.end()) {
        //*it = 'b';
        std::cout << *it << ' ';
        it++;
    }
    std::cout << "array" << std::endl;

    LinkedListSequence<char> linkedList(b, 7);
    auto it4 = linkedList.begin();
    it4 += 4;
    auto it2 = linkedList.begin();
    linkedList.Swap(it2, it4);
    //linkedList.Swap(&(*it2), &*it4);
    while (it2 != linkedList.end()) {
        std::cout << *it2 << ' ';
        it2++;
    }
    std::cout << "list" << std::endl;

    it3 = charSequence.begin();

    //Experiments<typename LinkedList<char>::Iterator>::print(linkedList.begin(), linkedList.end());

    Experiments<typename DynamicArray<char>::Iterator>::print(charSequence.begin(), charSequence.end());
    *//*Sorter<char, typename DynamicArray<char>::Iterator>::BubbleSort(charSequence.begin(), charSequence.end(), compare);
    Experiments<typename DynamicArray<char>::Iterator>::print(charSequence.begin(), charSequence.end());*//*

    auto begin = std::chrono::steady_clock::now();
    auto end = std::chrono::steady_clock::now();
    auto elapsed_ms = std::chrono::steady_clock::now();

    begin = std::chrono::steady_clock::now();
    Sorter<char, typename DynamicArray<char>::Iterator>::QuickSort(charSequence.begin(), charSequence.end(), compare);
    end = std::chrono::steady_clock::now();;
    elapsed_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
    std::cout << "BubbleSort: " << elapsed_ms.count() << " ms\n";

    Experiments<typename DynamicArray<char>::Iterator>::print(charSequence.begin(), charSequence.end());

    begin = std::chrono::steady_clock::now();
    Sorter<char, typename DynamicArray<char>::Iterator>::BubbleSort(charSequence.begin(), charSequence.end(), com2);
    end = std::chrono::steady_clock::now();;
    elapsed_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
    std::cout << "QuickSort: " << elapsed_ms.count() << " ms\n";

    Experiments<typename DynamicArray<char>::Iterator>::print(charSequence.begin(), charSequence.end());*/

    auto begin = std::chrono::steady_clock::now();
    auto end = std::chrono::steady_clock::now();
    auto elapsed_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);


    auto current_time = std::chrono::system_clock::now();
    std::time_t current_time_t = std::chrono::system_clock::to_time_t(current_time);
    int seed = current_time_t;
    //std::cout << seed << "\n";
    srand(seed);

    int n = 10000;
    int hu[n];
    for (int i = 0; i < n; i++){
        hu[i] = std::rand();
       // std::cout << hu[i] << " ";
    }

    ArraySequence<int> arraySequence1(hu, n);
    ArraySequence<int> arraySequence2(hu, n);
    //Experiments<typename DynamicArray<int>::Iterator>::print(arraySequence.begin(), arraySequence.end());

    //LinkedListSequence<int> listSequence(hu, n);
    //auto t = arraySequence1.begin();
    //--t;
    //t++;
    //printf("%d", *t);

    begin = std::chrono::steady_clock::now();
    Sorter<int, DynamicArray<int>::Iterator>::BubbleSort(arraySequence1.begin(), arraySequence1.end(), com);
    end = std::chrono::steady_clock::now();
    elapsed_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
    std::cout << "BubbleSort Array: " << elapsed_ms.count() << " ms\n";

    //Experiments<typename DynamicArray<int>::Iterator>::print(arraySequence1.begin(), arraySequence1.end());


    begin = std::chrono::steady_clock::now();
    Sorter<int, DynamicArray<int>::Iterator>::QuickSort(arraySequence2.begin(), arraySequence2.end(), com);
    end = std::chrono::steady_clock::now();
    elapsed_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
    std::cout << "QuickSort Array: " << elapsed_ms.count() << " ms\n";

    //Experiments<typename DynamicArray<int>::Iterator>::print(arraySequence2.begin(), arraySequence2.end());


    LinkedListSequence<int> list(hu, n);

    begin = std::chrono::steady_clock::now();
    Sorter<int, LinkedList<int>::Iterator>::BubbleSort(list.begin(), list.end(), com);
    end = std::chrono::steady_clock::now();
    elapsed_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
    std::cout << "BubbleSort List: " << elapsed_ms.count() << " ms\n";

   // Experiments<typename LinkedList<int>::Iterator>::print(list.begin(), list.end());



    return 0;
}
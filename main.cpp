#include "dynamic_array.h"
#include "linked_list.h"
#include "dynamic_array_sequence.h"
#include "linked_list_sequence.h"
#include "experiments.h"
#include "sorter.h"
#include <iostream>


bool compare(char a, char b){
    return b < a;
}

bool com(int a, int b){
    return a > b;
}

bool com1(int a, int b){
    return a < b;
}

int main() {
    int a[] = {1,4,3,2,5,6};
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

    std::cout << std::endl;

    char b[] = {'a', 'b', 'c', 'd', 'e', 'f', 'j'};

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



    Experiments<typename DynamicArray<char>::Iterator>::print(charSequence.begin(), charSequence.end());
    Sorter<char, typename DynamicArray<char>::Iterator>::bubbleSort(charSequence.begin(), charSequence.end(), compare);
    Experiments<typename DynamicArray<char>::Iterator>::print(charSequence.begin(), charSequence.end());
    //Experiments<char>::print(linkedList.begin(), linkedList.end());
    //Experiments<char>::print(it3, it);
/*
    Sorter<char>::bubbleSort(charSequence.begin(), charSequence.end(), compare);

    Experiments<char>::print(charSequence.begin(), charSequence.end());

    int nn[] = {1, 4, 3, 5, 6, 2};
    ArraySequence<int> omg(nn, 6);

    Sorter<int>::bubbleSort(omg.begin(), omg.end(), com);
    Experiments<int>::print(omg.begin(), omg.end());

    ArraySequence<int> hh;
    Sorter<int>::bubbleSort(hh.begin(), hh.end(), com);
    Experiments<int>::print(hh.begin(), hh.end());

    LinkedListSequence<int> bn(nn, 6);
    Sorter<int>::bubbleSort(bn.begin(), bn.end(), com1);
    Experiments<int>::print(bn.begin(), bn.end());*/


    return 0;
}
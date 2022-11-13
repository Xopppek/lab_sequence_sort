#include "dynamic_array.h"
#include "linked_list.h"
#include "dynamic_array_sequence.h"
#include "linked_list_sequence.h"
#include <iostream>

int main() {
    int a[] = {1,4,3,2,5,6};
    ArraySequence<int> array(a, 6);
    LinkedListSequence<int> list(a, 6);

    array.Append(15);
    list.Append(15);

    for(int i = 0; i < array.GetLength(); i++)
        std::cout << array.Get(i) << ' ';
    std::cout << "array" << std::endl;
    for(int i = 0; i < list.GetLength(); i++)
        std::cout << list.Get(i) << ' ';
    std::cout << "list" << std::endl;

    array.Prepend(50);
    list.Prepend(50);

    for(int i = 0; i < array.GetLength(); i++)
        std::cout << array.Get(i) << ' ';
    std::cout << "array" << std::endl;
    for(int i = 0; i < list.GetLength(); i++)
        std::cout << list.Get(i) << ' ';
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

    return 0;
}
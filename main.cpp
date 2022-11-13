#include "dynamic_array.h"
#include "linked_list.h"
#include "dynamic_array_sequence.h"
#include "linked_list_sequence.h"
#include <iostream>

int main() {
    int a[] = {1,4,3,2,5,6};
    LinkedListSequence<int> array(a, 6);

    //LinkedList<int> arr(a, 6);
    //LinkedList<int>* b = arr.GetSubList(2,4);

    /*
    LinkedList<int> list(a, 6);
    int y = 2;
    list[y]= 4;
    list.Append(200);
    list.Prepend(900);
    for(int i = 0; i < list.GetLength(); i++)
        std::cout << list[i] << ' ';
        */



    //std::cout << std::endl;

    //std::cout << array[5] << std::endl;

    //array[5] = 8;
    for(int i = 0; i < array.GetLength(); i++)
        std::cout << array.Get(i) << ' ';
    std::cout << std::endl;
/*
    array[5] = 100;

    array.Append(600);
    array.Prepend(800);*/
    array.InsertAt(200, 6);
    //array.Prepend(5);
    //array.Set(3, 200);
    LinkedListSequence<int>* b = array.GetSubSequence(2, 5);


    for (int i = 0; i < b->GetLength(); i++){
        std::cout << (*b)[i] << ' ';
    }

    /*std::cout << std::endl;
    for(int i = 0; i < array.GetLength(); i++)
        std::cout << array[i] << ' ';

    std::cout << std::endl;
    std::cout << array.GetLength() << ' ';*/

    /*
    std::cout << std::endl;
    std::cout << array[5] << std::endl;
    std::cout << std::endl;

    //for(int i = 0; i < 5; i++)
        //std::cout << list[i] << ' ';
        //int* b = &(array[0]);

    std::cout << b[0] << " " << b[1] << " ";
    delete &array;

    std::cout << b[0] << " " << b[1];
*/
    return 0;
}
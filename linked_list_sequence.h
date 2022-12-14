#ifndef LAB2SEM2V2_LINKED_LIST_SEQUENCE_H
#define LAB2SEM2V2_LINKED_LIST_SEQUENCE_H
#include "linked_list.h"
#include "sequence.h"

template <typename T>
class LinkedListSequence : Sequence <T> {
private:
    LinkedList<T>* list_;
public:

    //typename LinkedList<T>::Iterator begin() {return list_->begin(); }
    //typename LinkedList<T>::Iterator end() { return list_->end(); }

    auto begin() {return list_->begin(); }
    auto end() { return list_->end(); }


    LinkedListSequence(){
        list_ = new LinkedList<T>;
    }
    LinkedListSequence(const int& size){
        list_ = new LinkedList<T>(size);
    }
    LinkedListSequence(const LinkedListSequence<T>& copyingList){
        list_ = new LinkedList<T>(copyingList);
    }
    LinkedListSequence(const T* copyingArray, const int& copyingArraySize){
        list_ = new LinkedList<T>(copyingArray, copyingArraySize);
    }
    ~LinkedListSequence(){
        delete list_;
    }
    int GetLength() const{
        return list_->GetLength();
    }
    T Get (const int& index) const{
        return list_->Get(index);
    }
    T GetFirst() const{
        //обработать случай пустого массива
        return list_->Get(0);
    }
    T GetLast() const{
        //обработать случай пустого массива
        return list_->Get(list_->GetLength());
    }
    LinkedListSequence<T>* GetSubSequence(const int& startIndex, const int& endIndex){
        LinkedListSequence<T>* subList = new LinkedListSequence<T>;
        subList->list_ = list_->GetSubList(startIndex, endIndex);
        return subList;
    }
    void Append(const T& value){
        list_->Append(value);
    }
    void Prepend(const T& value){
        list_->Prepend(value);
    }
    void Set(const int& index, const T& value){
        list_->Set(index, value);
    }
    void InsertAt(const T& value, const int& index){
        list_->InsertAt(value, index);
    }

    void Swap(T* value1, T* value2)
    {
        list_->Swap(value1, value2);
    }

    void Swap(typename LinkedList<T>::Iterator iter1, typename LinkedList<T>::Iterator iter2){
        list_->Swap(iter1, iter2);
    }

    T& operator[] (const int& index){
       return (*list_)[index];
    }
};

#endif //LAB2SEM2V2_LINKED_LIST_SEQUENCE_H

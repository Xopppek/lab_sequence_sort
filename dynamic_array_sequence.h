#ifndef LAB2SEM2V2_DYNAMIC_ARRAY_SEQUENCE_H
#define LAB2SEM2V2_DYNAMIC_ARRAY_SEQUENCE_H
#include "dynamic_array.h"
#include "sequence.h"
#include "iostream"

template <typename T>
class ArraySequence : Sequence <T> {
private:
    DynamicArray<T>* array_;
public:
    typename DynamicArray<T>::Iterator begin() {return array_->begin(); }
    typename DynamicArray<T>::Iterator end() { return array_->end(); }

    ArraySequence(){
        array_ = new DynamicArray<T>;
    }
    ArraySequence(const int& size){
        array_ = new DynamicArray<T>(size);
    }
    ArraySequence(const ArraySequence<T>& copyingArray){
        array_ = new DynamicArray<T>(copyingArray);
    }
    ArraySequence(const T* copyingArray, const int& copyingArraySize){
        array_ = new DynamicArray<T>(copyingArray, copyingArraySize);
    }
    ~ArraySequence(){
        delete array_;
    }
    int GetLength() const{
        return array_->GetSize();
    }
    T Get (const int& index) const{
        return array_->Get(index);
    }
    T GetFirst() const{
        //обработать случай пустого массива
        return array_->Get(0);
    }
    T GetLast() const{
        //обработать случай пустого массива
        return array_->Get(array_->GetSize());
    }
    ArraySequence<T>* GetSubSequence(const int& startIndex, const int& endIndex){
        ArraySequence<T>* subSequence = new ArraySequence<T>;
        subSequence->array_ = array_->GetSubArray(startIndex, endIndex);
        return subSequence;
    }
    void Append(const T& value){
        array_->Append(value);
    }
    void Prepend(const T& value){
        array_->Prepend(value);
    }
    void Set(const int& index, const T& value){
        array_->Set(index, value);
    }
    void InsertAt(const T& value, const int& index){
        //обработать outOfRange
        array_->Resize(array_->GetSize() + 1);
        for (int i = array_->GetSize() - 1; i >= index; i--){
            array_->Set(i, array_->Get(i - 1));
        }
        array_->Set(index, value);
    }

    T& operator[] (const int& index){
        return array_->GetElementPointer(const_cast<int &>(index));
    }

};




#endif //LAB2SEM2V2_DYNAMIC_ARRAY_SEQUENCE_H

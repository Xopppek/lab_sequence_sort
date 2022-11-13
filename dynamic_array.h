#ifndef LAB2SEM2_DYNAMIC_ARRAY_H
#define LAB2SEM2_DYNAMIC_ARRAY_H

template <typename T>
class DynamicArray{
private:
    T *elements_;
    int size_;
    int memorySize_;
public:
    DynamicArray(){
        elements_ = nullptr;
        size_ = 0;
        memorySize_ = 0;
    }
    DynamicArray(const int& size){
        //обработать случай ввода отрицательного size
        size_ = size;
        memorySize_ = size_;
        elements_ = new T[size];
    }
    DynamicArray(const DynamicArray <T>& copyingArray){
        size_ = copyingArray.size_;
        memorySize_ = size_;
        elements_ = new T[size_];
        for (int i = 0; i < size_; i++)
            elements_[i] = copyingArray.elements_[i];
    }
    DynamicArray(const T* copyingArray, const int& copyingArraySize){
        //обработать случай отрицательного size
        size_ = copyingArraySize;
        memorySize_ = size_;
        elements_ = new T[size_];
        for (int i = 0; i < size_; i++)
            elements_[i] = copyingArray[i];
    }
    ~DynamicArray(){
        delete[] elements_;
        elements_ = nullptr;
    }
    int GetSize() const{
        return size_;
    }
    T Get(const int& index) const{
        if (index < 0 || index >= size_){
            //ошибка
        }
        return elements_[index];
    }
    DynamicArray<T>* GetSubArray(const int& startIndex, const int& endIndex){
        DynamicArray<T>* subArray = new DynamicArray<T>;
        for (int i = startIndex; i <= endIndex; i++){
            subArray->Append(Get(i));
        }
        return subArray;
    }
    void Append(const T& value){
        Resize(size_ + 1);
        Set(size_ - 1, value);
    }
    void Prepend(const T& value){
        Resize(size_ + 1);
        for (int i = size_ - 1; i > 0; i--){
            Set(i, elements_[i-1]);
        }
        Set(0, value);
    }
    void Set(const int& index, const T& value){
        if (index < 0 || index >= size_){
            return; //ошибка
        }
        elements_[index] = value;
    }
    void Resize(const int& newSize){
        if (newSize > memorySize_){
            int newMemorySize = newSize > 2 * size_ ? newSize : 2 * size_;
            T *newElements = new T[newMemorySize];
            for (int i = 0; i < size_; i++)
                newElements[i] = elements_[i];
            delete[] elements_;
            elements_ = newElements;
            size_ = newSize;
            memorySize_ = newMemorySize;
        }
        else if (newSize < size_){
            T *newElements = new T[newSize];
            for (int i = 0; i < newSize; i++)
                newElements[i] = elements_[i];
            delete[] elements_;
            elements_ = newElements;
            size_ = newSize;
            memorySize_ = size_;
        }
        else if (newSize >= size_ && newSize <= memorySize_){
            size_ = newSize;
        }
    }
    /*
    T& operator[] (int index){
        //обработать OutOfRange
        return elements_[index];
    }*/
    T& GetElementPointer(int index){
        return elements_[index];
    }
};

#endif //LAB2SEM2_DYNAMIC_ARRAY_H

#ifndef LAB2SEM2_LINKED_LIST_H
#define LAB2SEM2_LINKED_LIST_H

template <typename T>
class LinkedList {
private:
    struct Element{
        T value_;
        Element* next;
    };
    Element* firstElement;
    Element* lastElement;
    int size_;
public:
    LinkedList(){
        firstElement = nullptr;
        lastElement = nullptr;
        size_ = 0;
    }
    LinkedList(const T* copyingArray, const int copyingArraySize){
        firstElement = new Element;
        size_ = copyingArraySize;
        Element* currentElement = firstElement;
        firstElement->value_ = copyingArray[0];
        for (int i = 1; i < copyingArraySize; i++){
            Element* newElement = new Element;
            newElement->value_ = copyingArray[i];
            currentElement->next = newElement;
            currentElement = newElement;
        }
        lastElement = currentElement;
        lastElement->next = nullptr;
    }
    LinkedList(const LinkedList<T>& copyingList){
        size_ = copyingList.size_;
        if (size_){
            firstElement = new Element;
            firstElement->value_ = copyingList.firstElement->value_;
            Element* slowPointer = firstElement;
            Element* fastPointer = copyingList.firstElement->next;
            while (fastPointer){
                Element* newElement = new Element;
                newElement->value_ = fastPointer->value_;
                slowPointer->next = newElement;
                slowPointer = newElement;
                fastPointer = fastPointer->next;
            }
            slowPointer->next = nullptr;
            lastElement = slowPointer;
        }
    }
    ~LinkedList(){
        Element* currentElement = firstElement;
        while (currentElement){
            Element* nextElement = currentElement->next;
            delete currentElement;
            currentElement = nextElement;
        }
    }
    T GetFirst() const{
        return firstElement->value_;
    }
    T GetLast() const{
        return lastElement->value_;
    }
    T Get(const int index){
        if (index == size_ - 1)
            return GetLast();
        Element* currentElement = firstElement;
        for (int i = 0; i < index; i++)
            currentElement = currentElement->next;
        return currentElement->value_;
    }
    int GetLength() const{
        return size_;
    }
    LinkedList<T>* GetSubList(const int startIndex, const int endIndex){
        //обработать случаи выхода за границы
        LinkedList<T>* SubList = new LinkedList<T>;
        SubList->size_ = endIndex - startIndex + 1;
        SubList->firstElement = new Element;
        SubList->firstElement->value_ = Get(startIndex);
        Element* prevElement = SubList->firstElement;
        for (int i = startIndex + 1; i <= endIndex; i++){
            Element* newElement = new Element;
            newElement->value_ = Get(i);
            prevElement->next = newElement;
            prevElement = newElement;
        }
        prevElement->next = nullptr;
        SubList->lastElement = prevElement;
        return SubList;
    }
    void Append(const T value){
        size_++;
        Element* newElement = new Element;
        newElement->value_ = value;
        if (firstElement == nullptr){
            firstElement = newElement;
            lastElement = newElement;
            return;
        }
        lastElement->next = newElement;
        lastElement = newElement;
        lastElement->next = nullptr;
    }
    void Prepend(const T value){
        size_++;
        Element* newElement = new Element;
        newElement->value_ = value;
        if (firstElement == nullptr){
            firstElement = newElement;
            lastElement = newElement;
            return;
        }
        newElement->next = firstElement;
        firstElement = newElement;
    }
    void Set(const int index, const T value){
        //обработать OutOfRange
        if(index == size_ - 1){
            lastElement->value_ = value;
            return;
        }
        Element* currentElement = firstElement;
        for (int i = 0; i < index; i++){
            currentElement = currentElement->next;
        }
        currentElement->value_ = value;
    }
    void InsertAt(const T value, const int index){
        if (index == 0){
            Prepend(value);
            return;
        }
        if (index == size_){
            Append(value);
            return;
        }
        Element* newElement = new Element;
        newElement->value_ = value;
        Element* currentElement = firstElement;
        for (int i = 0; i < index - 1; i++){
            currentElement = currentElement->next;
        }
        newElement->next = currentElement->next->next;
        currentElement->next = newElement;
        size_++;
    }

    /*
    T& operator[] (const int index){
        //обработать OutOfRange
        if (index == size_ - 1)
            return (lastElement->value_);
        Element* currentElement = firstElement;
        for (int i = 0; i < index; i++)
            currentElement = currentElement->next;
        return (currentElement->value_);
    }*/

    T& GetElementPointer (const int index){
        //обработать OutOfRange
        if (index == size_ - 1)
            return (lastElement->value_);
        Element* currentElement = firstElement;
        for (int i = 0; i < index; i++)
            currentElement = currentElement->next;
        return (currentElement->value_);
    }
};

#endif //LAB2SEM2_LINKED_LIST_H

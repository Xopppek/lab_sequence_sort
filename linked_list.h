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
    class Iterator;
    Iterator begin() { return firstElement; }
    Iterator end() { return lastElement->next; }

    LinkedList(){
        firstElement = nullptr;
        lastElement = nullptr;
        size_ = 0;
    }
    LinkedList(const T* copyingArray, const int& copyingArraySize){
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
    T Get(const int& index) const{
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
    LinkedList<T>* GetSubList(const int& startIndex, const int& endIndex){
        //обработать случаи выхода за границы
        LinkedList<T>* subList = new LinkedList<T>;
        subList->size_ = endIndex - startIndex + 1;
        subList->firstElement = new Element;
        subList->firstElement->value_ = Get(startIndex);
        Element* prevElement = subList->firstElement;
        for (int i = startIndex + 1; i <= endIndex; i++){
            Element* newElement = new Element;
            newElement->value_ = Get(i);
            prevElement->next = newElement;
            prevElement = newElement;
        }
        prevElement->next = nullptr;
        subList->lastElement = prevElement;
        return subList;
    }
    void Append(const T& value){
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
    void Prepend(const T& value){
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
    void Set(const int& index, const T& value){
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
    void InsertAt(const T& value, const int& index){
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
        newElement->next = currentElement->next;
        currentElement->next = newElement;
        size_++;
    }

    void Swap(T* value1, T* value2)
    {
        T temp = *value1;
        *value1 = *value2;
        *value2 = temp;
    }

    void Swap(Iterator iter1, Iterator iter2){
        T temp =  *iter1;
        *iter1 = *iter2;
        *iter2 = temp;
    }


    T& operator[] (const int index){
        //обработать OutOfRange
        if (index == size_ - 1)
            return (lastElement->value_);
        Element* currentElement = firstElement;
        for (int i = 0; i < index; i++)
            currentElement = currentElement->next;
        return (currentElement->value_);
    }

    class Iterator : BaseIterator{
    private:
        Element* currentElement;
    public:
        Iterator(Element* first) : currentElement(first){}

        void operator+= (int shift) { for (int i = 0; i < shift; i++) { currentElement = currentElement->next; } }

        Element* operator++ (int)
        {
            Element* temp = currentElement;
            currentElement = currentElement->next;
            return temp;
        }
        Element* operator++ ()
        {
            currentElement = currentElement->next;
            return currentElement;
        }

        bool operator== (const Iterator& comparingIterator)
        { return currentElement != comparingIterator.currentElement; }
        bool operator!= (const Iterator& comparingIterator)
        { return currentElement != comparingIterator.currentElement; }
        T& operator* () { return currentElement->value_; }
    };
};

#endif //LAB2SEM2_LINKED_LIST_H

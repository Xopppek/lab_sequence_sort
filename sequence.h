#ifndef LAB2SEM2V2_SEQUENCE_H
#define LAB2SEM2V2_SEQUENCE_H

template <typename T>
class Sequence{
public:
    virtual int GetLength() const = 0;
    virtual T GetFirst() const = 0;
    virtual T GetLast() const = 0;
    virtual T Get(const int& index) const = 0;
    virtual Sequence<T>* GetSubSequence(const int& startIndex, const int& endIndex) = 0;
    virtual void Append(const T& value) = 0;
    virtual void Prepend(const T& value) = 0;
    virtual void Set(const int& index, const T& value) = 0;
    virtual void InsertAt(const T& value, const int& index) = 0;
    virtual void Swap(T* value1, T* value2) = 0;
    virtual T& operator[] (const int& index) = 0;
};


#endif //LAB2SEM2V2_SEQUENCE_H

#pragma once

#include <iostream>

template <class T>
class VectorIter {
public:
    VectorIter(T* element_) {
        element = element_;
    }

    bool operator!=(const VectorIter& other) {
        return element != other.element;
    }
    VectorIter operator++() {
        return (*this)++;
    }
    VectorIter& operator++(int) {
        ++element;
        return *this;
    }
    const T& operator*() const {
        return *(element);
    }
    T& operator*() {
        return *(element);
    }

private:
    T* element = nullptr;
};

template <class T>
class MyVector {
public:
    explicit MyVector(size_t size = 0)
        : Size_(size)
        , Capacity(size)
        , DataPtr(new T[Size_])
    {
    }

    ~MyVector() {
        delete[] DataPtr;
    }

    size_t size() const {
        return Size_;
    }
    T& operator[](size_t s) {
        return s >= Size_ ? throw std::out_of_range("s >= Size_") : DataPtr[s];
    }

    void pushBack(const T& element) {
        if (Size_ >= Capacity)
            Reallocate();
        DataPtr[Size_++] = element;
    }

    void Erase(size_t s) {
        for (size_t i = s; i < Size_; ++i) {
            DataPtr[i] = DataPtr[i + 1];
        }
        Size_--;
    }

    VectorIter<T> begin() {
        return DataPtr;
    }
    VectorIter<T> begin() const {
        return DataPtr;
    }
    VectorIter<T> end() {
        return DataPtr + Size_;
    }
    VectorIter<T> end() const {
        return DataPtr + Size_;
    }

    T* beginPtr() {
        return DataPtr;
    }
    T* endPtr() {
        return DataPtr + Size_;
    }

private:
    size_t Size_, Capacity;
    T* DataPtr;

    void Reallocate() {
        Capacity = (Capacity == 0 ? Capacity = 1 : Capacity * 2);
        auto new_data = new T[Capacity];
        for (size_t i = 0; i < Size_; ++i) {
            new_data[i] = DataPtr[i];
        }
        delete[] DataPtr;
        DataPtr = new_data;
    }
};

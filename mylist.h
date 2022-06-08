#pragma once

#include <iostream>

template <class T>
struct Node {
public:
    Node(const T& data, Node* prev = nullptr, Node* next = nullptr)
        : Data_(data)
        , Prev_(prev)
        , Next_(next)
    {
    }

    T Data_;
    Node* Prev_;
    Node* Next_;
};

template <class T>
class ListIter {
public:
    ListIter(Node<T>* node_) {
        node = node_;
    }

    bool operator!=(const ListIter& other) {
        return node != other.node;
    }

    ListIter operator++() {
        return (*this)++;
    }
    ListIter& operator++(int) {
        node = node->Next_;
        return *this;
    }

    T& operator*() {
        return node->Data_;
    }
    Node<T>* node = nullptr;
};

template <class T>
class MyList {
public:
    MyList(size_t size = 0)
        : First_(nullptr)
        , Last_(nullptr)
        , Size_(size)
    {
    }

    size_t size() const {
        return Size_;
    }

    ~MyList() {
        if (Size_ == 0)
            return;
        auto temp = First_;
        for (size_t i = 0; i < Size_; ++i) {
            temp = temp->Next_;
        }
        delete First_;
        delete Last_;
    }

    void pushBack(const T& element) {
        if (Size_ == 0) {
            Last_ = new Node(element);
            First_ = Last_;
        } else {
            Last_ = (Last_->Next_ = new Node(element, Last_));
        }
        ++Size_;
    }
    void pushFront(const T& element) {
        if (Size_ == 0) {
            First_ = new Node(element);
            Last_ = First_;
        } else {
            First_ = (First_->Prev_ = new Node<T>(element, nullptr, First_));
        }
        ++Size_;
    }
    void popBack() {
        if (Last_ == nullptr) {
            return;
        }
        if (First_ == Last_) {
            delete First_;
            First_ = (Last_ = nullptr);
        } else {
            auto temp = Last_;
            Last_ = Last_->Prev_;
            Last_->Next_ = nullptr;
            delete temp;
        }
        --Size_;
    }
    void popFront() {
        if (Last_ == nullptr) {
            return;
        }
        if (First_ == Last_) {
            delete First_;
            First_ = (Last_ = nullptr);
        } else {
            auto temp = First_;
            First_ = First_->Next_;
            First_->Prev_ = nullptr;
            delete temp;
        }
        --Size_;
    }

    T& operator[](const size_t& s) {
        if (s >= Size_) {
            throw std::out_of_range("s >= m_size");
        }
        auto temp = First_;
        for (size_t i = 0; i < s; ++i) {
            temp = temp->Next_;
        }
        return temp->Data_;
    }

    ListIter<T> begin() {
        return First_;
    }
    ListIter<T> end() {
        return nullptr;
    }
    ListIter<T> begin() const {
        return First_;
    }
    ListIter<T> end() const {
        return nullptr;
    }

private:
    Node<T>* First_;
    Node<T>* Last_;
    size_t Size_;
};

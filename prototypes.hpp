#ifndef PRO_HPP
#define PRO_HPP

#include <iostream>

template <typename T>
class MyVector
{
    public:
    //CONSTRUCTORS AND DESTRUCTOR
        MyVector();
        MyVector(T, size_t);
        MyVector(std::initializer_list<T> list);
        MyVector(const MyVector& other);
        MyVector(MyVector&& other);
        ~MyVector();

    //OPERATORS
        T& operator[](int);
        MyVector& operator=(const MyVector&);
        MyVector& operator=(MyVector&&);

    //METHODS
        void print();
        void allocator();
        int size();
        int max_size();
        void resize(int);
        int capacity();
        bool empty();
        void reserve(int);
        void shrink_to_fit();
        T& at(int);
        T& front();
        T& back();
        T* data();
        void push_back(T);
        void pop_back();
        void insert(int,T);
        void erase(int);
        void clear();
        void emplace(int,T);
        void emplace_back(T);

    private:
    //MEMBERS
        size_t v_size;
        size_t v_cap;
        T* ptr;
};

template <typename T>
std::ostream& operator<<(std::ostream& os, const MyVector<T>& obj);

#include "implementations.hpp"

#endif
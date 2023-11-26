#ifndef PROTOTYPES_HPP
#define PROTOTYPES_HPP

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
        void swap(MyVector&);

    private:
    //MEMBERS
        size_t v_size;
        size_t v_cap;
        T* ptr;
};

template <typename T>
std::ostream& operator<<(std::ostream& os, const MyVector<T>& obj);



/////////////////////////BITVECTOR//////////////////////

template <>
class MyVector<bool>
{
    public:
    //CONSTRUCTORS AND DESTRUCTOR
        MyVector(); 
        MyVector(bool, size_t);
        MyVector(std::initializer_list<bool> list);
        MyVector(const MyVector& other);
        MyVector(MyVector&& other);
        ~MyVector();

//METHODS
        void print(); 
        void allocator();
        size_t size();
        int max_size();
        void resize(size_t);
        size_t capacity();
        bool empty();
        void reserve(size_t);
        void shrink_to_fit();
        size_t& at(int);
        size_t& front();
        size_t& back();
        size_t* data();
        void push_back(bool);
        void pop_back();
        void insert(int,bool);
        void erase(int);
        void clear();
        void emplace(int,bool);
        void emplace_back(bool);

    private:
//MEMBERS
        size_t v_size;
        size_t v_cap;
        size_t user_cap;
        size_t* ptr;
};

#include "implementations.hpp"

#endif
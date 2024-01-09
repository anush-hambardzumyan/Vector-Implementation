#ifndef PROTOTYPES_HPP
#define PROTOTYPES_HPP

#include <iostream>

template <typename T>
class MyVector
{
    public:
    class iterator
    {
        public:
        iterator (T* ptr1) : ptr(ptr1) {}  //PARAMETRIZED CONSTRUCTOR
        iterator () : ptr(nullptr) {}      //DEFAULT CONSTRUCTOR
        T& operator*();
        T* operator ->();
        iterator& operator=(const iterator& obj);
        iterator& operator++();     //prefix
        iterator& operator--();      //prefix
        iterator operator++(int);    //postfix
        iterator operator--(int);    //postfix
        iterator operator +(unsigned int n);
        iterator& operator += (unsigned int n);
        iterator operator - (unsigned int n);
        iterator& operator -= (unsigned int n);
        bool operator == (const iterator& other);
        bool operator != (const iterator& other);
        bool operator > (const iterator& other);
        bool operator < (const iterator& other);
        bool operator >= (const iterator& other);
        bool operator <= (const iterator& other);
        T& operator[](int i);
        iterator (const iterator & other) : ptr(other.ptr) {}

        private:
        T* ptr;
    };

    iterator begin()
    {
        return iterator(this -> data());
    }

    iterator end()
    {
        return iterator(this -> data() + this -> size());
    }

    private:
    //MEMBERS
        size_t v_size;
        size_t v_cap;
        T* ptr;

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
        void insert(iterator,const T&);
        void erase(iterator pos);
        void clear();
        void emplace(int,T);
        void emplace_back(T);
        void swap(MyVector&);

};

template <typename T>
std::ostream& operator<<(std::ostream&, const MyVector<T>&);



/////////////////////////BITVECTOR//////////////////////////////

template <>
class MyVector<bool>
{
    public:
       friend std::ostream& operator<<(std::ostream& , const MyVector<bool>&);
    //CONSTRUCTORS AND DESTRUCTOR
        MyVector();   //done
        MyVector(bool, size_t);   //done
        MyVector(std::initializer_list<bool>);  //done
        MyVector(const MyVector&);  //done
        MyVector(MyVector&&);  //done
        ~MyVector();   //done

    //METHODS
        void print(); //done
        void allocator();  //done
        size_t size() const; //done
        int max_size(); //done
        void resize(size_t);        
        size_t capacity();  //done
        bool empty();  //done
        void reserve(size_t);  //done 
        void shrink_to_fit();
        size_t& at(int);  //done
        size_t& front();  //done
        size_t& back();  //done
        size_t* data();   //done
        void push_back(bool);  //done
        void pop_back();   //done
        void insert(int,bool);  //done
        void erase(int);  
        void clear();    //done
        void swap(MyVector<bool>&);   //done
        
    private:
    //MEMBERS
        size_t v_size;
        size_t v_cap;
        size_t user_cap;
        size_t* ptr;

    public:
        class reference
        {
            public:
            reference(size_t* , size_t ); //done
            reference(const reference&); 
            reference& operator=(const reference&);  //done
            reference& operator=(bool);  //done
            operator bool();

            private:
            size_t* r_ptr;
            size_t index;
            bool value; 
        };
    
    public:
    reference operator[](size_t);  //done
};

std::ostream& operator<<(std::ostream&  os, const MyVector<bool>& obj);

#include "implementations.hpp"

#endif
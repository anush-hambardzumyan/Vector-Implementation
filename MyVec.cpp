#include <iostream>

template <typename T>
class MyVector
{
    private:
        int v_size;
        int v_cap;
        T* ptr;

    public:
        MyVector()
        {
            v_size = 0;
            v_cap = 10;
            ptr = nullptr;
        }

        MyVector(T val, int quantity)
        {
            v_size = quantity;
            v_cap = v_size;
            ptr = new T[v_size];
            for(int i = 0; i < v_size; ++i)
            {
                ptr[i] = val;
            }
        }

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
        void assign(T);
        void push_back(T);
        void pop_back();
        void insert(int,T);
        void erase(int);
        //void swap(T &);
        void clear();
        void emplace(int,T);
        void emplace_back(T);
};

template <typename T>
void MyVector<T>::allocator() // for creatiing an object, at first we need a memory allocator
{
    ptr = new int[10];
    v_cap = 10;         //sets capacity 10 by default
}

template <typename T>
int MyVector<T>::size()
{
    return v_size; 
}

template <typename T>
void MyVector<T>::print()
{
    for(int i = 0; i < v_size; ++i)
    {
        std::cout << ptr[i] << " ";
    }
    std::cout << std::endl;
}

template <typename T>
int MyVector<T>::max_size()
{
    return 1073741823; 
}

template <typename T>
void MyVector<T>::resize(int newsize)
{
    if(newsize > v_cap)   //if new size is greater that capacity 
    {
        T* ptrr = new T [newsize];  // we allocate a new memory block
        for(int i = 0; i < v_size; ++i)
        {
            ptrr[i] = ptr[i];   //filling it with same members
        }
        delete[] ptr;
        ptr = ptrr;
        ptrr = nullptr;
        v_cap = newsize; // and update the capacity
    } 

    else
    {
        v_size = newsize;
        int* ptrr = new T [v_size];
        for(int i = 0; i < v_size; ++i)
        {
            ptrr[i] = ptr[i];  //else we just ignore the elements, whose indexes are grater than the new size
        }
        delete[] ptr;
        ptr = ptrr;
        ptrr = nullptr;
    }
}

template <typename T>
int MyVector<T>::capacity()
{
    return v_cap; 
}

template <typename T>
bool MyVector<T>::empty()
{
    return v_size == 0; 
}

template <typename T>
void MyVector<T>::reserve(int newcap)
{
    if(newcap > v_cap) //reserve will only work in case, when the given argument is greater than the old capacity
    {
        T* ptrr = new T [newcap];
        for(int i = 0; i < v_size; ++i)
        {
            ptrr[i] = ptr[i];  //so it fills the new allocated memory with the same elements
        }
        delete[] ptr;
        ptr = ptrr;
        ptrr = nullptr;
        v_cap = newcap;  //and updates the capacity
    }
}

template <typename T>
void MyVector<T>::shrink_to_fit()
{
    T* ptrr = new T[v_size];   
    for(int i = 0; i < v_size; ++i)
    {
        ptrr[i] = ptr[i];  //makes a new vector that has the same elements 
    }
    delete[] ptr;
    ptr = ptrr;
    ptrr = nullptr;
    v_cap = v_size;  //and its capacity and size are equal one to another
}

template <typename T> 
T& MyVector<T>::at(int pos)
{
    if(pos < v_size && pos >= 0)  //check for the element existence
    {
        return ptr[pos];
    }

    else
    {
        std::cout << "unvalid operation: " <<std::endl;
    }
}

template <typename T>
T& MyVector<T>::front()
{
    return &ptr[0];
}

template <typename T>
T& MyVector<T>::back()
{
    return &ptr[v_size - 1];
}

template <typename T>
T* MyVector<T>::data()
{
    if(v_size == 0)
    {
        return nullptr; //if there are elements in vec, data method returns pointer to the first element of it
    }

    return ptr;
}

template <typename T>
void MyVector<T>::push_back(T val) 
{
    if(ptr == nullptr)
    {
        allocator();  //checking, if the vector is empty or not
    }

    if(v_size + 1 == v_cap)
    {
        v_cap *= 2;
        T* ptrr = new T[v_cap];   //in case that the +1 element will make a cause of getting bigger capacity
        for (int i = 0; i < v_size; ++i)   
        {
            ptrr[i] = ptr[i];
        }
    } 
    ptr[v_size++] = val;
}

template <typename T>
void MyVector<T>::pop_back()
{
    if(v_size == 0)
    {
        std::cout << "unvalid operation: " << std::endl;  //check of vector's emptiness
        return;
    }

    v_size -= 1;                //update the size 
    T* ptrr = new T[v_size];
    for(int i = 0; i < v_size; ++i)
    {
        ptrr[i] = ptr[i];       //fill the new array with the old elements except the last one
    }
    delete[] ptr;
    ptr = ptrr;
    ptrr = nullptr;
}

template <typename T>
void MyVector<T>::insert(int pos, T val)
{
    if(pos < 0 || pos > v_size - 1)
    {
        std::cout << "unvalid operation: " << std::endl;  //checking if the given position is valid for insertion
        return;
    }

    else
    {
        int *ptrr = new int [++v_cap];
        for (int i = 0; i < pos; ++i)
        {
            ptrr[i] = ptr[i];
        }
        ptrr[pos] = val;            //inserting the element in right position

        for (int j = pos; j < v_size; ++j) 
        {
            ptrr[j + 1] = ptr[j];
        }

        delete[] ptr;
        ptr = ptrr;
        ptrr = nullptr;
        v_size++;
    }
}

template <typename T>
void MyVector<T>::erase(int pos) 
{
    if (v_size != 0 && pos >= 0 && pos < v_size)  //checking if the given position is valid for erasing an element
    {
        T* ptrr = new T[v_size - 1];
        for (int i = 0; i < pos; ++i) 
        {
            ptrr[i] = ptr[i];
        }

        for (int i = pos + 1; i < v_size; ++i) 
        {
            ptrr[i - 1] = ptr[i];               // ignoring the element of given position, so it gets erased
        }

        delete[] ptr;
        ptr = ptrr;
        ptrr = nullptr;
        --v_size;
    } 

    else 
    {
        std::cout << "unvalid operation: " << std::endl;
        return;
    }
}

// template <typename T>
// void MyVector<T>::swap(T& other)
// {
    
// }

template <typename T>
void MyVector<T>::clear()
{
    delete[] ptr;
    v_size = 0;
    v_cap = 0;
    ptr = nullptr;
}

template <typename T>
void MyVector<T>::emplace(int pos, T val)
{
    if(pos < 0 || pos > v_size - 1)
    {
        std::cout << "unvalid operation: " << std::endl;  //checking if the given position is valid for emplacement
        return;
    }

    else
    {
        int *ptrr = new int [++v_cap];
        for (int i = 0; i < pos; ++i)
        {
            ptrr[i] = ptr[i];
        }
        ptrr[pos] = val;            //emplacing the element in right position

        for (int j = pos; j < v_size; ++j) 
        {
            ptrr[j + 1] = ptr[j];
        }

        delete[] ptr;
        ptr = ptrr;
        ptrr = nullptr;
        v_size++;
    }
}


template <typename T>
void MyVector<T>::emplace_back(T val)
{
    if(ptr == nullptr)
    {
        allocator();  //checking, if the vector is empty or not
    }

    if(v_size + 1 == v_cap)
    {
        v_cap *= 2;
        T* ptrr = new T[v_cap];   //in case that the +1 element will make a cause of getting bigger capacity
        for (int i = 0; i < v_size; ++i)   
        {
            ptrr[i] = ptr[i];
        }
    } 
    ptr[v_size++] = val;  //emplacing the element from the end of vector
}
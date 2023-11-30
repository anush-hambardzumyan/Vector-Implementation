#include "prototypes.hpp"

enum noname {BITCOUNT = sizeof(size_t) * 8};

//***CONSTRUCTORS***

    //DEFAULT CONSTRUCTOR
    template <typename T> 
    MyVector<T>::MyVector() 
    {
        v_size = 0;
        v_cap = 10;
        ptr = nullptr;
    }

    //DESTRUCTOR
    template <typename T>
    MyVector<T>::~MyVector()
    {
        if(ptr != nullptr)
        {
            delete[] ptr;
        }
    }

    //PARAMETERIZED CONSTRUCTOR
    template <typename T>
    MyVector<T>::MyVector(T val, size_t quantity)
    {
        v_size = quantity;
        v_cap = v_size;
        ptr = new T[v_size];
        for(int i = 0; i < v_size; ++i)
        {
            ptr[i] = val;
        }
    }

    //INITIALIZER LIST CONSTRUCTOR
    template <typename T>
    MyVector<T>::MyVector(std::initializer_list<T> list)
    {
        v_size = list.size();
        v_cap = v_size;
        ptr = new T[v_cap];  

        for (size_t i = 0; i < v_size; ++i)
        {
            ptr[i] = *(list.begin() + i);
        }
    }

    //MOVE CONSTRUCTOR
    template <typename T>
    MyVector<T>::MyVector(MyVector&& list)
    {
        v_size = list.size();
        v_cap = list.capacity();
        ptr = new T [v_cap];
        for(int i = 0; i < v_size; ++i)
        {
            ptr[i] = list[i];
        }
        list.v_size = 0;
        list.v_cap = 0;
        delete[] list.ptr;
        list.ptr = nullptr;
    }

    //COPY CONSTRUCTOR
    template <typename T>
    MyVector<T>::MyVector(const MyVector& other)
    {
        v_size = other.v_size;
        v_cap = other.v_cap;
        ptr = new T[v_cap];
        for (size_t i = 0; i < v_size; ++i)
        {
            ptr[i] = other.ptr[i];
        }
    }


//***OPERATORS***

    //SUBSCRIPT OPERATOR
    template <typename T>
    T& MyVector<T>::operator[] (int index)
    {
        return ptr[index];
    }

    //MOVE ASSIGNMENT
    template <typename T>
    MyVector<T>& MyVector<T>::operator=(MyVector&& other)     
    {
        if (this != &other) 
        {
            delete[] ptr;
            v_cap = other.v_cap;
            v_size = other.v_size;
            ptr = other.ptr;
            other.v_cap = 0;
            other.v_size = 0;
            other.ptr = nullptr;
        }
        return *this;
    }

    //COPY ASSIGNMENT
    template <typename T>
    MyVector<T>& MyVector<T>::operator=(const MyVector& other)    
    {
        if (this != &other)
        {
            delete[] ptr;
            v_cap = other.v_cap;
            v_size = other.v_size;
            ptr = new T[v_cap];
            for (size_t i = 0; i < v_size; ++i)
            {
                ptr[i] = other.ptr[i];
            }
        }
        return *this;
    }

    //OSTREAM OPERATOR
    template <typename T>
    std::ostream& operator<<(std::ostream& os,MyVector<T>& obj) 
    {
        for (int i = 0; i < obj.size(); ++i)
        {
            os << obj[i];
            if (i < obj.size() - 1)
            {
                os << " ";
            }
        }
        os << std::endl;
        return os;
    }


//***METHODS***

template <typename T>
void MyVector<T>::allocator() // for creatiing an object, at first we need a memory allocator
{
    ptr = new int[10];
    v_size = 0;
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
        exit(0);
    }
}

template <typename T>
T& MyVector<T>::front()
{
    if(v_size)
    {
        return ptr[0];
    }

    else
    {
        std::cout << "unvalid operation: " << std::endl;
        exit(0);
    }
}

template <typename T>
T& MyVector<T>::back()
{
    if(v_size)
    {
        return ptr[v_size - 1];
    }

    else
    {
        std::cout << "unvalid operation: " << std::endl;
        exit(0);
    }
}

template <typename T>
T* MyVector<T>::data()
{
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
    if (v_size != 0 && pos >= 0 && pos < v_size)  // Checking if the given position is valid for erasing an element
    {
        T* ptrr = new T[v_size - 1];
        for (int i = 0; i < pos; ++i) 
        {
            ptrr[i] = ptr[i];
        }

        for (int i = pos + 1; i < v_size; ++i) 
        {
            ptrr[i - 1] = ptr[i];  // Ignoring the element at the given position, so it gets erased
        }

        delete[] ptr;
        ptr = ptrr;
        ptrr = nullptr;
        --v_size;
    } 

    else 
    {
        std::cout << "Invalid operation: " << std::endl;
        exit(0);
    }
}

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

template <typename T> 
void MyVector<T>::swap(MyVector& x)
{
    std::swap(this -> ptr , x.ptr);
    std::swap(this -> v_size , x.v_size);
    std::swap(this -> v_cap , x.v_cap);
}


////////////////////////BITVECTOR/////////////////////////

//**CONSTRUCTORS**

//DEFAULT CONSTRUCTOR
MyVector<bool>::MyVector()
{
    ptr = nullptr;
    v_size = 0;
    v_cap = 0;
}

//PARAMETRIZED CONSTRUCTOR
MyVector<bool>::MyVector(bool value , size_t quantity)
{
    v_size = quantity;
    if(quantity / BITCOUNT)
    {
        v_cap = (quantity / BITCOUNT) + 1;
    }

    else
    {
        v_cap = quantity / BITCOUNT;
    }

    ptr = new size_t [v_cap];

    if(value)
    {
        for(size_t i = 0 ; i < quantity; ++i)
        {
            ptr[i / BITCOUNT] |= 1ULL << (i % BITCOUNT);
        }
    }  
}

//INITIALIZER LIST CONSTRUCTOR
MyVector<bool>::MyVector(std::initializer_list<bool> list)
{
    v_size = list.size();
    if(v_size / BITCOUNT)
    {
        v_cap = (v_size / BITCOUNT) + 1;
    }
    else
    {
        v_cap = v_size / BITCOUNT;
    }

    ptr = new size_t[v_cap];

    size_t i = 0;
    for (const bool value : list) 
    {
        if (value) {
            ptr[i / BITCOUNT] |= (1ULL << (i % BITCOUNT));
        }
        ++i;
    }
}

//COPY CONSTRUCTOR
MyVector<bool>::MyVector(const MyVector<bool>& other)
:v_size(other.v_size) , v_cap(other.v_cap) , user_cap(other.v_cap * BITCOUNT)
{
    ptr = new size_t[v_cap]();

    for(size_t i = 0 ; i < v_size; ++i)
    {
        if (other.ptr[i / BITCOUNT] & (1ULL << (i % BITCOUNT))) 
        {
            ptr[i / BITCOUNT] |= (1ULL << (i % BITCOUNT));
        }    
    }
}

//MOVE CONSTRUCTOR
MyVector<bool>::MyVector(MyVector<bool>&& other)
:v_size(other.v_size), v_cap(other.v_cap) , user_cap(v_cap * BITCOUNT)
{
    ptr = other.ptr;
    other.ptr = nullptr;
    other.v_size = 0;
    other.v_cap = 0;
}

//DESTRUCTOR
MyVector<bool>::~MyVector()
{
    if(ptr != nullptr)
    {
        delete[] ptr;
    }
}


//**REFERENCES**

//REFERENCE CONSTRUCTOR
MyVector<bool>::reference::reference(size_t* ptr , size_t index1)
:r_ptr(ptr) , index(index1)
{
    value = r_ptr[index1/BITCOUNT] & (1 << index1 % BITCOUNT);
}



//**METHODS**

void MyVector<bool>::allocator()
{
    ptr = new size_t[1];
    v_size = 0;
    v_cap = BITCOUNT;
    user_cap = BITCOUNT;
}

void MyVector<bool>::push_back(bool val) 
{
    if(ptr == nullptr)
    {
        allocator();
    }

    if(v_size + 1 == v_cap)
    {
        size_t* ptr1 = new size_t[v_cap/BITCOUNT + 1];
        for(size_t i = 0; i < v_cap/BITCOUNT; ++i)
        {
            ptr1[i] = ptr[i];
        }
        delete[] ptr;
        ptr = ptr1;
        ptr1 = nullptr;
        v_cap ++;
        user_cap = v_cap * BITCOUNT;
    }

    if (val) 
    {
        size_t x = 1 << (v_size % BITCOUNT);
        ptr[v_size / BITCOUNT] |= x;
    }
    v_size++;
};

void MyVector<bool>::print()
{
    size_t x = 1ULL << (BITCOUNT - 1);

    for (size_t i = 1; i <= v_size; ++i) 
    {
        size_t index = (i - 1) / BITCOUNT;
        size_t offset = (i - 1) % BITCOUNT;
        bool bit = (ptr[index] >> offset) & 1;
        std::cout << bit;
    }
    std::cout << std::endl;
}

size_t MyVector<bool>::size() const
{
    return v_size;
}

int MyVector<bool>::max_size()
{
    return 1073741823;
}

size_t MyVector<bool>::capacity()
{
    return user_cap;
}

bool MyVector<bool>::empty() 
{
    return v_size == 0;
}

void MyVector<bool>::pop_back()
{
    if(v_size == 0)
    {
        std::cout << "unvalid operation" << std::endl;
        exit(0);
    } 

    ptr[v_cap/BITCOUNT - 1] &= ~(1 << (v_size));
    v_size -- ;
}

void MyVector<bool>::reserve(size_t newcap)
{
    if(newcap > v_size)
    {
        if(newcap % BITCOUNT == 0)
        {
            size_t *ptrr = new size_t[newcap/BITCOUNT];
            for(int i = 0; i < newcap/BITCOUNT ; ++i)
            {
                ptrr[i] = ptr[i];
            }
            delete[] ptr;
            ptr = ptrr;
            ptrr = nullptr;
        }

        else
        {
            size_t *ptrr = new size_t[(newcap/BITCOUNT) + 1];
            for(int i = 0 ; i < newcap/BITCOUNT + 1 ; ++i)
            {
                ptrr[i] = ptr[i];
            }
            delete[] ptr;
            ptr = ptrr;
            ptrr = nullptr;
        }
    }
}

void MyVector<bool>::insert(int pos , bool val)
{
    if(pos > v_size)
    {
        std::cout << "unvalid operation:" << std::endl;
        exit(0);
    }

    if ((v_size + 1) % BITCOUNT == 0) 
    {
        size_t* ptr1 = new size_t[(v_cap / BITCOUNT) + 1];
        for (size_t i = 0; i < v_cap / BITCOUNT; ++i) 
        {
            ptr1[i] = ptr[i];
        }
        delete[] ptr;
        ptr = ptr1;
        ptr1 = nullptr;
        v_cap *= 2;
        user_cap = v_cap;
    }

    for (size_t i = v_size; i > pos; --i) 
    {
        size_t index = (i - 1) / BITCOUNT;
        size_t offset = (i - 1) % BITCOUNT;
        bool bit = (ptr[index] >> offset) & 1;
        size_t newBit = bit ? 1 << offset : 0;
        ptr[index + 1] |= newBit;
    }

    size_t index = pos / BITCOUNT;
    size_t offset = pos % BITCOUNT;
    size_t x = 1 << offset;
    ptr[index] |= (val ? x : 0);

    ++v_size;
}

size_t& MyVector<bool>::at(int pos)
{
    if(pos < v_size && pos >= 0) 
    {
        return ptr[pos];
    }

    else
    {
        std::cout << "unvalid operation: " <<std::endl;
        exit(0);
    }
}

size_t& MyVector<bool>::front()
{

    if(v_size)
    {
        return ptr[0];
    }

    else
    {
        std::cout << "unvalid operation: " << std::endl;
        exit(0);
    }
}

size_t& MyVector<bool>::back()
{
    if(v_size)
    {
        return ptr[v_size - 1];
    }

    else
    {
        std::cout << "unvalid operation: " << std::endl;
        exit(0);
    }
}

void MyVector<bool>::swap(MyVector<bool>& obj)
{
    std::swap(this -> ptr , obj.ptr);
    std::swap(this -> v_cap , obj.v_cap);
    std::swap(this -> v_size , obj.v_size);
    std::swap(this -> user_cap , obj.user_cap);
}

void MyVector<bool>::clear()
{
    if(ptr)
    {
        delete[] ptr;
        v_size = 0;
        v_cap = 0;
        user_cap = 0;
    }
}

size_t* MyVector<bool>::data()
{
    return ptr;
}



//**OPERATORS**

//SUBSCRIPT OPERATOR FOR BOOLVECTOR
MyVector<bool>::reference MyVector<bool>::operator[](size_t index1)
{
    return MyVector<bool>::reference(ptr,index1);
}

//BOOL CAST OVERLOADING FOR REFERENCE
MyVector<bool>::reference::operator bool()
{
    return value;
}

//ASSIGNMENT FOR OBJECT
MyVector<bool>::reference& MyVector<bool>::reference::operator=(const reference& obj)
{
    if(value != obj.value)
    {
        this -> r_ptr[index / BITCOUNT] ^= 1ULL << (index % BITCOUNT);
    }
    return *this;
}

//ASSIGNMENT FOR BOOL VARIABLE
MyVector<bool>::reference& MyVector<bool>::reference::operator=(bool value)
{
    if(this -> value != value)
    {
        this -> r_ptr[index / BITCOUNT] ^= 1ULL << (index % BITCOUNT);
    }
    return *this;
}

//OUTPUT STREAM OPERATOR
std::ostream& operator<<(std::ostream& os,  const MyVector<bool>& obj)
{
    size_t size = obj.size();
    for (size_t i = 0; i < obj.size(); ++i)
        {
            os << (obj.ptr[i] & (1ULL << (i % BITCOUNT)));
            if (i < obj.size() - 1)
            {
                os << " ";
            }
        } 
        os << std::endl;
        return os;
}

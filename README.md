# Vector-Implementation

In C++, a vector is a dynamic array, meaning that its size can grow or shrink as needed during program execution. Vectors are part of the C++ Standard Template Library (STL). This implementation gives us wide opportunities because of usage of templates in it. Usage of templates made implementation more flexible for many data types. 

![IMG_1825 3](https://github.com/anush-hambardzumyan/Vector-Implementation/assets/66312436/29efc6eb-ba9a-45c0-a4b6-f97839a758df)


As I tried to make my vector very similar to std::vector, I also added an iterators class, and methods that were implemented with iterators in std::vector, are implemented with my self-made iterators in this implementation.

Here is the list of implemented

### **Constructors:**  
* Default Constructor
* Parametrized Constructor
* Initialaizer List Constructor
* Copy Constructor
* Move Constructor  

### **Opeartors:**  
* Subscript operator ([])  
* Copy Assignment (=)  
* Move Assignment (=)  
* Output Stream Operator (<<)  

### **Methods:**  
* size
* max_size  
* resize  
* capacity  
* empty   
* reserve  
* shrink_to_fit  
* at  
* front   
* back  
* data   
* push_back  
* pop_back  
* insert  
* erase  
* clear  
* emplace   
* emplace_back  
* swap  

______

Quite important was exploring the work of std::vector<bool> specialization, that works absouloutly different way, then with the other data types.I made a bool vector specialization that works the exactly the same way, as the STL's vector. For realisation of that I made another class for bool vector , and it needed another nested class "reference" for getting access to elements of bool vector with subscript operator like the int vector and etc.
![9eccf7ce-1cb3-403c-a604-01dbad1f9fe9](https://github.com/anush-hambardzumyan/Vector-Implementation/assets/66312436/6d6e3aaf-a067-41c2-9917-49413113c93d)


### **Constructors for boolvector:**  
* Default Constructor  
* Parametrized Constructor   
* Initialaizer List Constructor   
* Copy Constructor   
* Move Constructor   

### **Opeartors:**  
* Subscript operator ([])
* Copy Assignment (=)
* Move Assignment (=)
* Output Stream Operator (<<)  

### **Methods:**    
* size
* max_size
* capacity
* empty
* reserve
* at
* front
* back
* data
* push_back
* pop_back
* insert
* clear  


Important to note, that in standard library many of this methods are overloaded, but for now I just wrote unique versions of them. Some of methods may be a little modificated, because of my humble knowledge in programming, but i tried to save the idea of how they work in original version.

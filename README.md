# Vector-Implementation
**Vector** is a one-dimensional data structure and all of its elements are of the same data type. 
Vectors are the same as dynamic arrays with the ability to resize itself automatically when an element is inserted or deleted, with their storage being handled automatically by the container. Vector elements are placed in contiguous storage so that they can be accessed and traversed using iterators. In vectors, data is inserted at the end. Inserting at the end takes differential time, as sometimes the array may need to be extended.

![ezgif-4-096e540da9](https://github.com/anush-hambardzumyan/Vector-Implementation/assets/66312436/75a13a65-e247-4978-ab39-f4cdd86d4897)
________
### Complexity
**The time complexity for doing various operations on**
| Operation | Complexity |
| :----: | :----: | 
| Random Access | O(1) | 
| Insertion at the end | O(1) | 
| Removal at the end | O(1) | 
| Insertion  | O(n) | 
| Removal | O(n) | 
| Knowing the size | O(1) | 
| Resizeing | O(n) | 
__________

As I tried to make implementation similar to std::vector, I made a specialization for bool vector that works in optimized way. For that specialization I implemented special nested class to get access to the element of bool vector such as elemnts of ordinary int vector. Implementation also includes self-made and all the methods of that use iterators in STL, are working the same way in this implementation.

![9eccf7ce-1cb3-403c-a604-01dbad1f9fe9](https://github.com/anush-hambardzumyan/Vector-Implementation/assets/66312436/de44a2f0-55bf-4505-af7d-8d43ca284b6d)

_____

| Constructors | Operators |
| :----- | :----- | 
| - Default Constructor| - Subscript operator ([])|
| - Parametrized Constructor | - Copy Assignment (=)|
| - Initialaizer List Constructor| - Move Assignment (=) |
| - Copy Constructor| - Output Stream Operator (<<) |
| - Move Constructor| |
_______

**Implemented Methods:**
- [x] size
- [x] max_size
- [x] resize
- [x] capacity
- [x] empty
- [x] reserve
- [x] shrink_to_fit
- [x] at
- [x] front
- [x] back
- [x] data
- [x] push_back
- [x] pop_back
- [x] insert
- [x] erase
- [x] clear
- [x] emplace
- [x] emplace_back
- [x] swap


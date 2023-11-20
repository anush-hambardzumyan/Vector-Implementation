# Vector-Implementation
Vector Implementation using class and templates, without usage of header files.

Vector is a one-dimensional data structure and all of its elements are of the same data type. Previously I implemented a vector using struct and it was implemented only for an int data type. This implementation gives us wider opportunities because of usage of templates in it. Usage of templates made my implementation more flexible for many data types, and now we are not used to only use int data type. Now it's almost equal implementation to vector of standard library, just with less methods.
I implemented overloaded constructor, basic and not basic methods of std::vector.
List of implemented methods:
1.size
2.max_size
3.resize
4.capacity
5.empty
6.reserve
7.shrink_to_fit
8.at
9.front
10.back
11.data
12.assign
13.push_back
14.pop_back
15.insert
16.erase
17.clear
18.emplace
19.emplace_back

Important to note, that in standard library many of this methods are overloaded, but for now I just wrote unique versions of them. Some of methods may be a little modificated, because of my humble knowledge in programming, but i tried to save the idea of how they work in original version.
Hope you like it :)

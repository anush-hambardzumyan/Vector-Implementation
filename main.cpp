#include "prototypes.hpp"

int main()
{
    MyVector<int> vec;
    MyVector<int> vec0 (0,10);
    MyVector<int> vec1 {2,3,4} ;
    //MyVector<int> vec2(move(vec1));
    vec0.print();
    std::cout << vec0;
    //vec2.print();
}
#include "prototypes.hpp"

int main()
{
    // MyVector<bool> vec;
    // vec.push_back(1);
    // vec.push_back(0);
    // vec.push_back(0);
    // vec.push_back(0);
    // vec.push_back(0);
    // vec.push_back(1);
    // vec.print();
    // vec.insert(2,1);
    // //vec.push_back(1);
    // vec.print();
    // vec.pop_back();
    // vec.print();
    // std::cout << vec.size();

    MyVector<int> vec1(2,10);
    MyVector<int> vec2 (4,7);

    std::cout << vec1;
    std::cout << vec2;
    vec1.swap(vec2);
    std::cout << vec1;
    std::cout << vec2;
}
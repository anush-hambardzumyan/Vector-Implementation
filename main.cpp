#include "prototypes.hpp"

int main()
{
    // MyVector<bool> vec;
    // vec.push_back(1);
    // vec.push_back(0);
    // vec.push_back(0);
    // vec.push_back(0);
    // vec.push_back(1);
    // vec.push_back(1);
    // std::cout << vec;
    // vec.print();
    // for(size_t i = 0; i < vec.size() ; ++i)
    // {
    //     std::cout << vec[i];
    // }
    // std::cout << std::endl;
    // vec[2] = 1;
    // vec.print();

    // MyVector<bool> vec1  = std::move(vec);
    // vec1.print();
    // vec.print();


    // MyVector<bool> vec2 {1,0,1,0,1,1,1,0};
    // vec2.print();

    // MyVector<bool> vec3(vec1);
    // vec3.print();

    //vec.insert(2,1);
    //vec.push_back(1);
    // vec.print();
    // vec.pop_back();
    // vec.print();
    // std::cout << vec.size();

    // MyVector<int> vec1(2,10);
    // MyVector<int> vec2 (4,7);

    MyVector<int> vec;
    vec.push_back(10);
    vec.push_back(9);
    vec.push_back(8);
    vec.push_back(7);

    MyVector<int>::iterator it;
    for(it = vec.begin() ; it != vec.end(); ++it)
    {
        std::cout << *it << " " ;
    }
    std::cout << std::endl;
    vec.at(1) = 2;
    for(it = vec.begin() ; it != vec.end(); ++it)
    {
        std::cout << *it << " " ;
    }
    std::cout << std::endl;

    vec.insert(vec.begin() + 1, 4);
    for(it = vec.begin() ; it != vec.end(); ++it)
    {
        std::cout << *it << " " ;
    }
    std::cout << std::endl;

    vec.erase(vec.begin() + 1);
    for(it = vec.begin() ; it != vec.end(); ++it)
    {
        std::cout << *it << " " ;
    }
    std::cout << std::endl;
}
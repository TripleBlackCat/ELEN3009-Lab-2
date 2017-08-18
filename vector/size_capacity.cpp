// size_capacity.cpp
// Vector size versus capacity

#include <vector>
#include <iostream>

using namespace std;

int main()
{
    vector<int> vec;
    cout << "vec: size: " << vec.size() 
         << " capacity: " << vec.capacity() << endl;
        
    // The size of the vector is the number of elements stored in the vector. 
    // The capacity of the vector is the maximum number of elements before reallocation
    // A vector is a dynamic array of elements. It has a capacity of 0 when it is first initialized and empty. As soon as the number of elements inside the array reaches the capacity, the capacity doubles to allow for more elements to be inserted.


    for(int i = 0; i < 24; i++) {
        vec.push_back(i);
        cout << "vec: size: " << vec.size() 
             << " capacity: " << vec.capacity() << endl;
    }

    return 0;
}

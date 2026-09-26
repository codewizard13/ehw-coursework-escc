/* ************************************************************
    Course: ESCC, CIS-251 - C++ Programming
    Self-Directed (Not Assigned) Practice Exercises

    YT: Tech with Tim - https://www.youtube.com/watch?v=RXzzE2wnnlo

    Student: Eric Hepperle
    Created: 2026-09-26

    VERSION: 1.0

    STATUS: Fully Working

    Purpose / Instructions:
    - Demonstrate vector array management techniques and methods

    📝 Lessons Learned:
    - vectors are arrays that can change their size; if you add/remove elements to/from the array, the vector will automatically allocate the correct memory size
    - capacity: how many elements a vector can hold, vs. size which is how many elements it is ACTUALLY  holding
    - when the vector size is increased by one more than size, it auto-allocates double(?) the original size
    - pop_back(): removes and returns the very last element of the vector
    - how to reduce the capacity of a vector/ shrink: shrink_to_fit()


    FUTURE IMPROVEMENTS:
    - ...

    GitHub: https://github.com/codewizard13
    email: codewizard13@gmail.com
 ************************************************************ */

#include <iostream>
#include <vector>
using namespace std;

int main()
{

    vector<int> v1 = {1, 2, 3};

    cout << v1[1] << endl;
    cout << v1[2] << endl;
    cout << v1.front() << endl;
    cout << v1.back() << endl;
    cout << "Size: " << v1.size() << endl;
    cout << "Capacity: " << v1.capacity() << endl;

    cout << "*****************************" << endl;
    cout << "Appending to vector with push_back() ...\n";

    v1.push_back(9); // append to end of vector
    v1.push_back(9); // append to end of vector
    v1.push_back(9); // append to end of vector
    v1.push_back(9); // append to end of vector
    v1.push_back(9); // append to end of vector
    
    cout << "Capacity: " << v1.capacity() << endl;
    cout << "Size: " << v1.size() << endl;

    cout << "*****************************" << endl;
    cout << "Popping the last element off ...\n";
    v1.pop_back();
    cout << "Capacity: " << v1.capacity() << endl;
    cout << "Size: " << v1.size() << endl;

    cout << "*****************************" << endl;
    cout << "Popping 4 elements off ...\n";
    v1.pop_back();
    v1.pop_back();
    v1.pop_back();
    v1.pop_back();

    cout << "Capacity: " << v1.capacity() << endl;
    cout << "Size: " << v1.size() << endl;

    cout << "*****************************" << endl;
    cout << "Shrinking vector size to fit ...\n";
    v1.shrink_to_fit();

    cout << "Capacity: " << v1.capacity() << endl;
    cout << "Size: " << v1.size() << endl;

    return 0;
}

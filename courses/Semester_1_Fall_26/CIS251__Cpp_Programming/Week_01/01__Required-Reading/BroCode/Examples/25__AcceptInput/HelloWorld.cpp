#include <iostream>

// cout << (insertion operator)
// cin >> (extraction operator)

/*
    - #GOTCHA:  To read in a string with spaces use std::getline()

    - #GOTCHA:  If we accept cin inbut followed by a getline it erroneously accepts the \n char still in the cin buffer. To prevent this, use `>> std::ws` in getline() like so:

        Example:

        std::getline(std::cin >> std::ws, name);
*/

int main()
{
    std::string name;
    int age;

    std::cout << "What5's your age?: ";
    std::cin >> age;

    std::cout << "What's your full name? ";
    std::getline(std::cin >> std::ws, name);

    std::cout << "Hello " << name << '\n';
    std::cout << "You are " << age << " years old";

    return 0;
}
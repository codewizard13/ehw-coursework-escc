// Source: https://www.youtube.com/watch?v=S3nx34WFXjI&list=PLZPZq0r_RZOMHoXIcxze_lP97j2Ase2on
# include <iostream>

int main() {

    /*
        This is
        a multi-line
        comment
    */
    
    // Add a newline with endl
    std::cout << "I like pizza!" << std::endl;

    // Add a newline with newline char; better performance, but doesn't flush output buffer
    std::cout << "I like pizza!" << '\n';

    std::cout << "It's really good!";
    return 0;
}
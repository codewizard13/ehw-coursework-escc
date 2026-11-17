#include <iostream>
#include <string>
#include <iomanip>

#include <vector>
#include <numeric>

// #include <ranges>
// #include <string_view>

using namespace std;

int main()
{

    // #GOTCHA: The only reason this prints with spaces is because spaces are manually included in some strings -- accumulate() doesn't have any built-in way to add a delimiter.
    vector<string> words = {"Winter ", "is ", "Coming."};
    string sentence = accumulate(begin(words), end(words), string(""));

    cout << sentence << endl;

    return 0;
}

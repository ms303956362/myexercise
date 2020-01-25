#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <vector>
using std::vector;

#include <list>
using std::list;

#include <algorithm>
using std::count;

#include <string>
using std::string;

int main(int argc, char const *argv[])
{
    // 10.1
    vector<int> iv{0, 1, 2, 2, 3, 4, 5};
    cout << count(iv.begin(), iv.end(), 2) << endl;

    // 10.2
    list<string> sl{"abc", "def", "ghi", "def"};
    cout << count(sl.begin(), sl.end(), "def");

    return 0;
}

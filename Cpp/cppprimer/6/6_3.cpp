#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

bool str_subrange(const string &s1, const string &s2){
    if (s1.size() == s2.size())
        return s1 == s2;
    auto size = s1.size() < s2.size() ? s1.size() : s2.size();
    for (decltype(size) i = 0; i != size; ++i){
        if (s1[i] != s2[i])
            return false;
    }
    return true;
}

void print_vector(vector<int>::iterator beg, vector<int>::iterator end){
    if (beg == end){
        cout << endl;
        return;
    }
    cout << *beg << " ";
    print_vector(++beg, end);
}

int main(int argc, char const *argv[])
{
    // 6.30
    // cout << str_subrange("abc", "abcde") << endl;

    // 6.33
    vector<int> v(10, 3);
    print_vector(v.begin(), v.end());

    return 0;
}

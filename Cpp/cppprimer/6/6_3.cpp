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

void print_vector_debug(vector<int>::iterator beg, vector<int>::iterator end){
    if (beg == end){
        cout << endl;
        return;
    }
    #ifndef NDEBUG
    cout << "Time: " << __DATE__ << " at " << __TIME__ << " Size: " << end - beg << " Item: ";
    #endif
    cout << *beg << endl;
    print_vector_debug(++beg, end);
}

constexpr int twice(int i){
    return 2 * i;
}

int add(int i1, int i2){
    return i1 + i2;
}

int sub(int i1, int i2){
    return i1 - i2;
}

int mult(int i1, int i2){
    return i1 * i2;
}

int divd(int i1, int i2){
    return i1 / i2;
}

int main(int argc, char const *argv[])
{
    // 6.30
    // cout << str_subrange("abc", "abcde") << endl;

    // 6.33
    // vector<int> v(10, 3);
    // print_vector(v.begin(), v.end());

    // 6.46
    // int i = 3;
    // cout << twice(i) << endl;

    // 6.47
    // vector<int> v{5, 4, 3, 2, 1, 0};
    // print_vector_debug(v.begin(), v.end());

    // 6.55
    vector<int (*)(int, int)> vf{add, sub, mult, divd};

    // 6.56
    int i1 = 6, i2 = 3;
    for (auto f : vf)
        cout << f(i1, i2) << endl;

    return 0;
}

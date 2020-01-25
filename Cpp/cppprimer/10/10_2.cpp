#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <string>
using std::string;

#include <vector>
using std::vector;

#include <list>
using std::list;

#include <algorithm>
using std::equal;

#include <numeric>
using std::accumulate;
using std::fill_n;

#include <iterator>
using std::back_inserter;

#include <sstream>
using std::stringstream;

int main(int argc, char const *argv[])
{
    // 10.3
    // vector<int> iv{0, 1, 2, 3, 4, 5}, iv2 = iv;
    // int sum = accumulate(iv.cbegin(), iv.cend(), 0);
    // cout << sum << endl;
    // iv2.push_back(6);
    // cout << equal(iv.cbegin(), iv.cend(), iv2.cbegin()) << endl;

    // 10.4
    // vector<double> dv{0.1, 1.2, 2.3};
    // double sum = accumulate(dv.cbegin(), dv.cend(), 0);
    // cout << sum << endl;

    // 10.5
    // char s1[6] = "abcde", s2[6] = "abcde";
    // vector<char *> roster2{s1};
    // list<char *> roster1{s2};
    // cout << equal(roster1.cbegin(), roster1.cend(), roster2.cbegin()) << endl;

    // 10.6
    // int a[5] = {1, 2, 3, 4, 5};
    // fill_n(std::begin(a), sizeof(a)/sizeof(*a), 0);
    // for (auto i : a)
    //     cout << i << " ";
    // cout << endl;

    // 10.7a
    // vector<int> vec;
    // list<int> lst{1, 2, 3, 4, 5};
    // std::copy(lst.cbegin(), lst.cend(), back_inserter(vec));
    // for (auto i: lst)
    //     cout << i << " ";
    // cout << endl;

    // 10.7b
    // vector<int> vec;
    // vec.resize(10);
    // fill_n(vec.begin(), 10, 0);
    // for (auto i: vec)
    //     cout << i << " ";
    // cout << endl;

    // 10.9
    stringstream ss("the quick red fox jumps over the red turtle");
    vector<string> sv;
    string s;
    while (ss >> s){
        sv.push_back(s);
        cout << s << " ";
    }
    cout << endl;
    std::sort(sv.begin(), sv.end());
    for (auto w : sv){
        cout << w << " ";
    }
    cout << endl;
    auto endu = std::unique(sv.begin(), sv.end());
    for (auto w : sv){
        cout << w << " ";
    }
    cout << endl;
    sv.erase(endu, sv.end());
    for (auto w : sv){
        cout << w << " ";
    }
    cout << endl;
    
    return 0;
}

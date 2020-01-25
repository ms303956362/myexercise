#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <string>
using std::string;

#include <vector>
using std::vector;

#include <algorithm>
using std::count_if;
using std::find_if;
using std::partition;
using std::sort;
using std::stable_sort;
using std::unique;

#include <iterator>
using std::back_inserter;

#include <sstream>
using std::stringstream;

#include "my_Sales_data.h"

void elimDups(vector<string> &words){
    sort(words.begin(), words.end());
    auto end_unique = unique(words.begin(), words.end());
    words.erase(end_unique, words.end());
}

bool compareIsbn(Sales_data& sd1, Sales_data& sd2){
    return sd1.isbn() < sd2.isbn();
}

bool isShorter(const string& s1, const string& s2){
    return s1.size() < s2.size();
}

bool isLongerThan5(const string& s){
    return s.size() >= 5;
}

void biggies(vector<string> &words, vector<string>::size_type sz){
    elimDups(words);
    stable_sort(words.begin(), words.end(), isShorter);
    auto wc = find_if(words.begin(), words.end(), [sz](const string &word) { return word.size() > sz; });
    auto count = words.end() - wc;
    cout << count << " words are longer than " << sz << ": ";
    for (auto iter = wc; iter != words.end(); ++iter){
        cout << *iter << " ";
    }
    cout << endl;
}

void biggies2(vector<string> &words, vector<string>::size_type sz){
    elimDups(words);
    auto wc = stable_partition(words.begin(), words.end(), [sz](const string &word) { return word.size() <= sz; });
    auto count = words.end() - wc;
    cout << count << " words are longer than " << sz << ": ";
    for (auto iter = wc; iter != words.end(); ++iter){
        cout << *iter << " ";
    }
    cout << endl;
}

int main(int argc, char const *argv[])
{
    // 10.11
    // stringstream ss("the quick red fox jumps over the red turtle");
    // vector<string> sv;
    // string s;
    // while (ss >> s){
    //     sv.push_back(s);
    //     cout << s << " ";
    // }
    // cout << endl;
    // elimDups(sv);
    // stable_sort(sv.begin(), sv.end(), isShorter);
    // for (const auto &w : sv)
    // {
    //     cout << w << " ";
    // }
    // cout << endl;

    // 10.12
    // Sales_data sd1("abc"), sd2("def"), sd3("acd");
    // vector<Sales_data> sdv{sd1, sd2, sd3};
    // sort(sdv.begin(), sdv.end(), compareIsbn);
    // for (auto& sd: sdv){
    //     print(cout, sd) << endl;
    // }

    // 10.13
    // stringstream ss("the quick red fox jumps over the red turtle");
    // vector<string> words;
    // string s;
    // while (ss >> s)
    //     words.push_back(s);
    // auto end_long = partition(words.begin(), words.end(), isLongerThan5);
    // for (auto iter = words.cbegin(); iter != end_long; ++iter){
    //     cout << *iter << " ";
    // }
    // cout << endl;

    // 10.14
    // cout << [](int i1, int i2) { return i1 + i2; }(1,2) << endl;

    // 10.15
    // int i1 = 1;
    // cout << [i1](int i2) { return i1 + i2; }(2) << endl;

    // 10.16
    // stringstream ss("the quick red fox jumps over the red turtle");
    // vector<string> words;
    // string s;
    // while (ss >> s)
    //     words.push_back(s);
    // biggies(words, 2);

    // 10.17
    // Sales_data sd1("def"), sd2("abc"), sd3("acd");
    // vector<Sales_data> sdv{sd1, sd2, sd3};
    // sort(sdv.begin(), sdv.end(), [](Sales_data &sdl, Sales_data &sdr) { return sdl.isbn() < sdr.isbn(); });
    // for (auto& sd: sdv){
    //     print(cout, sd) << endl;
    // }

    // 10.18
    // stringstream ss("the quick red fox jumps over the red turtle");
    // vector<string> words;
    // string s;
    // while (ss >> s)
    //     words.push_back(s);
    // biggies2(words, 5);

    // 10.20
    // stringstream ss("the quick red fox jumps over the red turtles");
    // vector<string> words;
    // string s;
    // while (ss >> s)
    //     words.push_back(s);
    // auto cnt = count_if(words.begin(), words.end(), [](const string &s) { return s.size() > 6; });
    // cout << cnt << endl;

    // 10.21
    int i = 6;
    auto f = [&i]() -> bool {
        if (i > 0)
            --i;
        return i == 0;
    };
    for (int j = 0; j != 7;++j){
        bool flag = f();
        cout << i << " is 0: ";
        cout << (flag ? "true" : "false") << endl;
    }

    return 0;
}

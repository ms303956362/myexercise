#include <iostream>
using std::begin;
using std::cin;
using std::cout;
using std::end;
using std::endl;

#include <string>
using std::string;

#include <deque>
using std::deque;

#include <list>
using std::list;

#include <forward_list>
using std::forward_list;

#include <vector>
using std::vector;

forward_list<string>& find_and_insert(forward_list<string>& sfl, const string& s1, const string& s2){
    bool found = false;
    auto prev = sfl.before_begin();
    for (auto iter = sfl.begin(); iter != sfl.end(); ++prev, ++iter){
        if (*iter == s1){
            found = true;
            iter = sfl.emplace_after(iter, s2);
        }
    }
    if (!found){
        sfl.emplace_after(prev, s2);
    }
    return sfl;
}

int main(int argc, char const *argv[])
{
    // 9.18
    // string s;
    // deque<string> sdq;
    // while (cin >> s)
    //     sdq.push_back(s);
    // for (auto p = sdq.begin(); p != sdq.end(); ++p)
    // {
    //     cout << *p << " ";
    // }
    // cout << endl;

    // 9.19
    // list<string> sl;
    // string s;
    // while (cin >> s)
    //     sl.push_back(s);
    // for (auto p = sl.begin(); p != sl.end(); ++p)
    // {
    //     cout << *p << " ";
    // }
    // cout << endl;

    // 9.20
    // list<int> il;
    // deque<int> eq, oq;
    // for (int i; cin >> i; il.push_back(i))
    //     ;
    // for (auto i : il){
    //     if (i % 2 == 0)
    //         eq.push_back(i);
    //     else
    //         oq.push_back(i);
    // }
    // cout << "even numbers: ";
    // for (auto i : eq)
    //     cout << i << " ";
    // cout << endl;
    // cout << "odd numbers: ";
    // for (auto i : oq)
    //     cout << i << " ";
    // cout << endl;

    // 9.22
    // int same_val = -1;
    // vector<int> iv{1, -1, 2, -2, 3, -3};
    // vector<int>::size_type d = iv.size() / 2;
    // vector<int>::iterator iter = iv.begin(), mid = iv.begin() + d;
    // while (iter != mid){
    //     if (*iter == same_val){
    //         iter = iv.insert(iter, 2 * same_val);
    //         ++iter;
    //         mid = iv.begin() + ++d;
    //     }
    //     ++iter;
    // }

    // 9.24
    // vector<int> iv = {1, 2, 3};
    // cout << "at: " << iv.at(0) << endl;
    // cout << "index: " << iv[0] << endl;
    // cout << "front: " << iv.front() << endl;
    // cout << "begin: " << *iv.begin() << endl;

    // 9.25
    // int ia[] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89};
    // vector<int> iv(begin(ia), end(ia));
    // list<int> il(begin(ia), end(ia));
    // for (auto iter = iv.begin(); iter != iv.end(); ){
    //     if (*iter % 2 == 0)
    //         iter = iv.erase(iter);
    //     else
    //         ++iter;
    // }
    // for (auto iter = il.begin(); iter != il.end(); ){
    //     if (*iter % 2 != 0)
    //         iter = il.erase(iter);
    //     else
    //         ++iter;
    // }
    // cout << "vector: ";
    // for (const auto& i:iv)
    //     cout << i << " ";
    // cout << endl;
    // cout << "list: ";
    // for (const auto& i:il)
    //     cout << i << " ";
    // cout << endl;

    // 9.27
    // forward_list<int> ifl{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    // cout << "before deleting odd numbers: " << endl;
    // for (auto i : ifl){
    //     cout << i << " ";
    // }
    // cout << endl;
    // auto prev = ifl.before_begin();
    // auto curr = ifl.begin();
    // while (curr != ifl.end()){
    //     if (*curr % 2 == 0){
    //         prev = curr;
    //         ++curr;
    //     } else {
    //         cout <<  "found odd number: " << *curr <<endl;
    //         curr = ifl.erase_after(prev);
    //     }
    // }
    // cout << "after deleting odd numbers: " << endl;
    // for (auto i : ifl){
    //     cout << i << " ";
    // }
    // cout << endl;

    // 9.28
    // forward_list<string> sfl = {"abc", "def", "ghi", "caoni", "ma"};
    // find_and_insert(sfl, "gh", "hhh");
    // for (auto s : sfl){
    //     cout << s << " ";
    // }
    // cout << endl;

    // 9.31
    list<int> il{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    auto iter = il.begin();
    while (iter != il.end()){
        if (*iter % 2){
            iter = il.insert(iter, *iter);
            ++iter;
            ++iter;
        } else {
            iter = il.erase(iter);
        }
    }
    cout << "use list: " << endl;
    for (auto i : il){
        cout << i << " ";
    }
    cout << endl;

        forward_list<int> ifl{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    auto iter = ifl.begin(), prev = ifl.before_begin();
    while (iter != ifl.end()){
        if (*iter % 2){
            iter = ifl.insert_after(iter, *iter);
            prev = iter;
            ++iter;
        } else {
            iter = ifl.erase_after(prev);
        }
    }
    cout << "use foward_list: " << endl;
    for (auto i : ifl){
        cout << i << " ";
    }
    cout << endl;
    return 0;
 }
 
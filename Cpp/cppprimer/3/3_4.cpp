#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main(int argc, char const *argv[])
{
    // 3.21
    // vector<string> v = {10, "hi"};
    // cout << v.size() << endl;
    // for (auto it = v.begin(); it != v.end(); ++it){
    //     cout << *it << " ";
    // }
    // cout << endl;

    // 3.22
    // vector<string> text;
    // string s;
    // while (getline(cin, s))
    //     text.push_back(s);
    // for (auto it = text.begin(); it != text.end() && !it->empty(); ++it){
    //     for (auto cit = it->begin();cit!=it->end(); ++cit)
    //         *cit = toupper(*cit);
    // }
    // for (auto str : text)
    //     cout << str << endl;

    // 3.23
    // vector<int> v(10, 3);
    // for (auto it = v.begin(); it != v.end(); ++it)
    //     *it = 2 * (*it);
    // for (auto i : v)
    //     cout << i << " ";
    // cout << endl;

    // 3.24
    vector<int> v;
    int num;
    while (cin >> num)
        v.push_back(num);
    if (v.size() >=2){
        for (auto it = v.begin(); it != v.end() - 1; ++it)
            cout << *it + *(it+1) << " ";
        cout << endl;
        for (auto b = v.begin(), e = v.end() - 1; b <= e; ++b, --e)
            cout << *b + *e << " ";
        cout << endl;
    }

    // 3.25
    // vector<int> scores(11, 0);
    // unsigned int grade;
    // while (cin >> grade){
    //     if (grade <= 100)
    //         ++(*(scores.begin() + grade / 10));
    // }
    // for (auto score : scores)
    //     cout << score << " ";
    // cout << endl;

    return 0;
}

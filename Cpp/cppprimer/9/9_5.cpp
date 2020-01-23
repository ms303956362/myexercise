#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <string>
using std::string;

#include <vector>
using std::vector;

string& find_and_replace(string& s, const string& oldVal, const string& newVal){
    for (auto iter = s.begin(); std::distance(iter, s.end()) >= std::distance(oldVal.begin(), oldVal.end()); ++iter){
        if (string(iter, iter + oldVal.size()) == oldVal)
        {
            iter = s.erase(iter, iter + oldVal.size());
            iter = s.insert(iter, newVal.begin(), newVal.end());
            iter += newVal.size() - 1;
        }
    }
    return s;
}

string& find_and_replace2(string& s, const string& oldVal, const string& newVal){
    string::size_type pos = 0;
    while ((pos = s.find(oldVal, pos)) != string::npos)
    {
        s.replace(pos, oldVal.size(), newVal);
        pos += newVal.size();
    }
    return s;
}

int main(int argc, char const *argv[])
{
    // 9.41
    // vector<char> cv{'H', 'e', 'l', 'l', 'o'};
    // const size_t n = cv.size();
    // char cp[n];
    // for (size_t i=0;i!=n;++i){
    //     cp[i] = cv[i];
    // }
    // string s(cp, n);
    // cout << s << endl;

    // 9.43
    // string s("abc thodeftho");
    // cout << find_and_replace(s, "tho", "though") << endl;

    // 9.44
    // string s("abcthodefthoghi");
    // cout << find_and_replace2(s, "tho", "though") << endl;

    return 0;
}

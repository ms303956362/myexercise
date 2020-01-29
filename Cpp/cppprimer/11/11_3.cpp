#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::getline;

#include <sstream>
using std::istringstream;

#include <fstream>
using std::ifstream;

#include <vector>
using std::vector;

#include <string>
using std::string;

#include <map>
using std::map;
using std::multimap;

#include <utility>
using std::pair;

const string& trans(const string& s, map<string, string>& m){
    auto it = m.find(s);
    if (it != m.end())
        return it->second;
    else
        return s;
}

map<string, string> createMap(ifstream& ifs){
    map<string, string> m;
    string line;
    while (getline(ifs, line)){
        auto pos = line.find(" ");
        if (pos != string::npos)
            m.insert({string(line.begin(), line.begin()+pos), string(line.begin()+pos+1, line.end())});
    }
    return m;
}

void word_trans(ifstream& map_file, ifstream& input){
    auto map = createMap(map_file);
    string line;
    while (getline(input, line)){
        istringstream iss(line);
        string s;
        while (iss >> s){
            cout << trans(s, map) << " ";
        }
        cout << endl;
    }
}

int main(int argc, char const *argv[])
{
    // 11.20
    // map<string, size_t> word_count;
    // string word;
    // while (cin >> word){
    //     auto ret = word_count.insert({word, 1});
    //     if (!ret.second)
    //         ++ret.first->second;
    // }
    // for (auto &p:word_count){
    //     cout << p.first << " occurs " << p.second << (p.second > 1 ? " times" : " time") << endl;
    // }

    // 11.23
    // multimap<string, string> mmp;
    // string fn, ln;
    // while (cin >> fn >>ln){
    //     mmp.insert({fn, ln});
    // }
    // for (const auto &p:mmp){
    //     cout << p.first << " " << p.second << endl;
    // }

    // 11.26
    // map<string, int> m;
    // string s = "a";
    // int i;
    // i = m[s];
    // auto iter = m.begin();
    // cout << s << ": " << i << endl;
    // cout << iter->first << ": " << iter->second << endl;

    // 11.31
    // multimap<string, string> books;
    // books.insert({"Jiang", "tagaibianlezhongguo"});
    // books.insert({"Jiang", "hasanpian"});
    // books.insert({"Wang", "hanpi"});
    // books.insert({"Cao", "nima"});
    // for (auto iter = books.find("Jiang"); iter != books.end() && iter->first == "Jiang"; ++iter)
    // {
    //     if (iter->second == "hasanpian"){
    //         books.erase(iter);
    //         break;
    //     }
    // }
    // for (const auto &p : books)
    // {
    //     cout << p.first << ": " << p.second << endl;
    // }

    // 11.32
    // multimap<string, string> books;
    // books.insert({"Jiang", "tagaibianlezhongguo"});
    // books.insert({"Jiang", "hasanpian"});
    // books.insert({"Wang", "hanpi"});
    // books.insert({"Cao", "nima"});
    // for (const auto &p : books)
    // {
    //     cout << p.first << ": " << p.second << endl;
    // }

    // 11.33
    ifstream map("data/rules"), input("data/text");
    word_trans(map, input);

    return 0;
}

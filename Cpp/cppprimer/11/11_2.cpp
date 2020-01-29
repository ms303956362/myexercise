#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::ostream;

#include <algorithm>
using std::find;

#include <vector>
using std::vector;

#include <string>
using std::string;

#include <fstream>
using std::ifstream;

#include <map>
using std::map;

#include <set>
using std::set;

#include <list>
using std::list;

#include <utility>
using std::pair;

#include "Sales_data.h"

class Family_kids{
    friend ostream &print_familys(Family_kids& fmlys, ostream &os);

public:
    Family_kids() = default;
    map<string, vector<string>> &add_family(const string &family_name);
    map<string, vector<string>> &add_family_kid(const string &family_name, const string& kid_name);

private:
    map<string, vector<string>> map_names;
};

map<string, vector<string>> &Family_kids::add_family(const string &family_name){
    map_names[family_name] = vector<string>();
    return map_names;
}

map<string, vector<string>> &Family_kids::add_family_kid(const string &family_name, const string& kid_name){
    map_names[family_name].push_back(kid_name);
    return map_names;
}

ostream &print_familys(Family_kids &fmlys, ostream &os = cout)
{
    for (const auto &f : fmlys.map_names)
    {
        os << "The last name of famliy: " << f.first << endl;
        for (auto iter = f.second.begin(); iter != f.second.end(); ++iter){
            os << "Kid" << iter - f.second.begin() + 1 << "'s name: " << f.first <<" "<< *iter << endl;
        }
    }
    return os;
}

int main(int argc, char const *argv[])
{
    // 11.7
    // Family_kids fmlys;
    // fmlys.add_family("Jiang");
    // fmlys.add_family_kid("Jiang", "Niubi");
    // fmlys.add_family_kid("Jiang", "Dadiao");
    // fmlys.add_family("Wang");
    // fmlys.add_family_kid("Wang", "Keai");
    // fmlys.add_family_kid("Yang", "Dalao");
    // print_familys(fmlys);

    // 11.8
    // vector<string> words_set;
    // string s;
    // while (cin >> s){
    //     if (find(words_set.begin(), words_set.end(), s) == words_set.end())
    //         words_set.push_back(s);
    // }
    // for(const auto& s: words_set){
    //     cout << s << " ";
    // }
    // cout << endl;

    // 11.10
    // map<vector<int>::iterator, int> m1;
    // map<list<int>::iterator, int> m2;

    // 11.11
    // std::multiset<Sales_data, bool (*)(const Sales_data &, const Sales_data &)> bookstore(compareIsbn);

    // 11.12
    // vector<string> sv{"abd", "def", "ghi"};
    // vector<int> iv{1, 2, 3};
    // vector<pair<string, int>> pv;
    // auto it_s = sv.begin();
    // auto it_i = iv.begin();
    // while (it_s != sv.end() && it_i != iv.end())
    // {
    //     //pv.push_back({*it_s, *it_i});
    //     //pv.push_back(pair<string, int>(*it_s, *it_i));
    //     pv.push_back(std::make_pair(*it_s, *it_i));
    //     ++it_s;
    //     ++it_i;
    // }
    // for (const auto &p : pv)
    // {
    //     cout << p.first << ": " << p.second << endl;
    // }

    // 11.14
    map<string, vector<pair<string, string>>> fmly_map;
    fmly_map["Jiang"] = vector<pair<string, string>>{{"Niubi", "20200127"}, {"Dadiao", "20200128"}};
    fmly_map["Wang"] = vector<pair<string, string>>{{"keai", "20200129"}};
    for (const auto &f : fmly_map)
    {
        cout << "The last name of famliy: " << f.first << endl;
        for (auto iter = f.second.begin(); iter != f.second.end(); ++iter){
            cout << "Kid" << iter - f.second.begin() + 1 << "'s name: " << f.first <<" "<< iter->first
             << " birthday: "<< iter->second << endl;
        }
    }

    return 0;
}

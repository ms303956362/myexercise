#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <string>
using std::string;

#include <fstream>
using std::ifstream;

#include <map>
using std::map;

#include <set>
using std::set;

#include <algorithm>
using std::remove_if;

#include "make_plural.h"

int main(int argc, char const *argv[])
{
    // 11.3
    // ifstream ifs("data/word_count");
    // string word;
    // map<string, size_t> words_conut;
    // while (ifs >> word){
    //     ++words_conut[word];
    // }
    // for (const auto& w:words_conut){
    //     cout << w.first << " occurs " << w.second << (w.second > 1 ? " time" : " times") << endl;
    // }

    // 11.4
    ifstream ifs("data/word_count");
    string word;
    map<string, size_t> words_conut;
    while (ifs >> word){
        // remove_if将满足条件的元素移至末尾，erase将末尾标点符号删除
        word.erase(remove_if(word.begin(), word.end(), ispunct), word.end());
        for (auto &ch : word)
            ch = tolower(ch);
        ++words_conut[word];
    }
    for (const auto& w:words_conut){
        cout << w.first << " occurs " << w.second << (w.second > 1 ? " time" : " times") << endl;
    }

    return 0;
}

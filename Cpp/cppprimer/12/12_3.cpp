#include <iostream>
using std::cin;
using std::cout;
using std::endl;

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

#include <set>
using std::set;

#include <algorithm>
using std::for_each;
using std::remove_if;

#include "MyTextQuery.h"

void runQueries(ifstream& infile){
    MyTextQuery tq(infile);
    while (true){
        cout << "enter word to look for, or q to quit: ";
        string s;
        if (!(cin >> s) || s=="q")
            break;
        print(cout, tq.query(s));
    }
}

void runQueries_directly(ifstream& infile){
    vector<string> text;
    map<string, set<size_t>> word2line;
    string line;
    size_t line_num = 0;
    while (getline(infile, line)){
        text.push_back(line);
        istringstream iss(line);
        string word;
        while (iss >> word){
            word.erase(remove_if(word.begin(), word.end(), ispunct), word.end());
            for_each(word.begin(), word.end(), [](char& ch) { ch = tolower(ch); });
            word2line[word].insert(line_num);
        }
        ++line_num;
    }
    while (true){
        cout << "enter word to look for, or q to quit: ";
        string s, s_show;
        if (!(cin >> s) || s=="q")
            break;
        s_show = s;
        for_each(s.begin(), s.end(), [](char& ch) { ch = tolower(ch); });
        if (word2line.find(s) == word2line.end())
            cout << s_show << " is not found" << endl;
        else{
            auto lines = word2line[s];
            cout << s_show << " occurs " << lines.size() << (lines.size() > 1 ? " times" : " time") << endl;
            for (auto line_num : lines){
                cout << "\t(line " << line_num + 1 << ") " << text[line_num] << endl;
            }
        }
    }
}


int main(int argc, char const *argv[])
{
    // 12.27
    ifstream infile("data/storyDataFile");
    runQueries(infile);
    return 0;
}

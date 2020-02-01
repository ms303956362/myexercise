#ifndef _MY_TEXT_QUERY
#define _MY_TEXT_QUERY
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <memory>
#include <algorithm>
#include "my_StrBlob.h"
// using MyStrBlob = std::vector<std::string>;

class MyQueryResult;

class MyTextQuery{
public:
    using lines_ptr = std::shared_ptr<std::set<size_t>>;
    MyTextQuery() = default;
    MyTextQuery(std::ifstream &infile);
    MyQueryResult query(const std::string &word);

private:
    std::shared_ptr<MyStrBlob> ptr_text;
    std::map<std::string, lines_ptr>word_to_line_nums;
};

class MyQueryResult{
    friend MyTextQuery;
    friend std::ostream &print(std::ostream &os, const MyQueryResult &query_res);
public:
    MyQueryResult() = default;
    MyQueryResult(std::string w, std::shared_ptr<MyStrBlob> pt, std::shared_ptr<std::set<size_t>> pl) : word(w), ptr_text(pt), ptr_lines(pl){};
    std::shared_ptr<MyStrBlob> &get_file() { return ptr_text; }
    const std::shared_ptr<MyStrBlob> &get_file() const { return ptr_text; }
    std::set<size_t>::iterator begin() { return ptr_lines->begin(); }
    std::set<size_t>::const_iterator begin() const { return ptr_lines->begin(); }
    std::set<size_t>::iterator end() { return ptr_lines->end(); }
    std::set<size_t>::const_iterator end() const { return ptr_lines->end(); }

private:
    std::string word;
    std::shared_ptr<MyStrBlob> ptr_text;
    std::shared_ptr<std::set<size_t>> ptr_lines;
};

std::ostream &print(std::ostream &os, const MyQueryResult &query_res);

using std::cin;
using std::cout;
using std::endl;
using std::getline;
using std::ifstream;
using std::istringstream;
using std::make_shared;
using std::map;
using std::ostream;
using std::set;
using std::shared_ptr;
using std::string;
using std::vector;

MyTextQuery::MyTextQuery(ifstream &infile){
    size_t line_num = 0;
    string line;
    ptr_text = make_shared<MyStrBlob>();
    while (getline(infile, line)){
        ptr_text->push_back(line);
        istringstream iss(line);
        string word;
        while (iss >> word){
            word.erase(remove_if(word.begin(), word.end(), ispunct), word.end());
            for_each(word.begin(), word.end(), [](char& ch) { ch = tolower(ch); });
            if (word_to_line_nums.find(word) == word_to_line_nums.end())
                word_to_line_nums.emplace(word, make_shared<set<size_t>>());
            word_to_line_nums[word]->insert(line_num);
        }
        ++line_num;
    }
}

MyQueryResult MyTextQuery::query(const std::string &word){
    string word_key = word;
    for_each(word_key.begin(), word_key.end(), [](char& ch) { ch = tolower(ch); });
    if (word_to_line_nums.find(word_key) != word_to_line_nums.end())
        return MyQueryResult(word, ptr_text, word_to_line_nums[word_key]);
    else
        return MyQueryResult(word, ptr_text, make_shared<set<size_t>>());
}

ostream &print(ostream &os, const MyQueryResult &query_res){
    if (query_res.ptr_lines->size() == 0)
        os << query_res.word << " is not found" << endl;
    else{
        os << query_res.word << " occurs " << query_res.ptr_lines->size() 
        << (query_res.ptr_lines->size() > 1 ? " times" : " time") << endl;
        for (auto line_num : *query_res.ptr_lines){
            os << "\t(line " << line_num + 1 << ") " << (*query_res.ptr_text).at(line_num) << endl;
        }
    }
    return os;
}
#endif

#include <sstream>
#include "MyTextQuery.h"
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
    ptr_text = make_shared<vector<string>>();
    while (getline(infile, line)){
        ptr_text->push_back(line);
        istringstream iss(line);
        string word;
        while (iss >> word){
            if (word_to_line_nums.find(word) == word_to_line_nums.end())
                word_to_line_nums.emplace(word, make_shared<set<size_t>>());
            word_to_line_nums[word]->insert(line_num);
        }
        ++line_num;
    }
}

MyQueryResult MyTextQuery::query(const std::string &word){
    MyQueryResult query_res;
    query_res.word = word;
    query_res.ptr_text = ptr_text;
    if (word_to_line_nums.find(word) != word_to_line_nums.end())
        query_res.ptr_lines = word_to_line_nums[word];
    else
        query_res.ptr_lines = make_shared<set<size_t>>();
    return query_res;
}

ostream &print(ostream &os, const MyQueryResult &query_res){
    if (query_res.ptr_lines->size() == 0)
        cout << query_res.word << " is not found" << endl;
    else{
        cout << query_res.word << " occurs " << query_res.ptr_lines->size() 
        << (query_res.ptr_lines->size() > 1 ? " times" : " time") << endl;
        for (auto line_num : *query_res.ptr_lines){
            cout << "\t(line " << line_num + 1 << ") " << (*query_res.ptr_text)[line_num] << endl;
        }
    }
    return os;
}

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <string>
using std::string;

#include <vector>
using std::vector;

#include <algorithm>
using std::sort;

#include "my_StrBlob.h"

class HasPtr_V{
private:
    std::string *ps;
    int i;

public:
    friend void swap(HasPtr_V &lhp, HasPtr_V &rhp);
    HasPtr_V(const std::string &s = std::string()) : ps(new std::string(s)), i(0){};
    HasPtr_V(const HasPtr_V &hp) : ps(new std::string(*hp.ps)), i(hp.i){};
    HasPtr_V &operator=(HasPtr_V rhp);
    bool operator<(const HasPtr_V &rhp) { return *this->ps < *rhp.ps; }
    ~HasPtr_V() { delete ps; }
    std::string &deref() { return *ps; }
};

HasPtr_V& HasPtr_V::operator=(HasPtr_V rhp) {
    swap(*this, rhp);
    return *this;
}

void swap(HasPtr_V &lhp, HasPtr_V &rhp){
    using std::swap;
    swap(lhp.ps, rhp.ps);
    swap(lhp.i, rhp.i);
    cout << "swap(HasPtr_P &lhp, HasPtr_P &rhp)" << endl;
}

class HasPtr_P{
public:
    HasPtr_P(const std::string &s = "") : ps(new std::string(s)), i(0), use(new std::size_t(1)){};
    HasPtr_P(const HasPtr_P &rhp) : ps(rhp.ps), i(rhp.i), use(rhp.use) { ++*use; }
    HasPtr_P &operator=(const HasPtr_P &rhp);
    ~HasPtr_P();
    std::string &deref() { return *ps; }

private:
    std::string *ps;
    int i;
    std::size_t *use;
};

HasPtr_P& HasPtr_P::operator=(const HasPtr_P &rhp){
    ++*rhp.use;
    // 析构左侧对象
    if (--*use == 0){
        delete ps;
        delete use;
    }
    // 拷贝右侧对象
    ps = rhp.ps;
    i = rhp.i;
    use = rhp.use;
    return *this;
}

HasPtr_P::~HasPtr_P(){
    if (--*use == 0){
        delete ps;
        delete use;
    }
}

class TreeNode
{
private:
    std::string value;
    int count;
    TreeNode *left;
    TreeNode *right;

public:
    TreeNode(std::string s="", int i=0, TreeNode* l=nullptr, TreeNode* r=nullptr): value(s), count(i), left(l), right(r){};
};

class BinStrTree
{
private:
    TreeNode *root;

public:
    BinStrTree(std::string s = "", int i = 0, TreeNode *l = nullptr, TreeNode *r = nullptr) : root(new TreeNode(s, i, l, r)){};
    BinStrTree(const BinStrTree &rbst) : root(rbst.root){};
    BinStrTree &operator=(const BinStrTree &rbst);
    ~BinStrTree();
};

BinStrTree& BinStrTree::operator=(const BinStrTree &rbst){
    auto new_root = rbst.root;
    delete root;
    root = new_root;
    return *this;
}

BinStrTree::~BinStrTree(){
    delete root;
}

int main(int argc, char const *argv[])
{
    // 13.22
    // HasPtr_V hp1("hello");
    // hp1 = hp1;

    // 13.26
    // MyStrBlob msb({"abc", "def", "ghi"});
    // MyStrBlob msb1 = msb, msb2;
    // msb2 = msb;
    // msb2.push_back("123");
    // for (auto iter = msb1.begin(); !equal(iter, msb1.end());iter.incr()){
    //     cout << iter.deref() << " ";
    // }
    // cout << endl;
    // for (auto iter = msb2.begin(); !equal(iter, msb2.end());iter.incr()){
    //     cout << iter.deref() << " ";
    // }
    // cout << endl;

    // 13.27
    // HasPtr_P hp1("j"), hp2(hp1), hp3("w");
    // cout << hp1.deref() << " ";
    // hp2 = hp3;
    // cout << hp2.deref() << " ";
    // hp3.deref() = "nb";
    // hp1 = hp3;
    // cout << hp1.deref() << endl;

    // 13.30
    // HasPtr_P hp1("hello"), hp2("world");
    // swap(hp1, hp2);
    // cout << hp2.deref() << " " << hp1.deref() << endl;

    // 13.31
    vector<HasPtr_V> vhp{HasPtr_V("abc"), HasPtr_V("def"), HasPtr_V("abe")};
    sort(vhp.begin(), vhp.end());
    for (auto iter = vhp.begin(); iter != vhp.end();++iter){
        cout << iter->deref() << " ";
    }
    cout << endl;

    return 0;
}

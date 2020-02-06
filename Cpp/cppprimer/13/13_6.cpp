#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <vector>
using std::vector;

#include <string>

#include <utility>

#include <algorithm>
using std::sort;

#include "my_StrVec.h"
#include "my_String.h"
#include "my_Folder.h"
#include "my_StrBlob.h"

class HasPtr{
private:
    std::string *ps;
    int i;

public:
    HasPtr(const std::string &s = std::string()) : ps(new std::string(s)), i(0){};
    HasPtr(const HasPtr &hp) : ps(new std::string(*hp.ps)), i(hp.i) { cout << "copy constructor" << endl; }
    HasPtr(HasPtr &&hp) noexcept;
    HasPtr &operator=(const HasPtr& rhp);
    HasPtr &operator=(HasPtr &&rhp) noexcept;
    // HasPtr &operator=(HasPtr rhp);
    void swap(HasPtr &lhp, HasPtr &rhp);
    ~HasPtr() { cout << "destructor" << endl; delete ps; }
};

class Foo{
private:
    vector<int> data;

public:
    Foo sorted() &&;
    Foo sorted() const &;
};

Foo Foo::sorted() && {
    sort(data.begin(), data.end());
    cout << "Foo Foo::sorted() &&" << endl;
    return *this;
}

Foo Foo::sorted() const &{
    // Foo ret(*this);
    // sort(ret.data.begin(), ret.data.end());
    cout << "Foo Foo::sorted() const &" << endl;
    return Foo(*this).sorted();
}

HasPtr::HasPtr(HasPtr &&hp) noexcept : ps(hp.ps), i(hp.i) {
    hp.ps = nullptr;
    cout << "move constructor" << endl;
}

HasPtr& HasPtr::operator=(const HasPtr& rhp) {
    auto newp = new std::string(*rhp.ps);
    delete ps;
    ps = newp;
    i = rhp.i;
    cout << "copy assignment" << endl;
    return *this;
}

HasPtr& HasPtr::operator=(HasPtr &&rhp) noexcept {
    if (this!=&rhp){
        delete ps;
        ps = rhp.ps;
        i = rhp.i;
        rhp.ps = nullptr;
    }
    cout << "move assignment" << endl;
    return *this;
}

// HasPtr& HasPtr::operator=(HasPtr rhp){
//     swap(*this, rhp);
//     cout << "copy and swap assignment" << endl;
//     return *this;
// }

void HasPtr::swap(HasPtr &lhp, HasPtr &rhp){
    std::swap(lhp.ps, rhp.ps);
    std::swap(lhp.i, rhp.i);
}

int main(int argc, char const *argv[])
{
    // 13.48
    // vector<my_String> sv;
    // sv.reserve(10);
    // sv.push_back("abc");
    // cout << endl;
    // sv.push_back("def");
    // cout << endl;
    // sv.push_back("ghi");

    // 13.49
    // my_String s1("abc");
    // my_String s2(s1);
    // my_String s3(std::move(s1)), s4, s5;
    // s4 = s2;
    // s5 = std::move(s3);

    // My_StrVec msv1{"abc", "def", "ghi"};
    // My_StrVec msv2(std::move(msv1));
    // My_StrVec msv3;
    // msv3 = std::move(msv2);

    // Folder f1;
    // Message m1("abc");
    // m1.save(f1);
    // Message m2(std::move(m1));
    // Message m3;
    // m3 = std::move(m2);

    // 13.53
    // HasPtr hp1("abc");
    // HasPtr hp2(std::move(hp1));
    // cout << endl;
    // HasPtr hp3;
    // hp3 = std::move(hp2);
    // cout << endl;

    // 13.55
    // MyStrBlob msb{"abc"};
    // string s("def");
    // msb.push_back(s);
    // msb.push_back("ghi");
    // for (auto iter = msb.begin(); !equal(iter, msb.end());iter.incr()){
    //     cout << iter.deref() << " ";
    // }
    // cout << endl;

    // 13.58
    Foo f1;
    std::move(f1).sorted();
    f1.sorted();

    return 0;
}

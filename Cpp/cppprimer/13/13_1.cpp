#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <string>
using std::string;

#include <vector>
using std::vector;

class HasPtr{
private:
    std::string *ps;
    int i;

public:
    HasPtr(const std::string &s = std::string()) : ps(new std::string(s)), i(0){};
    HasPtr(const HasPtr &hp) : ps(new std::string(*hp.ps)), i(hp.i){};
    HasPtr &operator=(const HasPtr& rhp);
    ~HasPtr() { delete ps; }
};

HasPtr& HasPtr::operator=(const HasPtr& rhp) {
    auto newp = new std::string(*rhp.ps);
    delete ps;
    ps = newp;
    i = rhp.i;
    return *this;
}

struct X{
    X() { std::cout << "X()" << std::endl; }
    X(const X&) { std::cout << "X(const X&)" << std::endl; }
    X &operator=(const X& x) {
        std::cout << "X& operator=(X&)" << std::endl;
        return *this;
    }
    ~X() { std::cout << "~X()" << std::endl; }
};

X f(X& x){
    return x;
}

class numbered {
    friend void f(numbered s);

private:
    static size_t sn;
    size_t mysn;

public:
    numbered() = default;
    // numbered(const numbered &rn) : mysn(sn++){};
};

size_t numbered::sn = 0;

void f(numbered s) { cout << s.mysn << endl; }

class Employee{
public:
    Employee() = delete;
    Employee(const string &s) : name(s), id(id_gen++){};
    Employee(const Employee &) = delete;
    Employee &operator=(const Employee &) = delete;

private:
    static size_t id_gen;
    string name;
    size_t id;
};

size_t Employee::id_gen = 0;

int main(int argc, char const *argv[])
{
    // 13.5
    // HasPtr hp1("hello"), hp2 = hp1;

    // 13.8
    // HasPtr hp1("hello"), hp2;
    // hp2 = hp1;
    
    // 13.11
    // HasPtr hp("hello");
    
    // 13.13
    // cout << "direct and copy initlization" << endl;
    // X x1, x2(x1);
    // cout << "\ncopy assignment" << endl;
    // x2 = x1;
    // cout << "\nunref and ref parameter delivery" << endl;
    // x2 = f(x1);
    // cout << "\ndynamic allocation" << endl;
    // X *px1 = new X;
    // *px1 = x1;
    // cout << "\nuse vector<X>" << endl;
    // vector<X> xv;
    // xv.push_back(x1);
    // cout << "\ndestroy memory" << endl;
    // delete px1;
    
    // 13.17
    // numbered a;
    // numbered b = a;
    // numbered c = b;
    // f(a);
    // f(b);
    // f(c);

    // 13.18
    Employee e1("jw");

    return 0;
}

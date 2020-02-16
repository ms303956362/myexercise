#include <iostream>

class Base{
public:
    void pub_mem() { std::cout << "Base::pub_mem()" << std::endl; }
    void memfcn(Base &b) { b = *this; }
protected:
    int prot_mem;
private:
    char priv_mem;
};

struct Pub_Derv: public Base {
    void pub_mem() { std::cout << "Pub_Derv::pub_mem()" << std::endl; }
    int f() { return prot_mem; }
    void memfcn(Base &b) { b = *this; }
};

struct Priv_Derv: private Base {
    int f() { return prot_mem; }
    void memfcn(Base &b) { b = *this; }
};

struct Prot_Derv: protected Base {
    int f() { return prot_mem; }
    void memfcn(Base &b) { b = *this; }
};
struct Derived_from_Public: public Pub_Derv {
    int use_base() { return prot_mem; }
    void memfcn(Base &b) { b = *this; }
};

struct Derived_from_Private: public Priv_Derv {
    // void memfcn(Base &b) { b = *this; }
};

struct Derived_from_Protect: public Prot_Derv {
    int use_base() { return prot_mem; }
    void memfcn(Base &b) { b = *this; }
};

int main(int argc, char const *argv[])
{
    // Base *p = &Pub_Derv();   //OK
    // p = &Priv_Derv();
    // p = &Prot_Derv();
    // p = &Derived_from_Public();  //OK
    // p = &Derived_from_Private();
    // p = &Derived_from_Protect();
    Pub_Derv pd;
    Base *p = &pd;
    p->pub_mem();
    return 0;
}


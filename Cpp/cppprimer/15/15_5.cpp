class Base{
public:
    void pub_mem();
    void memfcn(Base &b) { b = *this; }
protected:
    int prot_mem;
private:
    char priv_mem;
};

struct Pub_Derv: public Base {
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
    Base *p = &Pub_Derv();
    // p = &Priv_Derv();
    // p = &Prot_Derv();
    p = &Derived_from_Public();
    // p = &Derived_from_Private();
    // p = &Derived_from_Protect();
    return 0;
}


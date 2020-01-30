#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::istream;
using std::ostream;

#include <vector>
using std::vector;

#include <memory>
using std::make_shared;
using std::shared_ptr;
using std::unique_ptr;

#include "my_StrBlob.h"

vector<int>* craete_vec(){
    return new vector<int>();
}

istream& read_vec(istream& is, vector<int>* piv){
    int i;
    while (is >> i){
        piv->push_back(i);
    }
    return is;
}

ostream& print_vec(ostream& os, vector<int>* piv){
    for (auto i:*piv){
        os << i << " ";
    }
    return os;
}

shared_ptr<vector<int>> create_vec_sp(){
    return make_shared<vector<int>>();
}

istream& read_vec(istream& is, shared_ptr<vector<int>> piv){
    int i;
    while (is >> i){
        piv->push_back(i);
    }
    return is;
}

ostream& print_vec(ostream& os, shared_ptr<vector<int>> piv){
    for (auto i:*piv){
        os << i << " ";
    }
    return os;
}

void process(shared_ptr<int> sp){
    cout << "process " << *sp << endl;
}

struct destination{
    int des;
};
struct connection{
    int a;
};
connection connect(destination *pd){
    connection c;
    c.a = pd->des;
    cout << "connected " << c.a << endl;
    return c;
}
void disconnect(connection c){
    cout << "disconnected " << c.a << endl;
}

void connection_end(connection* pc){
    disconnect(*pc);
}

void f(destination &d){
    connection c = connect(&d);
    shared_ptr<connection> pc(&c, [](connection *pc) { disconnect(*pc); });
    cout << "use connection " << c.a << endl;
}

int main(int argc, char const *argv[])
{
    // 12.2
    // MyStrBlob msb, msb1 = msb;
    // const MyStrBlob cmsb{1,2,3};
    // msb.push_back(1);
    // msb1.push_back(2);
    // cout << "msb size: " << msb.size() << ", msb last element: " << msb.back() << endl;
    // cout << "cmsb size: "<< cmsb.size() << ", cmsb first element: " << cmsb.front() << endl;

    // 12.6
    // vector<int> *piv = craete_vec();
    // read_vec(cin, piv);
    // print_vec(cout, piv) << endl;
    // delete piv;

    // 12.7
    // auto piv = create_vec_sp();
    // read_vec(cin, piv);
    // print_vec(cout, piv);

    // 12.11
    // shared_ptr<int> sp(new int(42));
    // process(shared_ptr<int>(sp));
    // *sp = 2;

    // 12.14
    // destination des;
    // f(des);

    // 12.16
    // unique_ptr<int> sp(new int(1));
    // unique_ptr<int> sp2 = sp;

    // 12.17
    int ix = 1024, *pi = &ix, *pi2 = new int(2048);
    typedef unique_ptr<int> IntP;
    IntP p2(pi2);
    IntP p5(p2.get());

    return 0;
}

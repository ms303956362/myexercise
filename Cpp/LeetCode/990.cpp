#include "usual.h"

class UnionFindSet {
public:
    UnionFindSet(const vector<char>& vc) {
        for (auto c : vc) {
            unordered_set<char> s;
            s.insert(c);
            uf.push_back(s);
        }
    }
    list<unordered_set<char>>::iterator find(char c) {
        auto p = uf.begin();
        while (p != uf.end()) {
            if (p->find(c) != p->end()) {
                return p;
            }
            ++p;
        }
        return uf.end();
    }

    void unionn(list<unordered_set<char>>::iterator p1, list<unordered_set<char>>::iterator p2) {
        auto p3 = (p1->size() < p2->size() ? p1 : p2), p4 = (p1->size() >= p2->size() ? p1 : p2);
        for (auto p = p3->begin(); p != p3->end(); ++p) {
            p4->insert(*p);
        }
        uf.erase(p3);
    }

    inline list<unordered_set<char>>::iterator end() { return uf.end(); }

private:
    list<unordered_set<char>> uf;
};

class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        vector<char> vc;
        for (auto& e : equations) {
            vc.push_back(e[0]);
            vc.push_back(e[3]);
        }
        vc.erase(unique(vc.begin(), vc.end()), vc.end());
        UnionFindSet uf(vc);
        for (auto &e : equations) {
            auto p1 = uf.find(e[0]), p2 = uf.find(e[3]);
            if (e[1] == '=' && p1 != p2)
                uf.unionn(p1, p2);
        }
        for (auto &e : equations) {
            auto p1 = uf.find(e[0]), p2 = uf.find(e[3]);
            if (e[1] == '!' && p1 == p2)
                return false;
        }
        return true;
    }
};

int main(int argc, char const *argv[])
{
    vector<string> v{"m!=f","g!=s","k==c","r!=c","l==d","x==b","e==p","s!=b","a==k","e!=g","t==n","j!=b","w==w","r!=b","w!=f","c!=g","q==a","f!=c","t!=v","i==f","o!=i","m==y","r==r","s!=i","u!=h","u!=w","i!=p","o!=x","r!=e","c!=f","v!=t","f!=h","w==w","e==p","j!=q","k!=s","s!=a","u!=s","w!=d","e!=s","t!=k","w!=u","p==e","x!=e","a!=n","v!=u","k!=l","j!=e","c!=g","p!=k","m!=s","v==v","t!=m","c==c","v!=l","y!=f","e==e","a!=j","u!=g","u!=s","r!=k","u!=m","o!=v","g!=o","w!=a","k!=u","e!=a","s!=k","c==k","g!=y","b!=n","a!=r","k!=n","y!=e","g!=j","l!=f","e!=t","v!=e","y!=r","c!=t","x!=o","r!=u","c!=l","c!=u","w!=r","g!=c","o!=p","r!=w","h!=v","k!=i","f!=a","l!=o","j!=r","g!=x","h!=b","o!=p","x!=v","l!=o","y!=i","v!=c","s!=p","t!=u","e!=y","b!=l","s!=r","r!=t","u!=d","s!=j","x!=p","y!=r","v!=i","d!=s","y!=j","w!=h","f!=s","q!=i","r!=h","w!=r","a!=e","c!=x","f!=s","c!=b","n!=w","b==x","k!=s","p!=m","x!=f","p!=a","x!=w","l!=f","u!=o","p!=w","s!=c","o!=y","w!=d","e!=x","f==f","u!=q","n!=h","a!=n","m==m","u!=q","c!=t","e!=j","a!=y","j!=k","h!=k","x!=n","t!=f","p!=i","b!=l","o==o","o!=k","j!=h","k!=v","b!=j","w!=r","l!=m","k!=d","a!=v","r!=v","g!=k","m!=x","s!=i","a!=v","n!=p","t!=d","j==j","p!=o","f==f","o!=a","m!=j","o!=h","i!=h","p!=c","h!=t","w!=b","d!=h","e!=c","i!=k","k!=d","r!=g","t!=o","v!=x","s!=d","t!=r","d==d","r!=d","p!=g","j!=e","b!=a","k!=d","l!=q","m!=h","l!=t","u!=q","w!=t","i!=v","r!=q","t!=q","f!=j","y!=f","u!=o","x!=s","s!=t","g!=b","d!=h","y!=e","p!=s","x!=n","f!=w","v!=w","g!=y","u!=j","r!=o","n!=s","h!=n","g!=q","x!=p","w!=a","w!=j","r==r","s!=u","x!=e","b!=k","j!=d","k!=e","q!=p","d!=k","r!=u","o!=w","j!=c","v!=u","r!=q","x!=d","p!=o","s!=q","s!=d","q!=g","i!=n","e!=u","i!=o","k!=s","c!=r","k!=t","x!=t","h!=r","f!=d","a!=m","l!=e","w!=f","j!=p","g!=v","l!=h","g!=q","s!=r","s!=t","g!=n","o!=n","j!=s","h!=v","a!=p","k!=y","g==g","a!=h","y==m","i!=n","x!=j","b!=f","w!=c","o!=y","e!=n","e!=v","o==o","e!=y","k!=t","m!=l","h!=r","j!=e","b!=w","s!=c","b!=f","v!=n","b!=m","p!=u","b!=u","u!=q","x!=l","g!=t","l!=u","a!=m","e!=g","t!=l","p!=y","v!=c","i!=q","o!=t","f!=m","a!=f","t!=y","h!=y","g!=y","i!=d","m!=t","j!=l","w!=o","u!=o","k!=j","v!=g","g!=c","o!=b","y!=c","i!=k","j!=i","n!=v","w!=n","c!=t","c!=i","p!=m","v!=t","e!=f","n!=o","l!=s","v!=h","q!=r","u!=s","g!=t","n!=r","v!=m","u!=i","n!=a","a!=d","m!=r","u!=d","d!=y","h!=u","e!=k","m==m","l!=p","x!=p","w==w","e!=c","a!=p","q!=b","s!=q","s!=p","c!=b","l!=c","b!=q","q!=t","r!=d","d!=j","o!=p","j!=b","b!=l","t==t","w!=h","e!=v","c!=y","c!=v","l!=x","g!=k","l!=u","u!=b","m!=p","t!=s","i!=v","k!=o","i!=m","f!=y","d!=n","v!=n","k!=r","p!=g","k!=t","n!=i","u!=f","q!=d","o!=m","c!=u","m!=r","w!=a","e!=i","n==n","l!=k","i!=j","k!=x","c!=n","t==n","h!=o","y!=n","g!=t","c==k","j!=o","i!=m","c!=y","v!=e","c!=j","g!=p","g!=i","o!=m","a!=i","n==n","f!=s","v!=w","w!=r","e!=u","w!=r","g==g","p!=c","d!=a","k!=y","c!=n","d==d","j!=u","y!=r","b!=c","i!=d","o!=u","n!=u","c!=x","e!=k","b!=k","k!=b","y!=r","j==j","e!=o","o!=h","w!=m","d==l","c!=h","p!=f","t!=o","f!=e","d==l","s!=u","s!=a","d!=y","x!=i","l!=r","n!=e","h!=c","a!=y","j!=c","h!=x","s!=t","u!=j","c!=e","e!=i","s!=n","i!=e","u!=k","n!=w","r!=c","v!=x","p!=m","n!=s","h!=p","n!=o","q!=v","b!=v","e!=d","n!=e","r!=n","o!=r","e!=m","s!=f","g!=y","r!=a","q!=j","e!=c","v!=p","t!=y","b!=v","e==e","t!=a","m!=r","q==q","k!=s","d!=k","e!=w","y!=t","t!=g","l!=t","e==e","g!=j","g!=v","p!=j","w!=b","i!=k","a==k","l!=h","y!=t","j!=r","g!=w","x!=l","i!=l","o!=n","o!=f","h==w"};
    cout << Solution().equationsPossible(v) << endl;
    return 0;
}

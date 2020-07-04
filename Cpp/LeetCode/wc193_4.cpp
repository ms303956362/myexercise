#include "usual.h"

class TreeAncestor {
public:
    TreeAncestor(int n, vector<int>& parent) : m(n), p(parent.begin(), parent.end()) {

    }
    
    int getKthAncestor(int node, int k) {
        int anc = node;
        for (int i = 0; i != k && anc != -1; anc = p[anc])
            ;
        return anc;
    }

private:
    int m;
    vector<int> p;
};
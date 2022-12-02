#include "usual.h"


struct Node {
    char val;
    Node *left;
    Node *right;
    Node() : val(' '), left(nullptr), right(nullptr) {}
    Node(char x) : val(x), left(nullptr), right(nullptr) {}
    Node(char x, Node *left, Node *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    Node* expTree(string s) {
        int n = s.size();
        stack<Node*> sn, sc;
        unordered_map<char, int> order{{'(', -1}, {'+', 0}, {'-', 0}, {'*', 1}, {'/', 1}};
        auto calc = [](stack<Node*>& sn, stack<Node*>& sc) {
            Node *res = sc.top();
            sc.pop();
            res->right = sn.top();
            sn.pop();
            res->left = sn.top();
            sn.pop();
            sn.push(res);
        };
        for (int i = 0; i < n; ++i) {
            if ('0' <= s[i] && s[i] <= '9') {
                sn.push(new Node(s[i]));
            } else if (s[i] == '(') {
                sc.push(new Node(s[i]));
            } else if (s[i] == ')') {
                while (sc.top()->val != '(') {
                    calc(sn, sc);
                }
                sc.pop();
            } else {
                while (!sc.empty() && order[s[i]] <= order[sc.top()->val]) {
                    calc(sn, sc);
                }
                sc.push(new Node(s[i]));
            }
        }
        while (!sc.empty()) {
            calc(sn, sc);
        }
        return sn.top();
    }
};


int main(int argc, char const *argv[])
{
    Solution().expTree("3*(9-6*5)");
    return 0;
}

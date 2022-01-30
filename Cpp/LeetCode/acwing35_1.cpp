// IO
#include <iostream>
#include <sstream>
// ordered container
#include <vector>
#include <deque>
#include <list>
#include <forward_list>
#include <string>
#include <stack>
#include <queue>
// associative-container
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
// algorithm
#include <algorithm>
#include <cmath>
// utility
#include <initializer_list>
#include <iterator>
#include <memory>
#include <utility>
// c
#include <cstdio>
#include <cstdlib>
#include <cstring>
// functional
#include <functional>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};



int main(int argc, char const *argv[])
{
    string a, b;
    cin >> a >> b;
    for (auto& c : a) {
        if ('A' <= c && c <= 'Z') {
            c = c - 'A' + 'a';
        }
    }
    for (auto& c : b) {
        if ('A' <= c && c <= 'Z') {
            c = c - 'A' + 'a';
        }
    }
    if (a > b) {
        cout << 1 << endl;
    } else if (a == b) {
        cout << 0 << endl;
    } else {
        cout << -1 << endl;
    }
    return 0;
}

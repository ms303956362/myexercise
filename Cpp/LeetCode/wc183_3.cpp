#include "usual.h"
// struct Node
// {
//     int cnt;
//     char ch;
//     Node(int i, char c) : cnt(i), ch(c) {}
// };

// bool operator<(const Node &n1, const Node &n2) { return n1.cnt < n2.cnt; }

// class Solution {
// public:
//     string longestDiverseString(int a, int b, int c) {
//         vector<Node> v;
//         v.push_back(Node(a, 'a'));
//         v.push_back(Node(b, 'b'));
//         v.push_back(Node(c, 'c'));
//         sort(v.begin(), v.end());
//         Node max_num = v[2], n1 = v[1], n2 = v[0];
//         string res;
//         while (n1.cnt != 0 || n2.cnt != 0) {
//             int cnt = 0;
//             while (max_num.cnt > 0 && cnt < 2) {
//                 res.push_back(max_num.ch);
//                 --max_num.cnt;
//                 ++cnt;
//             }
//             change(max_num, n1, n2);
//         }
//         int cnt = 0;
//         while (max_num.cnt > 0 && cnt < 2) {
//             res.push_back(max_num.ch);
//             --max_num.cnt;
//             ++cnt;
//         }
//         return res;
//     }

//     void change(Node &max_num, Node &n1, Node &n2) {
//         if (n2 < n1) {
//             Node tmp = n1;
//             n1 = max_num;
//             max_num = tmp;
//         } else {
//             Node tmp = n2;
//             n2 = max_num;
//             max_num = tmp;
//         }
//     }
// };

struct Node
{
    int cnt;
    string ch;
    Node(int i, string c) : cnt(i), ch(c) {}
};

bool operator<(const Node &n1, const Node &n2) { return n1.cnt < n2.cnt; }

unordered_map<Node, string> ans;

class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        vector<Node> v;
        v.push_back(Node(a, "a"));
        v.push_back(Node(b, "b"));
        v.push_back(Node(c, "c"));
        sort(v.begin(), v.end());
        Node max_num = v[2], n1 = v[1], n2 = v[0];
        return f(max_num, n1, n2);
    }

    string f(Node max_num, Node n1, Node n2) {
        if (n1.cnt == 0 && n2.cnt == 0) {
            int cnt = min(max_num.cnt, 2);
            string res;
            for (int i = 0; i < cnt; ++i) {
                res += max_num.ch;
            }
            return res;
        }
        if (max_num.cnt > 1) {
            Node max_num1 = max_num, n11 = n1, n21 = n2;
            Node max_num2 = max_num, n12 = n1, n22 = n2;

            string res1 = max_num1.ch;
            --max_num1.cnt;
            change(max_num1, n11, n21);
            res1 += f(max_num1, n11, n21);

            string res2 = max_num2.ch + max_num2.ch;
            max_num2.cnt -= 2;
            change(max_num2, n12, n22);
            res2 += f(max_num2, n12, n22);
            return res1.size() > res2.size() ? res1 : res2;
        } else {
            string res = max_num.ch;
            --max_num.cnt;
            change(max_num, n1, n2);
            res += f(max_num, n1, n2);
            return res;
        }
    }

    void change(Node &max_num, Node &n1, Node &n2) {
        if (n2 < n1) {
            Node tmp = n1;
            n1 = max_num;
            max_num = tmp;
        } else {
            Node tmp = n2;
            n2 = max_num;
            max_num = tmp;
        }
    }
};

int main(int argc, char const *argv[])
{
    cout << Solution().longestDiverseString(2, 2, 1) << endl;
    return 0;
}

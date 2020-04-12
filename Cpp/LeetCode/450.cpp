#include "usual.h"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 };

class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int val) {
        TreeNode* x = root, *p = nullptr;
        while (x) {
            if (x->val < val) {
                p = x;
                x = x->left;
            }
            else if (val <x->val) {
                p = x;
                x = x->right;
            }
            else
                break;
        }
        if (!x)
            return root;
        TreeNode* &p2x = (!p ? root :(x == p->left ? p->left : p->right));
        if (!x->left) { // 左子树为空，右子树替代（右子树空或不空都OK）
            p2x = x->right;
        } else if (!x->right) { // 左子树不为空，右子树为空
            p2x = x->left;
        } else { // 左右子树都不为空
            TreeNode* pw = x, *w = succ(x, pw);
            int tmp = w->val;
            w->val = w->val;
            x->val = tmp;
            TreeNode* &p2w = (w == pw->right ? pw->right : pw->left);
            p2w = w->right;
        }
        return root;
    }
    
    TreeNode* succ(TreeNode* x, TreeNode*& pw) { // x必须有右子树
        x = x->right;
        while (x->left) {
            pw = x;
            x = x->left;
        }
        return x;
    }
};

void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}

TreeNode* stringToTreeNode(string input) {
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    if (!input.size()) {
        return nullptr;
    }

    string item;
    stringstream ss;
    ss.str(input);

    getline(ss, item, ',');
    TreeNode* root = new TreeNode(stoi(item));
    queue<TreeNode*> nodeQueue;
    nodeQueue.push(root);

    while (true) {
        TreeNode* node = nodeQueue.front();
        nodeQueue.pop();

        if (!getline(ss, item, ',')) {
            break;
        }

        trimLeftTrailingSpaces(item);
        if (item != "null") {
            int leftNumber = stoi(item);
            node->left = new TreeNode(leftNumber);
            nodeQueue.push(node->left);
        }

        if (!getline(ss, item, ',')) {
            break;
        }

        trimLeftTrailingSpaces(item);
        if (item != "null") {
            int rightNumber = stoi(item);
            node->right = new TreeNode(rightNumber);
            nodeQueue.push(node->right);
        }
    }
    return root;
}

int stringToInteger(string input) {
    return stoi(input);
}

string treeNodeToString(TreeNode* root) {
    if (root == nullptr) {
      return "[]";
    }

    string output = "";
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()) {
        TreeNode* node = q.front();
        q.pop();

        if (node == nullptr) {
          output += "null, ";
          continue;
        }

        output += to_string(node->val) + ", ";
        q.push(node->left);
        q.push(node->right);
    }
    return "[" + output.substr(0, output.length() - 2) + "]";
}

int main() {
    string line;
    while (getline(cin, line)) {
        TreeNode* root = stringToTreeNode(line);
        getline(cin, line);
        int val = stringToInteger(line);
        
        TreeNode* ret = Solution().deleteNode(root, val);

        string out = treeNodeToString(ret);
        cout << out << endl;
    }
    return 0;
}

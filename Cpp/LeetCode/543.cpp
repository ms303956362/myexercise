#include "usual.h"
 struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int max_d, max_height;
        postOrder(root, max_height, max_d);
        return max_d;
    }

    void postOrder(TreeNode* root, int& max_height, int& max_d) {
        if (!root) {
            max_height = 0;
            max_d = 0;
            return;
        }
        int left_max_h, left_max_d, right_max_h, right_max_d;
        postOrder(root->left, left_max_h, left_max_d);
        postOrder(root->right, right_max_h, right_max_d);
        max_height = (left_max_h > right_max_h ? left_max_h : right_max_h) + 1;
        int max_d_curr = left_max_h + right_max_h;
        if (max_d_curr > left_max_d && max_d_curr > right_max_d)
            max_d = max_d_curr;
        else if (left_max_d > max_d_curr && left_max_d > right_max_d)
            max_d = left_max_d;
        else
            max_d = right_max_d;
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

int main() {
    string line;
    while (getline(cin, line)) {
        TreeNode* root = stringToTreeNode(line);
        
        int ret = Solution().diameterOfBinaryTree(root);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
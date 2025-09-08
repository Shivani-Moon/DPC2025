#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return validate(root, LONG_MIN, LONG_MAX);
    }

private:
    bool validate(TreeNode* node, long minVal, long maxVal) {
        if (!node) return true; 
        if (node->val <= minVal || node->val >= maxVal) return false;
        return validate(node->left, minVal, node->val) &&
               validate(node->right, node->val, maxVal);
    }
};

TreeNode* newNode(int val) {
    return new TreeNode(val);
}

int main() {
    TreeNode* root = newNode(2);
    root->left = newNode(1);
    root->right = newNode(3);

    Solution s;
    if (s.isValidBST(root)) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }

    return 0;
}

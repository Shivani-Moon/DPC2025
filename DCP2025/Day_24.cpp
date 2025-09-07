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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        unordered_map<TreeNode*, TreeNode*> parent;
        parent[root] = NULL;
        queue<TreeNode*> que;
        que.push(root);
        while (parent.find(p) == parent.end() || parent.find(q) == parent.end()) {
            TreeNode* node = que.front();
            que.pop();

            if (node->left) {
                parent[node->left] = node;
                que.push(node->left);
            }
            if (node->right) {
                parent[node->right] = node;
                que.push(node->right);
            }
        }
        unordered_set<TreeNode*> ancestors;
        while (p) {
            ancestors.insert(p);
            p = parent[p];
        }
        while (ancestors.find(q) == ancestors.end()) {
            q = parent[q];
        }

        return q;
    }
};

TreeNode* buildTree(vector<int> nodes) {
    if (nodes.empty() || nodes[0] == -1) return NULL;
    TreeNode* root = new TreeNode(nodes[0]);
    queue<TreeNode*> q;
    q.push(root);
    int i = 1;
    while (!q.empty() && i < nodes.size()) {
        TreeNode* current = q.front();
        q.pop();
        if (i < nodes.size() && nodes[i] != -1) {
            current->left = new TreeNode(nodes[i]);
            q.push(current->left);
        }
        i++;
        if (i < nodes.size() && nodes[i] != -1) {
            current->right = new TreeNode(nodes[i]);
            q.push(current->right);
        }
        i++;
    }
    return root;
}

TreeNode* findNode(TreeNode* root, int val) {
    if (!root) return NULL;
    if (root->val == val) return root;
    TreeNode* left = findNode(root->left, val);
    if (left) return left;
    return findNode(root->right, val);
}

int main() {
    vector<int> nodes = {3,5,1,6,2,0,8,-1,-1,7,4};
    int p_val = 5, q_val = 1;

    TreeNode* root = buildTree(nodes);

    TreeNode* p = findNode(root, p_val);
    TreeNode* q = findNode(root, q_val);

    Solution sol;
    TreeNode* lca = sol.lowestCommonAncestor(root, p, q);

    if (lca)
        cout << "Lowest Common Ancestor of " << p_val << " and " << q_val << " is: " << lca->val << endl;
    else
        cout << "No LCA found" << endl;

    return 0;
}

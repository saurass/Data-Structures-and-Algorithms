/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    TreeNode *invertTree(TreeNode *root)
    {
        queue<TreeNode *> q;
        q.push(root);

        if (root == NULL)
            return root;

        while (!q.empty())
        {
            TreeNode *tp = q.front();
            q.pop();

            TreeNode *lt = tp->left;
            TreeNode *rt = tp->right;

            tp->left = rt;
            tp->right = lt;

            if (tp->left != NULL)
                q.push(tp->left);
            if (tp->right != NULL)
                q.push(tp->right);
        }

        return root;
    }
};
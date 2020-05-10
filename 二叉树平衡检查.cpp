题目描述
实现一个函数，检查二叉树是否平衡，平衡的定义如下，对于树中的任意一个结点，其两颗子树的高度差不超过1。

给定指向树根结点的指针TreeNode* root，请返回一个bool，代表这棵树是否平衡。

/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};*/

class Balance {
public:
    bool isBalance(TreeNode* root) {
        // write code here
        if (root->right && root->left)
        {
            return isBalance(root->right) && isBalance(root->left);
        }
        if (!root->right && !root->left)
        {
            return true;
        }
        if (root->left)
        {
            if (root->left->left || root->left->right)
                return false;
            return true;
        }
        if (root->right)
        {
            if (root->right->left || root->right->right)
                return false;
            return true;
        }
    }
};

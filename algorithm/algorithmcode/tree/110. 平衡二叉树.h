#ifndef SOLUTION_H
#define SOLUTION_H
#include<iostream>

using namespace std;
 struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };


class Solution{
public:
    int f(TreeNode *root){
        if(root==nullptr)
            return -1;
        return 1+max(f(root->left),f(root->right));
    }

    bool isBalanced(TreeNode *root){
        if(root==nullptr)
            return true;
        return abs(f(root->left)-f(root->right))<2&&
        isBalanced(root->left)&&isBalanced(root->right);
    }
};
#endif 
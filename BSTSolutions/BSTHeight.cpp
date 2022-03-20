
#include "pch.h"
#include "BSTHeight.h"


/*
    Return maximum height of BST when looking at left and right
*/
int GetHeight(Node* root)
{
    // Handle base case. When reaching the max depth return -1
    if (!root)
        return -1;

    int leftHeight = GetHeight(root->_left);

    // If the tree is truly balanced then no need to check the right side (but will anyway since this method supports unbalanced trees)
    int rightHeight = GetHeight(root->_right);

    return (leftHeight > rightHeight ? leftHeight + 1 : rightHeight + 1); // +1 to handle base case (-1)
}
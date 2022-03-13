// BSTHeight.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "TreeLibrary.cpp"


using namespace std;


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


int main()
{
    int treeValues[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    int n = sizeof(treeValues) / sizeof(treeValues[0]);

    Node* root = CreateBalancedTree(treeValues, 0, n - 1);

    cout << "The maximum height of the tree is: " << GetHeight(root) << endl;
}

// GenericConsoleApp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "InOrderTraversal.h"
#include "BSTHeight.h"
#include "LowestCommonAncestor.h"


int main()
{
    // Build a balanced tree
    int treeValues[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    int n = sizeof(treeValues) / sizeof(treeValues[0]);
    Node* root = CreateBalancedTree(treeValues, 0, n - 1);

    // Find LowestCommonAncestor
    cout << "The lowest common ancestor of (1,3) is: " << GetLowestCommonAncestor(root, 1, 3) << endl;
    cout << "The lowest common ancestor of (6,8) is: " << GetLowestCommonAncestor(root, 6, 8) << endl;

    // Print In Order
    string inOrder;
    PrintInOrderTraversal(root, inOrder);
    cout << "The InOrder traversal of the tree is: " << inOrder << endl;

    // Get the Binary Search Tree Height
    cout << "The maximum height of the tree is: " << GetHeight(root) << endl;
}


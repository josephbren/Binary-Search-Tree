// GenericConsoleApp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "InOrderTraversal.h"
#include "BSTHeight.h"
#include "LowestCommonAncestor.h"
#include "LevelOrderTraversal.h"
#include "SwapNodes.h"
#include "PathsWithSpecifiedSum.h"


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

    // Level order traversal
    string levelOrder;
    LevelOrderTraversal(root, levelOrder);
    cout << "The level order traversal of the tree is: " << levelOrder << endl;

    // Swap nodes
    string nodesAfterSwap;
    SwapNodes(root, 1, nodesAfterSwap);
    cout << "The level order traversal of swapped tree is: " << nodesAfterSwap << endl;

    vector<vector<int>> paths;
    vector<int> currentPath;

    PathsWithSpecifiedSum(root, paths, currentPath, 0, 29);
    if (paths.size() == 0)
        cout << "There are no paths with the specified sum" << endl;
    else
    {
        cout << "The paths with the specified sum are:" << endl;
        for (auto path : paths)
        {
            for (auto value : path)
            {
                cout << value << " ";
            }
            cout << endl;
        }
    }
}


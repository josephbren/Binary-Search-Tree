// TreeLibrary.cpp : Defines the functions for the static library.
//

#include "pch.h"
#include "framework.h"
#include "TreeLibrary.h"

using namespace std;



Node* CreateBalancedTree(int treeValues[], int start, int end)
{
    if (start > end)
    {
        return nullptr;
    }

    int mid = (start + end) / 2;

    Node* root = new Node(treeValues[mid]);

    root->_left = CreateBalancedTree(treeValues, start, mid - 1);
    root->_right = CreateBalancedTree(treeValues, mid + 1, end);

    return root;
}

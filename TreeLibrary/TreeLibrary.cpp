// TreeLibrary.cpp : Defines the functions for the static library.
//

#include "pch.h"
#include "framework.h"

using namespace std;

struct Node
{
    Node(int data)
    {
        _data = data;
        _left = _right = nullptr;
    }

    int _data;
    Node* _left;
    Node* _right;
};


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

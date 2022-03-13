// InOrderTraversal.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

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


void PrintInOrderTraversal(Node* root)
{
    if (!root)
    {
        return;
    }

    PrintInOrderTraversal(root->_left);
    cout << root->_data << " ";
    PrintInOrderTraversal(root->_right);
}


int main()
{
    int treeValues[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    int n = sizeof(treeValues) / sizeof(treeValues[0]);

    Node* root = CreateBalancedTree(treeValues, 0, n - 1);

    PrintInOrderTraversal(root);
}

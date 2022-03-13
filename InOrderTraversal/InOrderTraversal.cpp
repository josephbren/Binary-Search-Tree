// InOrderTraversal.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "TreeLibrary.cpp"

using namespace std;


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

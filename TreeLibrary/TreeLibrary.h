#pragma once
#include <string>
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


Node* CreateBalancedTree(int treeValues[], int start, int end);
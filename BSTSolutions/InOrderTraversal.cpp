// InOrderTraversal.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include "pch.h"
#include "InOrderTraversal.h"


void PrintInOrderTraversal(Node* root, string& inOrder)
{
    if (!root)
    {
        return;
    }

    PrintInOrderTraversal(root->_left, inOrder);
    inOrder += std::to_string(root->_data) + " ";
    PrintInOrderTraversal(root->_right, inOrder);
}



#include "pch.h"
#include "VerifyBST.h"


void IsValidBST(Node* root, int& value, bool& isValidBST)
{
	if (!root || !isValidBST)
	{
		return;
	}
	
	// A valid BST is one where there is only two child nodes and the left child is less than the parent and the right child is greater than the parent
	// Verifying a valid BST can be done by doing an inorder traversal. If the nodes appear in increasing order then the tree is a valid BST
	IsValidBST(root->_left, value, isValidBST);

	if (root->_data < value)
	{
		isValidBST = false;
		return;
	}
	else
	{
		value = root->_data;
	}

	IsValidBST(root->_right, value, isValidBST);
}
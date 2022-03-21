
#include "pch.h"
#include "SwapNodes.h"


/* 
	Go level by level and swap child nodes relative to that level. Solved using recursion
*/
void SwapNodes(Node* root, int currentLevel, string& inOrder)
{
	if (!root || currentLevel < 0)
	{
		return;
	}

	if (currentLevel % 2 == 0)	// Swap every 2nd level
	{
		Node* temp = root->_left;
		root->_left = root->_right;
		root->_right = temp;
	}

	SwapNodes(root->_left, currentLevel + 1, inOrder);
	inOrder += to_string(root->_data) + " ";
	SwapNodes(root->_right, currentLevel + 1, inOrder);
}

#include "pch.h"
#include <queue>
#include "LevelOrderTraversal.h"


/*
	Level order traversal of BST using BFS
*/
void LevelOrderTraversal(Node* root, string& levelOrder)
{
	if (!root)
	{
		return;
	}

	queue<Node*> q;
	q.push(root);	// Push root node onto tree


	// Iteratively process each node, level by level
	while (!q.empty())
	{
		Node* p = q.front();

		if (p->_left)
		{
			q.push(p->_left);
		}

		if (p->_right)
		{
			q.push(p->_right);
		}

		levelOrder += to_string(p->_data) + " ";	// Record each visited node 
		q.pop();
	}
}

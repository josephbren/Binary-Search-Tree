
#include "pch.h"
#include <vector>
#include "PathsWithSpecifiedSum.h"


void PathsWithSpecifiedSum(Node* root, vector<vector<int>>& paths, vector<int>& currentPath, int currentSum, int desiredSum)
{
	if (!root)
	{
		return;
	}

	// Build the current path and track the current sum
	currentPath.emplace_back(root->_data);
	currentSum += root->_data;

	// If we're at a leaf node and the current sum equals the desired sum, include that path
	if (!root->_left && !root->_right && currentSum == desiredSum)
	{
		paths.emplace_back(currentPath);
	}
	else
	{
		PathsWithSpecifiedSum(root->_left, paths, currentPath, currentSum, desiredSum);
		PathsWithSpecifiedSum(root->_right, paths, currentPath, currentSum, desiredSum);
	}

	// As we backtrack we pop the last value and reduce the current sum to exclude the previous value
	currentSum -= root->_data;
	currentPath.pop_back();
}
// LowestCommonAncestor.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include "TreeLibrary.cpp"


using namespace std;


void GetLCAPath(Node* root, int value1, vector<int>& values1, bool& value1Found, int value2, vector<int>& values2, bool& value2Found)
{
    // Handle base case. Return as soon as both are found
    if (!root || (value1Found && value2Found))
    {
        return;
    }

    if (!value1Found)
        values1.emplace_back(root->_data);

    if (!value2Found)
        values2.emplace_back(root->_data);

    if (value1 == root->_data)
    {
        value1Found = true;
    }

    if (value2 == root->_data)
    {
        value2Found = true;
    }

    if (!value1Found || !value2Found)
    {
        GetLCAPath(root->_left, value1, values1, value1Found, value2, values2, value2Found);
    }

    if (!value1Found || !value2Found)
    {
        GetLCAPath(root->_right, value1, values1, value1Found, value2, values2, value2Found);
    }

    // Searched both left and right and didn't find value1, value2 or both so pop the last item in vector(s)
    if (!value1Found)
        values1.pop_back();

    if (!value2Found)
        values2.pop_back();
}


int GetLowestCommonAncestor(Node* root, int value1, int value2)
{
    // Handle base case
    if (!root)
        return -1;

    bool value1Found = false;
    bool value2Found = false;

    vector<int> values1;
    vector<int> values2;

    // No point in DFS'ing for each value, continue the same DFS until both values found (if possible)
    GetLCAPath(root, value1, values1, value1Found, value2, values2, value2Found);

    // Make sure both values found
    if (value1Found && value2Found)
    {
        // Both found, interate the vector until the node values differ and then take the parent
        for (auto i = 1; i < values1.size() && i < values2.size(); i++)
        {
            if (values1[i] != values2[i])
            {
                return values1[i - 1];
            }
        }
    }

    return -1;
}


int main()
{
    int treeValues[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    int n = sizeof(treeValues) / sizeof(treeValues[0]);

    Node* root = CreateBalancedTree(treeValues, 0, n - 1);

    cout << "The lowest common ancestor of (1,3) is: " << GetLowestCommonAncestor(root, 1, 3) << endl;
    cout << "The lowest common ancestor of (6,8) is: " << GetLowestCommonAncestor(root, 6, 8) << endl;
}


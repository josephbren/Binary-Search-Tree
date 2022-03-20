#pragma once
#include <vector>
#include "TreeLibrary.h"

using namespace std;


void GetLCAPath(Node* root, int value1, vector<int>& values1, bool& value1Found, int value2, vector<int>& values2, bool& value2Found);
int GetLowestCommonAncestor(Node* root, int value1, int value2);
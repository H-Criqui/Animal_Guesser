#pragma once
#include <string>
#include <fstream>
#include <sstream>
#include "TreeNode.h"

using namespace std;

string remove_star(string& str)
{
	string str1 = str;
	str1.erase(0,1);
	return str1;
}

Node* Constructor(vector<string> file, int i, Node* x)
{
	if (i < file.size())
	{
		if (file[i] == "")
		{
			return x;
		}
		else if (i % 2 == 1)
		{
			Node* temp = new Node;
			temp->value = file[i];
			x->left = temp;

			Constructor(file, (2 * i + 1), temp);
			Constructor(file, (2 * i + 2), temp);

			return x;
		}
		else if (i % 2 == 0)
		{
			Node* temp = new Node;
			temp->value = file[i];
			x->right = temp;

			Constructor(file, (2 * i + 1), temp);
			Constructor(file, (2 * i + 2), temp);

			return x;
		}
	}
	return x;
	
}
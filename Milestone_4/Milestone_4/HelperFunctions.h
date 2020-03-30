#pragma once
#include <vector>
#include <string>
#include <iostream>
#include "TreeNode.h"

using namespace std;

void allocate(vector<string> vect, int i)
{
	while (i > vect.size())
	{
		vect.push_back("");
	}
}

void set_(string answer, Node* x)
{
	Node* temp = new Node;
	temp->value = x->value;
	x->left = temp;
	Node* AnswerNode = new Node;
	AnswerNode->value = "Is it a " + answer + "?";
	x->right = AnswerNode;
	cout << "What is a yes/no question where " + answer + " is the answer to yes." << endl;
	string newQuestion;
	getline(cin, newQuestion);
	x->value = newQuestion;
}

void run(Node* x, bool &guessed ) 
{
	cout << x->value << endl;
	string answer;
	getline(cin, answer);
	if (x->right != nullptr || x->left != nullptr)
	{
		if (answer == "yes")
		{
			run(x->right, guessed);
		}
		else
		{
			run(x->left, guessed);
		}
	}
	else
	{
		if (answer == "yes")
		{
			cout << "yay, I did it!!!" << endl;
			guessed = true;
		}
		else
		{
			cout << "What animal were you thinking of?" << endl;
			string animal;
			getline(cin, animal);
			set_(animal, x);
			
		}
	}
}

int maxSize(int depth)
{
	int n = 0;
	int counter = 0;
	while (counter < depth)
	{
		n += (counter + 1);
		counter++;
	}
	return n;
}

int maxDepth(Node* top) 
{
	if (top == NULL)
	{
		return 0;
	}
	else
	{
		/* compute the depth of each subtree */
		int lDepth = maxDepth(top->left);
		int rDepth = maxDepth(top->right);

		/* use the larger one */
		if (lDepth > rDepth)
		{
			return(lDepth + 1);
		}
		else
		{
			return(rDepth + 1);
		}
	}
}

void allocate(vector<string>& vect, int size)
{
	while (vect.size() < size)
	{
		vect.push_back("");
	}
}

void Deconstructor(Node* start, int i, vector<string>& result)
{
	if (result.size() > i)
	{
		if (start == NULL)
		{
			result[i] = "";

		}
		else
		{
			result[i] = start->value;
			Deconstructor(start->left, (2 * i + 1), result);
			Deconstructor(start->right, (2 * i + 2), result);
		}
	}
}
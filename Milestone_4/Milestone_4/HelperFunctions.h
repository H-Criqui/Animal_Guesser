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
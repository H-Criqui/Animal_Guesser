#include <cstdlib>
#include <string>
#include <sstream>
#include <fstream>
#include <iostream>
#include <vector>
#include <cmath>
#include "HeapConstructor.h"
#include "HelperFunctions.h"
using namespace std;







int main()
{
	ifstream fin;
	fin.open("heap1.txt");
	string temp;
	vector<string> construct;
	while (fin.good())
	{
		getline(fin, temp);
		construct.push_back(temp);
	}

	
	Node* StartNode = new Node;
	Constructor(construct, 0, StartNode);

	Node* start = StartNode->right;
	bool guessed = false;
	while (!guessed)
	{
		cout << "Think of an animal." << endl;
		run(start, guessed);
	}

	fin.close();
	ofstream fout;
	fout.open("heap1.txt");
	int counter = 0;
	int size = pow(2, maxDepth(start));
	vector<string> result{};
	result.resize(size);
	Deconstructor(StartNode->right, 0, result);
	while (counter < result.size())
	{
		fout << result[counter] << endl;
		counter++;
	}

	return 0;
}
/* 
Title: Project 2: Simplified Pagerank Algorithm
Author: Edward Zhang
Date: 11/15/2020
Purpose: Create a simplified pagerank algorithm using an adjacency list
*/

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <sstream>

using namespace std;

class AdjacencyList 
{
private:
	map<string, vector<string>> adjList;

public:
	AdjacencyList() {}
	void insert(string f, string t) 
	{
		adjList[f].push_back(t);
		if (adjList.find(t) == adjList.end())
			adjList[t] = {};
	}

	void print()
	{
		for (auto iter = adjList.begin(); iter != adjList.end(); iter++) {
			auto key = iter->second;
			cout << iter->first << " |";
			for (int i = 0; i < key.size(); i++){
				cout << " " << key[i];
			}
			cout << endl;
		}
	}

};

int main() 
{
	AdjacencyList pages;

	int numLines, powIter;
	string from, to;
	cin >> numLines;
	cin >> powIter;

	for (int i = 0; i < numLines; i++) {
		cin >> from;
		cin >> to;
		pages.insert(from, to);
	}


	return 0;
}
/* 
Title: Project 2: Simplified Pagerank Algorithm
Author: Edward Zhang
Date: 11/15/2020
Purpose: Create a simplified pagerank algorithm using an adjacency list
*/

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <sstream>

using namespace std;

class AdjacencyList 
{
private:
	// string: From
	// Double: Rank
	// Vector<String> : Websites pointed to
	map<string, pair<double,vector<string>>> outNodes;

	// string: To
	// Vector<String> : Websites pointed From
	map<string, vector<string>> inNodes;

public:
	AdjacencyList() {}

	void insert(string f, string t) 
	{
		outNodes[f].second.push_back(t);
		if (outNodes.find(t) == outNodes.end())
			outNodes[t] = {};
		inNodes[t].push_back(f);
		if (inNodes.find(f) == inNodes.end())
			inNodes[f] = {};
	}

	void powerIter(int p)
	{
		// Initialize rank of pages
		for (auto iter = outNodes.begin(); iter != outNodes.end(); iter++) {
			iter->second.first = 1.00 / outNodes.size();
		}

		// Iterates based on the number of desired power iterations
		for (int i = 1; i < p; i++) {
			unordered_map<string, double> temp;
			for (auto iter = outNodes.begin(); iter != outNodes.end(); iter++) {
				string curr = iter->first;
				auto in = inNodes[curr];
				double sum = 0;
				for (int c = 0; c < in.size() ; c++) {
					sum += outNodes[in[c]].first * (1.00/outNodes[in[c]].second.size());
				}
				temp[curr] = sum;
			}
			for (auto iter = temp.begin(); iter != temp.end(); iter++) {
				outNodes[iter->first].first = iter->second;
			}
		}


	}
	
	void print()
	{
		for (auto iter = outNodes.begin(); iter != outNodes.end(); iter++) {
			//printf("%s %0.2f \n", iter->first, iter->second.first);
			cout << setprecision(2) << fixed;
			cout <<iter->first<<" "<<iter->second.first<< endl;
		}
	}

	// Testing method used to print maps
	void printMap()
	{
		for (auto iter = outNodes.begin(); iter != outNodes.end(); iter++) {
			auto key = iter->second.second;
			cout << iter->first << " |";
			for (int i = 0; i < key.size(); i++){
				cout << " " << key[i];
			}
			cout << endl;
		}
		cout << endl;
		for (auto iter = inNodes.begin(); iter != inNodes.end(); iter++) {
			auto key = iter->second;
			cout << iter->first << " |";
			for (int i = 0; i < key.size(); i++) {
				cout << " " << key[i];
			}
			cout << endl;
		}
	}

};

int main() 
{
	AdjacencyList pages;
	// Psuedocode from project documentation
	int numLines, pow_Iter;
	string from, to;
	cin >> numLines;
	cin >> pow_Iter;

	for (int i = 0; i < numLines; i++) {
		cin >> from;
		cin >> to;
		pages.insert(from, to);
	}
	pages.powerIter(pow_Iter);
	
	pages.print();

	return 0;
}
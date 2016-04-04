// IslandCounter.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <ctime>
#include <type_traits>
#include <vector>
#include "IslandGenerator.h"
#include <iostream>

using namespace std;

void DisplayMap(vector<vector<int>>& map)
{
	for (auto j = 0; j < map.size(); j++)
	{
		for (auto i = 0; i < map[j].size(); i++)
		{
			cout << map[j][i] << " ";
		}

		cout << "\n";
	}
}

int main()
{
	srand(time(nullptr));

	auto gen = IslandGenerator();

	auto map = vector<vector<int>>(30);
	for (auto i = 0; i < map.size(); i++)
	{
		map[i] = vector<int>(map.size());
	}

	gen.Generate(map);

	DisplayMap(map);

	cin.get();
}

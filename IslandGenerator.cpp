#include "stdafx.h"
#include "IslandGenerator.h"

using namespace std;

IslandGenerator::IslandGenerator()
{
}

IslandGenerator::~IslandGenerator()
{
}

void IslandGenerator::Generate(vector<vector<int>>& map)
{
	for (auto j = 0; j < map.size(); j++)
	{
		for (auto i = 0; i < map[j].size(); i++)
		{
			map[j][i] = rand() % 2;
		}
	}
}